#include<stdio.h>

#include<stdlib.h>
#include<limits.h>

long long int n,m,s,t,size,arr1[300009],arr2[300009],ans[300009],p1[300009],p2[300009];
long long int mod = 1000000007;
typedef struct node
{
	long long int value,wt;
	struct node * next;
}Node;

typedef struct list
{
	Node * head;
}List;

typedef struct graph
{
	long long int u,v,w;
}Graph;

Graph graph[300009];

typedef struct heap
{
	long long int dist,vert;	
}Heap;
Heap heap[300009];

long long int pos[300009];
Node* insert(Node * head,long long int val,long long int w)
{
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->value = val;
	temp->wt = w;
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
		return head;
	}
	temp->next=head;
	head=temp;  
	return head;
}

List diag[300009];

void print()
{
	long long int i;
	for(i=1;i<=n;i++)
	{
		printf("%lld => ",i);
		Node * temp = diag[i].head;
		while(temp!=NULL)
		{	
			printf("%lld ",temp->value);
			temp=temp->next;
		}
		printf("\n");
	}
	printf("\n");
	return ;
}

void hinsert(Heap heap[300009],long long int max,long long int z,long long int vert)
{
	while (max>=1)
	{
		long long int parent=(max-1)>>1;
		if (z>=heap[parent].dist)
		{
			heap[max].dist= z;
			heap[max].vert= vert;
			return;
		}
		heap[max].dist = heap[parent].dist;
		heap[max].vert = heap[parent].vert;
		max= parent;
	}
	heap[0].dist=z;
	heap[0].vert=vert;
}

long long int min_heap(Heap heap[300009], long long int n, long long int i)
{
	long long int small=i,left=2*i+1,right=2*i+2;
	if (right<n && heap[right].dist<heap[small].dist)
		small=right;
	if (left<n && heap[left].dist<heap[small].dist)
		small=left;
	if(small!=i) 
	{
        pos[heap[small].vert]=i;
        pos[heap[i].vert]=small;

		Heap tp;
		tp=heap[i];
		heap[i]=heap[small];
		heap[small]=tp;
		min_heap(heap,n,small);
	}
	return 0;
}

void decreaseKey(Heap heap[300009], long long int v, long long int dist)
{
	long long int i=pos[v];
	heap[i].dist=dist;

	while (i && heap[i].dist<heap[(i-1)>>1].dist)
	{
		pos[heap[i].vert] = (i-1)/2;
		pos[heap[(i-1)/2].vert] = i;

		Heap temp;
		temp = heap[i];
		heap[i] = heap[(i-1)>>1];
		heap[(i-1)>>1] = temp;
		i=(i-1)>>1;
	}
}

void initialize()
{
	long long int i;
	for(i=0;i<=n;i++)
		diag[i].head = NULL;
	return;
}

int isInMinHeap( long long int v)
{
	if (pos[v]<size)
		return 1;
	return 0;
}

void printArr(long long int dist[], long long int n)
{
	long long int i;
	printf("Vertex   Distance from Source\n");
	for (i=0;i<n;++i)
		printf("%lld \t\t %lld\n", i, dist[i]);
}

void dijkstra(long long int src,long long int arr[300009],long long int p[])
{
	long long int i;
	size = 0;
	for (i=0;i<n;i++)
	{
		arr[i] = INT_MAX;
		hinsert(heap,size,arr[i],i);
		size++;
		pos[i]=i;
		p[i]=0;
	}
	heap[src].dist = arr[src];
	heap[src].vert = src;
	pos[src]=src;
	arr[src] = 0;
	decreaseKey(heap, src, arr[src]);

	size = n;
    p1[s-1]=1;
	p2[t-1]=1;
	while (size>0)
	{
		Heap use;
		use = heap[0];
		heap[0] = heap[size-1];
		pos[heap[size-1].vert]=0;
		pos[use.vert]=size-1;
		size--;
		min_heap(heap,size,0);
		long long int u = use.vert; 

		Node * temp = diag[u].head;
		while (temp!=NULL)
		{
			long long int v = temp->value;
			if (isInMinHeap(v)==1 && arr[u]!=INT_MAX && 
					temp->wt+arr[u]<arr[v])
			{
				p[v] = p[u];
				arr[v]=arr[u]+temp->wt;
				decreaseKey(heap, v, arr[v]);
			}
			else if (isInMinHeap(v)==1 && arr[u]!=INT_MAX && temp->wt+arr[u]>arr[v])
				p[u] = p[v];
         
			else if (isInMinHeap(v)==1 && arr[u]!=INT_MAX && temp->wt+arr[u]==arr[v])
				p[v] = (p[v]+p[u])%mod;
			temp=temp->next;
		}
	}
//	printArr(arr, n);
}

int main()
{
	long long int test,i,j;
	scanf("%lld",&test);

	for(j=0;j<test;j++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
		initialize();
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld%lld",&graph[i].u,&graph[i].v,&graph[i].w);
			diag[graph[i].u-1].head = insert(diag[graph[i].u-1].head,graph[i].v-1,graph[i].w);   
			diag[graph[i].v-1].head = insert(diag[graph[i].v-1].head,graph[i].u-1,graph[i].w);   

		}
		//		print();
		dijkstra(s-1,arr1,p1);
		dijkstra(t-1,arr2,p2);
        for(i=0;i<m;i++)
		{ 
			ans[i]=0;
             if(arr1[t-1]== arr1[graph[i].u-1] + graph[i].w + arr2[graph[i].v-1])
			 {
				 ans[i] = (ans[i]+(p1[graph[i].u-1]*p2[graph[i].v-1])%mod)%mod;
			 }
					 
			if(arr1[t-1]== arr1[graph[i].v-1] + graph[i].w + arr2[graph[i].u-1])
			 {
				 ans[i]= (ans[i]+(p1[graph[i].v-1]*p2[graph[i].u-1])%mod)%mod;
			 }
		}
    for(i=0;i<m;i++)
		printf("%lld ",ans[i]);
	printf("\n");

	}
	return 0;
}
