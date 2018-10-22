#include<stdio.h>
#include<stdlib.h>
long long int flag[100009],size;

	long long int n,m,i,x,y;
	long long int ans=1;

typedef struct node
{
	long long int value;
	struct node * next;
}Node;

typedef struct list
{
	Node * head;
	long long int valid;
	long long int color;
}List;

int bfs(long long int i);

Node * start=NULL;
Node * end = NULL;

void enqueue(long long int val)
{
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->value = val;
	temp->next = NULL;
  if(start== end && start==NULL)
  {
     start = temp;
	 end = temp;
	 return;
  }
 
  end->next = temp;
  end = temp;

return;
}

long long int dequeue()
{
   if(start == end && start==NULL)
	   return 0;

   if(start == end)
      {
          long long int frus = start->value;
		  Node * tp = start;
		  free(tp);
		  start = NULL;
		 end = NULL;
		 return frus;
	  }
  long long int frus = start->value;
		  Node * tp = start;
  start = start->next;
  free(tp);
  return frus;

}

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

void printqueue()
{
		Node * temp = start;
		while(temp!=NULL)
		{	
			printf("%lld ",temp->value);
		    temp=temp->next;
		}
		printf("\n");
	
	return ;
}


void initialise()
{
	for(i=0;i<=n;i++)
	{
		graph[i].head=NULL;
		graph[i].valid=0;
		graph[i].color=0;
	}
}

void makeAdjacencyList()
{
	while(m--)
	{
		scanf("%lld%lld",&x,&y);
			if(x!=y)
			{
				graph[x].head = insert(graph[x].head,y);
				graph[y].head = insert(graph[y].head,x);
			}
	}
}

int main()
{
	size=0;

	for(i=0;i<=n;i++)
		flag[i]=0;
	initialise();
	scanf("%lld%lld",&n,&m);
	 makeAdjacencyList();
//	print();
//  printqueue();
	int temp;
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			temp = bfs(i);
			if(temp==0)
			{
				ans=0;
				break;
			}
		}
	}

	if(ans==1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}

int bfs(long long int i)
{
	int top;
  flag[i]=-1;
  enqueue(i);
  size++;
 // printf("size = %lld it should be 1",size);
  while(size!=0 && size>0)
  {
     top=dequeue();
	 size--;
     Node* temp = graph[top].head;

     while(temp!=NULL)
	 {
		 if(flag[temp->value]==0)
                  {
					  flag[temp->value]=-flag[top];
					  enqueue(temp->value);
					  size++;
				  }
		 else if(flag[temp->value]==flag[top])
			 return 0;

        temp = temp->next;
	 }
	   

  }

return 1;
}


