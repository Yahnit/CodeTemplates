#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long int h[100001],a[100001],b[100001],modulo=1000000009;
int main()
{
	long long int n,i,area=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld%lld",&h[i],&a[i],&b[i]);
	i=n;
	b[0]=-1000000001,h[0]=0,a[0]=-1000000001;
	while(i>0)
	{ 
		if(a[i]>=b[i-1])
		{
			area=(area+h[i]*(b[i]-a[i]))%modulo;
			i--;
		}
		else
		{
			if(h[i]>=h[i-1])
			{
				area=(area+h[i]*(b[i]-a[i]))%modulo;
				b[i-1]=a[i];
				i--;
			}
			else 
			{
				area=(area+h[i]*(b[i]-b[i-1]))%modulo;
				i--;
			}
		}

	}
	printf("%lld",area%modulo);

return 0;
}
