#include<stdio.h>
#include<string.h>

long long int n,q,k,x,y,len,sum=0,p=2,i,mod=100000009,u[100009],v[100009],fwd[100009];

power(long long int x,long long int y,long long int mod)
{
	long long int temp=1;
	while(y!=0)
	{
		if(y%2==1)
			temp = (x*temp)%mod;
		x = (x*x)%mod;
		y=y/2;
	}
	return temp;
}


int main()
{
	scanf("%lld%lld",&n,&q);
	char str[1000009];
	scanf("%s",str);
	len = strlen(str);

	sum=0;
	for(i=0;i<len;i++)
	{
		sum = (sum*p + str[i])%mod;
		fwd[i]=sum;
		//		  printf("%lld => fwd ",fwd[i]);
	}

	inv[0]=1;
   for(i=1;i<len;i++)
   {
      inv[i] = (inv[i-1]*p)%mod;
   }
 

	long long int f,b,j;
	while(q--)
	{
		f=0;
		b=0;
		long long int p=0,q=0;
		scanf("%lld",&k);
		for(j=0;j<k;j++)
		{ 
			scanf("%lld%lld",&u[j],&v[j]);
			temp =  (fwd[v[j]]-fwd[u[j]-1] + mod)%mod;
            pow = power(inv[v[j]],mod-2,mod);  
			f= f +(temp*pow)%mod;
			size = size + v[j]-u[j]+1;
		}
		for(j=k-1;j>=0;j--)
		{
			for(i=v[j];i>=u[j];i--)
			{
				b = b*p + str[i-1]-47;
			}
		}

		if(f==b)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
