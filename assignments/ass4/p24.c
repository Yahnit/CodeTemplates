#include<stdio.h>
#include<stdlib.h>

long long int n,a[1000009],u,v,flag[1000009],i;

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
List graph[1000009];


typedef struct tree
{
	long long int val,child,shops;
}Tree;
Tree city[1000009];

int dfs(long long int i);
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

int main()
{
	for(i=0;i<=n;i++)
		flag[i]=0;


	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);

	for(i=0;i<=n;i++)
	{
		graph[i].head=NULL;
		graph[i].valid=0;
		graph[i].color=0;
	}

	for(i=0;i<n-1;i++)
	{
		scanf("%lld %lld",&u,&v);
		graph[u].head = insert(graph[u].head,v);
		graph[v].head = insert(graph[v].head,u);
	}
//	print();

	for(i=1;i<=n;i++)
	{
		city[i].val = a[i];
	}

	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			dfs(i);
		}
	}

     long long int sum=0;
	for(i=2;i<=n;i++)
	{ 
       sum+= (city[i].child*city[i].shops) + (city[1].child-city[i].child)*(city[1].shops-city[i].shops);

	}
   printf("%lld\n",sum);
	return 0;
}

int dfs(long long int i)
{
	flag[i]=1;

	Node * temp = graph[i].head;
	while(temp!=NULL)
	{
		if(flag[temp->value]==0)
		{
			dfs(temp->value);
			city[i].child += city[temp->value].child;
			city[i].shops += city[temp->value].shops;
		}

		temp = temp->next;
	}

		city[i].child+=1;
		city[i].shops+=a[i];
	return 0;
}




