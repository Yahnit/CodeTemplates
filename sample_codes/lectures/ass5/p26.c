#include<stdio.h>
#include<stdlib.h>
long long int flag[100009],size,heap[100009],ans[100009];
long long int n,m,i,x,y;

typedef struct node
{
	long long int value;
	struct node * next;
}Node;

typedef struct list
{
	Node * head;
}List;

Node* insert(Node * head,long long val)
{
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->value = val;
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

List graph[100009];

void hinsert(long long int heap[100009],long long int max,long long int z)
{
	while (max>=1)
	{
		long long int parent=(max-1)>>1;
		if (z<=heap[parent])
		{
			heap[max]= z;
			return;
		}
		heap[max] = heap[parent];
		max= parent;
	}
	heap[0]=z;
}

long long int max_heap(long long int heap[100009], long long int n, long long int i)
{
	long long int big=i,left=2*i+1,right=2*i+2,tp;
	if (right<n && heap[right] > heap[big])
		big=right;
	if (left<n && heap[left]> heap[big])
		big=left;
	tp=heap[i];
	heap[i]=heap[big];
	heap[big]=tp;
	if(big!=i) max_heap(heap,n,big);
	return 0;
}



void print()
{
	for(i=1;i<=n;i++)
	{
		printf("%lld => ",i);
		Node * temp = graph[i].head;
		while(temp!=NULL)
		{	
			printf("%lld ",temp->value);
			temp=temp->next;
		}
		printf("\n");
	}
	return ;
}

void initialise()
{
	for(i=0;i<=n;i++)
	{
		graph[i].head=NULL;
		flag[i]=0;
	}
}

void makeAdjacencyList()
{
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
		if(x!=y)
			graph[y].head = insert(graph[y].head,x);
		    flag[x]++;
	}
}

int main()
{
	size=0;
	long long int t,i;
	scanf("%lld",&t);
	while(t--)
	{
		long long int size = 0;
		scanf("%lld%lld",&n,&m);
		initialise();
		makeAdjacencyList();
		for(i=1;i<=n;i++)
		{
           if(flag[i]==0)
		   {
			   hinsert(heap,size,i);
			   size++;
		   }
		}
		long long int ind = 0;
       while(size>0)
	   { 
         ans[ind++]=heap[0];  
         heap[0] = heap[size-1];
		 size--;
         max_heap(heap,size,0); 
         Node * temp = graph[ans[ind-1]].head;
		 while(temp!=NULL)
		 {
             flag[temp->value]--;
			 if(flag[temp->value]==0)
			 {
				 hinsert(heap,size,temp->value);
				 size++;
			 }
			 temp = temp->next;
		 }

	   }
       for(i=ind-1;i>=0;i--)
	   {
		   printf("%lld ",ans[i]);
	   }

		//print();
		printf("\n");
	}
	return 0;
}



