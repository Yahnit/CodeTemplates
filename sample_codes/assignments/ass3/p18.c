#include<stdio.h>

int main()
{
	int t,i,a[100009],stack[100009],max=0;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		max=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int size=0,sum=0;
		for(i=0;i<n;i++)
		{
			if(size==0 && a[i]>0)
				stack[size++]=a[i],sum+=a[i];
			else if(size==0 && a[i]<0)
				size=0,sum=0;
			else if(a[i]<0 && stack[size-1]>0 && stack[size-1]+a[i]==0 )
			{
				stack[size++]=a[i],sum+=a[i];
				if(sum==0)
				{
					if(size>max)
						max=size;
				}
			}

			else if(a[i]<0 && stack[size-1]>0 && stack[size-1]+a[i]!=0 )
			{
				size=0,sum=0;
			}
			else if(a[i]<0 && stack[size-1]<0 )
			{
				if(sum==0)
					size=0;
				else
				{
					stack[size++]=a[i],sum+=a[i];
					if(sum==0)
					{
						if(size>max)
							max=size;
					}
				}
			}
			else if(a[i]<0 && stack[size-1]>0 && (stack[size-1]+a[i])!=0)
			{
				size=0,sum=0;
			}

			else if(a[i]>0)
			{
				stack[size++]=a[i],sum+=a[i];
			}
		}
		printf("%d\n",max);
	}

	return 0;
}
