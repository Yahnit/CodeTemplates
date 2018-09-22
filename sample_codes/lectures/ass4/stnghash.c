#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long int p=27,mod=1000000007,x,y,fwd[100009],rev[100009],pwr[1000009];
char str[100009];

typedef struct node
{
	long long int l,r;
}Node;
Node arr[10009];

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

int main()
{
	long long int j,n,q,k,len,sum,i;
	scanf("%lld%lld",&n,&q);
	scanf("%s",str);
	len = strlen(str);
	pwr[0]=1;
	fwd[0]=0;
	for(i=1;i<=1000009;i++)
		pwr[i]=(pwr[i-1]*p)%mod;
	for(i=1;i<=len;i++)
		fwd[i] = (fwd[i-1]%mod + ((pwr[i-1]%mod)*(str[i-1]%mod))%mod)%mod;
	sum=0;
	rev[0]=0;
	for(j=1,i=len-1;i>=0 && j<=n;i--,j++)
		rev[j] = ((rev[j-1]%mod) +((pwr[j-1])%mod*str[i]%mod)%mod)%mod;
	long long int f,b,size;
	while(q--)
	{
		f=0;
		b=0;
		scanf("%lld",&k);
		size=0;
		for(j=0;j<k;j++)
		{ 
			scanf("%lld%lld",&arr[j].l,&arr[j].r);
			f = (f + ((((mod+fwd[arr[j].r]-fwd[arr[j].l-1])%mod * power((pwr[(arr[j].l)])%mod,mod-2))%mod)*(power(p,size)%mod)))%mod;			 
			size = size + arr[j].r-arr[j].l +1;
		}
		size=0;
		for(j=k-1;j>=0;j--)
		{
			b =( b + ((((mod+rev[n-arr[j].l+1]-rev[n-arr[j].r])%mod * power((pwr[n-arr[j].r+1])%mod,mod-2))%mod)*(power(p,size))%mod))%mod;			 

			size = size + arr[j].r-arr[j].l +1;
		}
		if(f==b)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
