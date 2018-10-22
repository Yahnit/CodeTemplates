#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define mod 1000000007
typedef long long int lint;
typedef struct node
{
	lint value,wt;
	struct node * next;
}Node;
#define ar 500000
lint sourcedij[ar],destdij[ar];
typedef struct list
{
	Node * head;
}List;
lint n;
lint m;
lint s;
lint t;
typedef struct input
{
	lint u,v,w;
}Graph;
lint ans[ar];
lint forpath[ar],backpath[ar];
lint size;
Graph input[ar];

typedef struct heap
{
	lint dist,vert;	
}Heap;
Heap heap[ar];

lint pos[ar];
Node* insert(Node * head,lint val,lint w)
{
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->wt = w,temp->value=val;
	if(head==NULL)
	{
		head=temp,head->next=NULL;
		return head;
	}
	temp->next=head,head=temp;  
	return head;
}

List diag[ar];

void hinsert(Heap heap[ar],lint max,lint z,lint vert)
{
	while (max>=1)
	{
		lint temp;
		temp=(max-1)/2;
		lint parent=temp;
		if (z>=heap[parent].dist)
		{
			heap[max].vert= vert,heap[max].dist=z;
			return;
		}
		heap[max]=heap[parent];
		max= parent;
	}
	heap[0].vert=vert,heap[0].dist=z;
}

lint min_heap(Heap heap[ar], lint n, lint i)
{
	lint small=i;
	lint right=i<<1 + 2;
	lint left=i<<1 + 1;
	if (heap[left].dist<heap[small].dist)
	{
		if(left<n)
		{
			small=left;
		}
	}
	if (heap[right].dist<heap[small].dist)
	{
		if(right<n)
		{
			small=right;
		}
	}
	if(small!=i) 
	{
		Heap tforpath,tbackpath;
		pos[heap[i].vert]=small;
		pos[heap[small].vert]=i;
		tforpath=heap[i];
		tbackpath=heap[small];
		heap[i]=tbackpath;
		heap[small]=tforpath;
		min_heap(heap,n,small);
	}
	return 0;
}

void decreaseKey(Heap heap[ar], lint v, lint dist)
{
	lint i;
	i=pos[v];
	heap[i].dist=dist;
	while (heap[i].dist<heap[(i-1)/2].dist && i)
	{
		Heap tforpath;
		pos[heap[i].vert] = (i-1)/2;
		Heap tbackpath;
		pos[heap[(i-1)/2].vert] = i;
		tforpath=heap[i];
		tbackpath=heap[(i-1)/2];
		heap[i]=tbackpath;
		heap[(i-1)/2]=tforpath;
		i=(i-1)/2;
	}
}

void initialize()
{
	lint i=0;
	while(i<=n)
	{
		diag[i].head = NULL;
		i++;
	}
	return;
}

int isInMinHeap( lint v)
{
	if (pos[v]>size)
		return 0;
	else
		return 1;
}
void dijkstra(lint src,lint arr[ar],lint p[])
{
	lint i=0;
	size = 0;
	while(i<n)
	{
		arr[i] = INT_MAX;
		hinsert(heap,size,arr[i],i);
		p[i]=0;
		pos[i]=i;
		i++;
		size++;
	}
	heap[src].vert = src;
	heap[src].dist = arr[src];
	arr[src] = 0;
	pos[src]=src;
	decreaseKey(heap, src, arr[src]);
	forpath[s-1]=1;
	backpath[t-1]=1;
	size = n;
	while (size>0)
	{
		lint u;
		Heap use=heap[0];
		size--;
		heap[0] = heap[size];
		pos[heap[size].vert]=0;
		pos[use.vert]=size;
		min_heap(heap,size,0);
		u = use.vert; 
		Node * temp = diag[u].head;
		while (temp!=NULL)
		{
			lint v;
			v = temp->value;
			lint t;
			t=temp->wt;
			if(t+arr[u] < arr[v])
			{
				if(arr[u]!=INT_MAX)
				{
					if (isInMinHeap(v)==1)
					{
						p[v] = p[u];
						arr[v]=arr[u]+t;
						decreaseKey(heap, v, arr[v]);
					}
				}
			}
			else if (t+arr[u]>arr[v])
			{
				if(arr[u]!=INT_MAX)
				{
					if (isInMinHeap(v)==1)
					{
						p[u] = p[v];
					}
				}
			}
			else if (t+arr[u]==arr[v])
			{
				if(arr[u]!=INT_MAX)
				{
					if (isInMinHeap(v)==1)
					{
						p[v] = (p[v]+p[u])%mod;
					}
				}
			}
			temp=temp->next;
		}
	}
}

int cond1(lint i)
{
	lint t1=0;
	t1+=sourcedij[input[i].v-1];
	t1+=input[i].w;
	t1+=destdij[input[i].u-1];
		if(sourcedij[t-1]== t1)
				return 1;
	return 0;
}
int cond2(lint i)
{
	lint t1=0;
	t1+=sourcedij[input[i].u-1];
	t1+=input[i].w;
	t1+=destdij[input[i].v-1];
		if(sourcedij[t-1]== t1)
				return 1;
	return 0;
}
int main()
{
	lint test;
	scanf("%lld",&test);
	lint j;
	while(j<test)
	{
		lint i;
		scanf("%lld",&n);
		scanf("%lld",&m);
		scanf("%lld",&s);
		scanf("%lld",&t);
		initialize();
		i=0;
		while(i<m)
		{
			scanf("%lld",&input[i].u);
			scanf("%lld",&input[i].v);
			scanf("%lld",&input[i].w);
			i++;
			diag[input[i-1].v-1].head = insert(diag[input[i-1].v-1].head,input[i-1].u-1,input[i-1].w);   
			diag[input[i-1].u-1].head = insert(diag[input[i-1].u-1].head,input[i-1].v-1,input[i-1].w);   
		}
		dijkstra(t-1,destdij,backpath);
		dijkstra(s-1,sourcedij,forpath);
		i=0;
		while(i<m)
		{
			ans[i]=0;
			i++;
		}
		i=0;
		lint sum;
		while(i<m)
		{ 
			lint tem;	
			if(cond1(i)==1)
			{
					sum=(forpath[input[i].v-1]*backpath[input[i].u-1])%mod;
					ans[i]=(ans[i]+sum)%mod;
			}
			if(cond2(i)==1)
			{
				sum=(forpath[input[i].u-1]*backpath[input[i].v-1])%mod;
				ans[i]=(ans[i]+sum)%mod;
			}
			i++;
		}
		i=0;
		while(i<m)
		{
			printf("%lld ",ans[i]);
			i++;
		}
		printf("\n");
		j++;
	}
	return 0;
}
