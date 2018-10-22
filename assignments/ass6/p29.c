#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

long long int ans = 0;
long long int n,i,j,u,v,flag[100009],check;

typedef struct edges
{
	long long int w,ind;
}Edge;

typedef struct node
{
	long long int value;
	struct node * next;
}Node;

typedef struct list
{
	Node * head;
	long long int save;
}List;

typedef struct tree
{
	long long int pres,notpres;
}Tree;
Tree a[100009];

int dfs(long long int src,long long int par,Tree a[]);
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

int compare(const void* a,const void * b)
{
	Edge *studentA=(Edge *)a;
	Edge *studentB=(Edge *)b;
	return(studentB->w-studentA->w);
}
Edge s[100009];
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
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&s[i].w);
		s[i].ind = i;
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&u,&v);
		graph[u].head = insert(graph[u].head,v);
		graph[v].head = insert(graph[v].head,u);
	}
	dfs(1,0,a);
	ans = a[1].pres>a[1].notpres?a[1].pres:a[1].notpres;
	printf("%lld\n",ans);
	return 0;

}
long long int re;

void update(long long int src,long long int p,long long int q)
{
	a[src].pres = s[src].w+p;
	a[src].notpres = q;
	return;
}


int dfs(long long int src,long long int par,Tree a[])
{
	Node * temp = graph[src].head;
	long long int p=0,q=0;	
	while(temp!=NULL)
	{
		if(temp->value!=par) 
		{
			long long int var = temp->value;
			dfs(var,src,a);
		   re = a[var].pres>a[var].notpres?a[var].pres:a[var].notpres;
			
		    q+=re;
			p+=a[var].notpres;
		}
		temp = temp->next;
	}
	update(src,p,q);
	return 0;
}


