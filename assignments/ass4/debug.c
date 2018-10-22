#include<stdio.h>
#include<string.h>

 int p=27,mod=1000000007,u[100009],v[100009],fwd[100009],rev[100009],pwr[100009];
	char str[100009];
int power(int x,int y)
{
   if(y==1)
	   return x;
   else if(y==0)
	   return 1;
   else
   {
       int var = power(x,y>>1);
         if(y&1==1)
			 return (((((long long int)var%mod)*((long long int)var%mod))%mod)*((long long int )x%mod))%mod;
		 else
            return ((long long int)var%mod * var%mod)%mod;
   }
}


int main()
{
	int j,n,q,k,len,sum,i;
	scanf("%d%d",&n,&q);
	scanf("%s",str);
	len = strlen(str);
    pwr[0]=1;
	fwd[0]=0;
	fwd[1]=str[0];
//  printf("%lld %lld",n,len);
	for(i=1;i<=n+1;i++)
       {
		   pwr[i]=((long long int)pwr[i-1]*p)%mod;
	   }
	
	for(i=2;i<=len;i++)
	{
		fwd[i] = ((long long int)fwd[i-1]%mod + ((long long int)(pwr[i-1]%mod)*(str[i-1]%mod))%mod)%mod;
				  printf("%d => fwd ",fwd[i]);
	}
	printf("\n");
	sum=0;
	
	   rev[0]=0;
	   rev[1]=str[len-1];
	for(j=2,i=len-2;i>=0 && j<=n;i--,j++)
	{
		rev[j] = ((long long int)(rev[j-1]%mod) +((long long int)(pwr[j-1])%mod*str[i]%mod)%mod)%mod;
				  printf("%d => rev ",rev[i]);
	}
	printf("\n");
	int f,b,size;
	while(q--)
	{
		f=0;
		b=0;
		scanf("%d",&k);
		size=0;
		for(j=0;j<k;j++)
		{ 
			scanf("%d%d",&u[j],&v[j]);
              f = (f + ((((mod+(long long int)fwd[v[j]]-fwd[u[j]-1])%mod * (long long int)power((pwr[u[j]-1])%mod,mod-2))%mod)*(long long int)pwr[size])%mod)%mod;			 
	 
			  size = size + v[j]-u[j] +1;
			  printf("f= %d \n",f);
		}
		size=0;
        for(j=k-1;j>=0;j--)
		{
              b =( b + ((((mod+(long long int)rev[n-u[j]+1]-rev[n-v[j]])%mod * (long long int)power((pwr[n-v[j]])%mod,mod-2))%mod)*(long long int)pwr[size])%mod)%mod;			 
	 
			  printf("b= %d \n",b);
			  size = size + v[j]-u[j] +1;

		}
        printf(" final f=%d b=%d\n",f,b);
		if(f==b)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
