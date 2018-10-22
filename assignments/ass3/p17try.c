#include<stdio.h>
#include<stdlib.h>
//long long int a[1000009],b[1000009];

typedef struct node
{
	long long int val;
	struct node *left,*right;
}Node;
Node *root=NULL;
int check(Node * cur);
Node *insert(long long int value,Node *temp)
{
	if(temp==NULL)
	{
		Node *cur = (Node*)malloc(sizeof(Node));
		cur->val = value;
		cur->left = NULL;
		cur->right = NULL;
		return cur;
	}
	
	if(value < temp->val)
		temp->left=insert(value,temp->left);
	else if(value > temp->val)
	temp->right=insert(value,temp->right);
	return temp;
}
void print(Node *root)
{
	if(!root) return;
	print(root->left);
	printf("%lld ", root->val);
	print(root->right);
}

int main()
{
    long long int t,n,k,i,x;
	scanf("%lld",&t);

	while(t--)
	{
		root=NULL;
        scanf("%lld",&n);
		scanf("%lld",&x);
		root=insert(x,root);
		for(i=1;i<n;i++)
		{
			scanf("%lld",&x);
			insert(x,root);
		}
//		printf("%lld",root->val);
      scanf("%lld",&k);
	  for(i=0;i<k;i++)
	  {
		  scanf("%lld",&x);
		  insert(x,root);		  
	  }
//	  print(root);
      int flag=1;
	  if(root->right!=NULL)
	  flag=check(root->right);
	  if(flag==1 && root->left!=NULL)
	  flag=check(root->left);
	  if(flag==1)
	  printf("Yes\n");
	  else
	  printf("No\n");

	}

	return 0;
}

int check(Node * cur)
{
   if(cur->left!=NULL && cur->right!=NULL)
      return 0;
   else if(cur->left==NULL && cur->right==NULL)
      return 1;
   else if(cur->left==NULL && cur->right!=NULL)
	 return check(cur->right);
   else if(cur->right==NULL && cur->left!=NULL)
	  return check(cur->left);
}



