#include<stdio.h>
#include<stdlib.h>

long long int n,m,M,u,v,i,j,calc,ans;
long long int flag[100009],stack[100009],size,prod,ind,a,b;

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
List reverse[100009];
void print()
{
	printf("\n");
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
long long int res;
void initialize()
{
	for(i=1;i<=n;i++)
		flag[i]=0;
}


void dfs(long long int src)
{
	flag[src]=1;
	Node * temp = graph[src].head;

	while(temp!=NULL)
	{
		if(flag[temp->value]==0)
			dfs(temp->value);
		temp = temp->next;
	}
	stack[size++]=src;
}

long long int scc(long long int src)
{
	flag[src] = 1;
	prod = mul(prod,src);
	calc++;
	Node * temp = reverse[src].head;
	while(temp!=NULL)
	{
		if(flag[temp->value]==0)
			scc(temp->value);
		temp = temp->next;
	}
}

long long int find_scc()
{
	size = 0;
	for(i=1;i<=n;i++)
		if(flag[i]==0)
			dfs(i);
	initialize();

	while(size>0)
	{
		long long int tp = stack[size-1];
		size--;
		if(flag[tp]==0)
		{
			prod = 1;
			calc = 0;
			scc(tp);
			if(calc>1)
			{
				ans = mul(ans,prod);
				ind = 1;
			}
		}
	}
	return 0;
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&M);
		while(m--)
		{
			scanf("%lld%lld",&u,&v);
			graph[u].head = insert(graph[u].head,v);
			reverse[v].head = insert(reverse[v].head,u);
		}
		//	print();
		initialize();
		ind = 0;
		ans = 1;
		find_scc();
		//	printf("\n");
		for(i=1;i<=n;i++)
		{
			graph[i].head = NULL;
			reverse[i].head = NULL;
		}
		if(ind==0)
			printf("-1\n");
		else
			printf("%lld\n",ans);
	}


	return 0;
}
