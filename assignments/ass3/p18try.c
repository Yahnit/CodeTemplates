#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long int maxm(long long int a,long long int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	long long int t,i,a[100009],arr[100009],max=0,size;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,k;
		max=0,size=0;
		arr[size++]= -1;
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]>0)
				arr[size++]=i;
			else
			{
				long long int temp=arr[size-1];
				if(a[arr[size-1]]+a[i]==0)
				{
                        size--;
						max= maxm(max,i-arr[size-1]);
				}
				else
				{
					size=0;
					arr[size++]=i;
				}
			//	size--;

     
	 /*			if(size!=0)
				{
					   if(temp+a[i]==0)
						max= (i-arr[size-1])>max ? i-arr[size-1]:max;
					   else
					   {
						   size=0;
						   arr[size++]=i;
					   }
				}
				else 
					arr[size++]=i;*/

			}
		}
		printf("%lld\n",max);
	}


	return 0;
}
