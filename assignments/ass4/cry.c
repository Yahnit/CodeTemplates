#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long int p=7,mod=1000000007,fwd[100009],rev[100009],x,y,pwr[100009];
	char str[100009];
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
			 return (((var*var)%mod)*x)%mod;
		 else
            return (var*var)%mod;
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
	fwd[1]=str[0];
//  printf("%lld %lld",n,len);
	for(i=1;i<=n+1;i++)
       {
		   pwr[i]=(pwr[i-1]*p)%mod;
	   }
	
	for(i=1;i<=len;i++)
	{
		fwd[i] = (fwd[i-1]+ (pwr[i-1]*str[i-1])%mod)%mod;
				  printf("%lld => fwd ",fwd[i]);
	}
	printf("\n");
	sum=0;
	
	   rev[0]=0;
	   rev[1]=str[len-1];
	for(j=2,i=len-2;i>=0 && j<=n;i--,j++)
	{
		rev[j] = (rev[j-1] +(pwr[j-1]*str[i])%mod)%mod;
			  printf("%lld => rev ",rev[i]);
	}
	printf("\n");
	long long int f,b,size;
	while(q--)
	{
		f=0;
		b=0;
		scanf("%lld",&k);
		size=0;
		for(j=0;j<k;j++)
		{ 
			scanf("%lld%lld",&x,&y);
              f = (f + ((((mod+fwd[y]-fwd[x-1])%mod * power(pwr[x-1],mod-2))%mod)*pwr[size])%mod)%mod;			 
              b = (b*pwr[size])%mod + ((((mod+rev[n-x+1]-rev[n-y])%mod * power((pwr[n-y]),mod-2))%mod))%mod;			 
			  
			  size = size + y-x+1;
//			  printf("%lld temp f\n",f);
		}
/*		size=0;
        for(j=k-1;j>=0;j--)
		{
	 
			  size = size + v[j]-u[j] +1;

		}*/
//        printf("f=%lld b=%lld\n",f,b);
		if(f==b)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
