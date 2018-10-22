#include<stdio.h>
#include<stdlib.h>

long long int mod = 1000000007,size=0,count=1,j;
long long int t,n,m,f[100009],flag[100009],x,y,i,arr[100009],fact[1000009],check[1000009],freq[1000009];
long long int bfs(long long int i);
long long int LCM(long long int freq[],long long int len);
typedef struct node
{
	long long int value;
	struct node * next;
}Node;

long long int power(long long int x,long long int y)
{
	if(y==1)
		return x;
	else if(y==0)
		return 1;
	else
	{
		long long int var = power(x,y>>1);
		if(y&1==1)
			return ((((var%mod)*(var%mod))%mod)*(x%mod))%mod;
		else
			return (var%mod * var%mod)%mod;
	}
}


typedef struct list
{
	Node * head;
}List;
List graph[100009];

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
	printf("\n");
	return ;
}


int function(long long int i);

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

int main()
{
	for(i=2;i<1000009;i+=2)
		fact[i]=2;

	scanf("%lld",&t);

	for(i=3;i<1000009;i=i+2)
		if(check[i]==0)
		{
			fact[i]=i;
			for(j=i;1000009>i*j;j=j+2)
				if(check[i*j]==0)
					fact[i*j]=i,check[i*j]=1;
	    }
	fact[0]=1;fact[1]=1;
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		count=1;

		start=NULL;
		end = NULL;

		for(i=1;i<=n;i++)
		{
			graph[i].head=NULL;
			flag[i]=0;
			scanf("%lld",&f[i]);
		}

		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&x,&y);
			if(x!=y)
			{
			graph[x].head = insert(graph[x].head,y);
			graph[y].head = insert(graph[y].head,x);
			}
		}

	//	print();
		long long int old=1,temp,j;
		for(i=1;i<=n;i++)
			if(flag[i]==0)
				temp = bfs(i);
		long long int ans;
		ans=LCM(freq,count-1);
		printf("%lld\n",ans);
	}
	return 0;
}
long long int bfs(long long int i)
{
	long long int top,max,j;
	max=f[i];
	flag[i]=1;
	enqueue(i);
	size++;
	while(size!=0 && size>0)
	{
		top=dequeue();
		size--;
		Node* temp = graph[top].head;

		while(temp!=NULL)
		{
			if(flag[temp->value]==0)
			{
				if(max<f[temp->value])
				{
					max=f[temp->value];
				}
				flag[temp->value]=1;
				enqueue(temp->value);
				size++;
			}
			temp = temp->next;
		}
	}
	arr[count++]=max;

	return max;
}


long long int tp,sn[1000009];
long long int LCM(long long int freq[],long long int len)
{
	long long int use,sze=0,cn=0;
	start=NULL;
	for(i=1;i<=len;i++)
	{
		tp = arr[i];
		while(tp!=0 && tp>1)
		{
            long long int v=fact[tp];
			use=0;
			while(tp%v==0)
				 {
					use++;
                    tp=tp/v;
				 }
			if(freq[v]==0)
		      { 
			    freq[v]=use;
			    sn[sze++]=v;
		      }
	// i could have put only the else statement omitting the if(freq[v]==0) but in that case u push the same numbers repeatedly to the array which is giving TLE!		
			else
				if(freq[v]<use)
					freq[v]=use;
		}
	}
    long long int ans=1;
    for(i=0;i<sze;i++)
	{
         ans=ans*(power(sn[i],freq[sn[i]])%mod)%mod;
		 freq[sn[i]]=0;
	}
	return ans;
}

