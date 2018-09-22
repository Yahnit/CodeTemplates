#include<stdio.h>
int f=0;
long long int func(long long int a,long long int b,long long int c)
{
	long long int temp=(a|b)*(a|b)-(a&b)*(a&b);
	if(temp>c)
		c=temp;
	return c;
}

long long int a[1000001],stack[1000001];
/*
int lis(int arr[], int n)
{
	int max_lis_length = 1;
	find_max_val( arr, n, &max_lis_length );
	return max_lis_length;
}*/

int main()
{
	long long int t,n,a[1000001],i,j,k,m1,m2,temp;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		long long int max=0,size=0,k=1;
		stack[size++]=a[0];
		stack[-1]=0;

		while(k<n)
		{
			if(a[k]>=stack[size-1])
			{
				max=func(a[k],stack[size-1],max);
				stack[size++]=a[k++];
			}
			else
			{
				while(stack[size-1]>=a[k])
				{
					max=func(stack[size-1],a[k],max);
					size--;
				}
				if(size>0)
				{
					max=func(stack[size-1],a[k],max);
					stack[size++]=a[k++];
				}
				else
				{
					stack[size++]=a[k++];
				/*	for(i=0;i<f;i++)
					{ 
						int arr[10000],h,j;
						if(arr[h]>arr[j])
							arr[h]=arr[j];	  
					}*/
				}
			}

		}		

		printf("%lld\n",max);


	}

	return 0;
}
/*
int find_max_val(int arr[], int n, int *max_lis_length)
{
	if (n == 1)
		return 1;

	int current_lis_length = 1,i;
	for (i=0; i<n-1; i++)
	{
		int subproblem_lis_length = find_max_val(arr, i, max_lis_length);
		if (arr[i] < arr[n-1] &&
				current_lis_length < (1+subproblem_lis_length))
			current_lis_length = 1+subproblem_lis_length;
	}
	if (*max_lis_length < current_lis_length)
		*max_lis_length = current_lis_length;

	return current_lis_length;
}*/
