#include<stdio.h>
long long int t,n,k,a[100009],arr[100009],i,max,size;

long long int find()
{
	arr[0]=-1;
	size=1;
	max=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>0)
			arr[size++]=i;
		else if (a[i]<0)
		{
			if(a[arr[size-1]]+a[i]==0)
			{
				size--;
				if(size!=0)
				{
					if(max<(i-arr[size-1]))
						max=(i-arr[size-1]);
				}
				else arr[size++]=i;
			}
			else
			{
				size=0;
				arr[size]=i;
				size++;
			}
		}
	}
	return max;
}
int main()
{

	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		printf("%lld\n",find());
	}
	return 0;
}
