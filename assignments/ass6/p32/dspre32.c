#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define mod 1000000007
#define arrsize 500009
typedef long long int lint;
typedef struct node
{
	lint value,wt;
	struct node * next;
}Node;

lint srcdij[arrsize],desdij[arrsize];
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
	lint u;
	lint v;
	lint w;
}Graph;
lint size;
Graph input[arrsize];

typedef struct heap
{
	lint vert;	
	lint dist;	
}Heap;
Heap heap[arrsize];

lint ans[arrsize];
lint pos[arrsize];
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

lint p1[arrsize],p2[arrsize];
List tree[arrsize];

void heapinsert(Heap heap[arrsize],lint max,lint z,lint vert)
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

lint heapify(Heap heap[arrsize], lint n, lint i)
{
	lint small=i;
	lint right=(i<<1) + 2;
	lint left=(i<<1) + 1;
	if (heap[right].dist<heap[small].dist)
	{
		if(right<n)
		{
			small=right;
		}
	}
	if (heap[left].dist<heap[small].dist)
	{
		if(left<n)
		{
			small=left;
		}
	}
	if(small!=i) 
	{
		Heap tp1,tp2;
		pos[heap[i].vert]=small;
		pos[heap[small].vert]=i;
		tp1=heap[i];
		tp2=heap[small];
		heap[i]=tp2;
		heap[small]=tp1;
		heapify(heap,n,small);
	}
	return 0;
}

lint calc(lint i,lint v,lint dist)
{
	i=pos[v];
	heap[i].dist=dist;
	return i;
}

void decreaseKey(Heap heap[arrsize], lint v, lint dist)
{
	lint i;
	i = calc(i,v,dist);
	while (i && heap[(i-1)/2].dist>heap[i].dist)
	{
		Heap tp1;
		pos[heap[i].vert] = (i-1)/2;
		Heap tp2;
		pos[heap[(i-1)/2].vert] = i;
		tp1=heap[i];
		tp2=heap[(i-1)/2];
		heap[i]=tp2;
		heap[(i-1)/2]=tp1;
		i=(i-1)/2;
	}
}

void initialize()
{
	lint i=0;
	while(i<=n)
	{
		tree[i].head = NULL;
		i++;
	}
	return;
}
int isInMinHeap( lint v)
{
	if (pos[v]<size)
		return 1;
	else
		return 0;
}



void dijkstra(lint src,lint arr[arrsize],lint p[])
{
	lint i=0;
	size = 0;
	while(i<n)
	{
		arr[i] = INT_MAX;
		heapinsert(heap,size,arr[i],i);
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
	p1[s-1]=1;
	p2[t-1]=1;
	size = n;
	while (size>0)
	{
		lint u;
		Heap use=heap[0];
		size--;
		heap[0] = heap[size];
		pos[heap[size].vert]=0;
		pos[use.vert]=size;
		heapify(heap,size,0);
		u = use.vert; 
		Node * temp = tree[u].head;
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
	t1+=srcdij[input[i].v-1];
	t1+=input[i].w;
	t1+=desdij[input[i].u-1];
	if(srcdij[t-1]== t1)
		return 1;
	return 0;
}
int cond2(lint i)
{
	lint t1=0;
	t1+=srcdij[input[i].u-1];
	t1+=input[i].w;
	t1+=desdij[input[i].v-1];
	if(srcdij[t-1]== t1)
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
			tree[input[i-1].v-1].head = insert(tree[input[i-1].v-1].head,input[i-1].u-1,input[i-1].w);   
			tree[input[i-1].u-1].head = insert(tree[input[i-1].u-1].head,input[i-1].v-1,input[i-1].w);   
		}
		dijkstra(t-1,desdij,p2);
		dijkstra(s-1,srcdij,p1);
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
				sum=(p1[input[i].v-1]*p2[input[i].u-1])%mod;
				ans[i]=(ans[i]+sum)%mod;
			}
			if(cond2(i)==1)
			{
				sum=(p1[input[i].u-1]*p2[input[i].v-1])%mod;
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
