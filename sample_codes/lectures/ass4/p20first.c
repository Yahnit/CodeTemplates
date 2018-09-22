#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	long long int val;
	struct node * next;
}Node;

typedef struct list
{
	Node * head;
	long long int valid;
	long long int place;
}List;

Node* insert(Node * head,long long val)
{
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
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

int main()
{
	long long int n,m,i,x,y;
	long long int flag[1000009],ans=1;

	scanf("%lld%lld",&n,&m);
	for(i=0;i<=n;i++)
	{
		graph[i].head=NULL;
		graph[i].valid=0;
	}
	for(i=0;i<=n;i++)
		flag[i]=0;
	scanf("%lld%lld",&x,&y);
	flag[x]=1;flag[y]=-1;

	for(i=1;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(x!=y)
		{
			if(flag[x]==0 && flag[y]==0)
			{
				graph[x].head=insert(graph[x].head,y);
				graph[x].valid=1;
				graph[y].head=insert(graph[y].head,x);
				graph[y].valid=1;
			}
			if(flag[x]==flag[y] && flag[x]!=0)
				ans=0;
			if(flag[x]==0 && flag[y]!=0)
			{
				if(graph[x].valid==1)
				{
					graph[x].valid=0;
					Node * temp = graph[x].head;
						while(temp!=NULL)
						{
							if(flag[temp->val]== -flag[y])
								ans=0;
							else flag[temp->val]= flag[y];
							temp=temp->next;  
						}
				}
				flag[x]= -flag[y];
			}

			if(flag[y]==0 && flag[x]!=0)
			{
				if(graph[y].valid==1)
				{
					graph[y].valid=0;
					Node * temp = graph[y].head;
						while(temp!=NULL)
						{
							if(flag[temp->val]== -flag[x])
								ans=0;
							else flag[temp->val]= flag[x];
							temp=temp->next;  
						}
				}
				flag[y]= -flag[x];
			}
		}
	}


	 for(i=0;i<=n;i++)
        {
			if(graph[i].valid==1)
			{
               if(flag[i]!=0)
			   {
				   Node* temp =graph[i].head;
                    while(temp!=NULL)
					{
						if(flag[temp->val]==flag[i])
							ans=0;
						if(flag[temp->val]==0)
							flag[temp->val]= -flag[i];
						temp=temp->next;
					}
					graph[i].valid=0;
			   }
			}
		}

	
	int count=0;
	 count=-10;
	 for(i=0;i<=n;i++)
        {
			if(graph[i].valid==1)
			{
               if(flag[i]!=0)
			   {
				   Node* temp =graph[i].head;
                    while(temp!=NULL)
					{
						if(flag[temp->val]==flag[i])
							ans=0;
						if(flag[temp->val]==0)
							flag[temp->val]= -flag[i];
						temp=temp->next;
					}
					graph[i].valid=0;
			   }
			   else
			   { 
				   count=-10;
				   Node* temp = graph[i].head;
					   while(temp!=NULL)
                        {
                             if(flag[temp->val]!=0)
							 {
								 count=flag[temp->val];
							     break;
							 }
								 temp=temp->next;
						}
				   if(count==-10)
				   {
					   flag[i]=1;
					   temp=graph[i].head;
					   while(temp!=NULL)
					   {
						   flag[temp->val]=-1;
                            temp=temp->next;
					   }
				   }
				   else
				   {
                        flag[i]= -count;
						temp=graph[i].head;
						while(temp!=NULL)
						{
							if(flag[temp->val]== flag[i])
								ans=0;
							else
								flag[temp->val]=count;
							temp=temp->next;
						}

				   }

						   
			   }
			}
		}

	if(ans==1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
