#include<stdio.h>
#include<limits.h>
#include<math.h>

long long int dist[2000],p,q,t,n,x[2000],y[2000],i,flag[2000],a,b,min,ind,count,ans;

void get_inp()
{
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&x[i],&y[i]);
			if(x[i]+y[i]<min)
			{
				min = x[i]+y[i];
				p = x[i],q = y[i],ind = i;
			}
			flag[i]=0;
		}
		return;
}

void initialize()
{
		ans+=min;
		a=p,b=q;
		flag[ind]=1;
		count = 1;
		for(i=1;i<=n;i++)
			dist[i] = fabs(x[i]-a)+fabs(y[i]-b);
		return;
}

long long int mst()
{
	while(count<n)
		{
			count++;
			min = INT_MAX;
			for(i=1;i<=n;i++)
			{
				if(((fabs(x[i]-a)+fabs(y[i]-b))<dist[i]) && flag[i]==0)
					dist[i] = fabs(x[i]-a)+fabs(y[i]-b);

				if(min>dist[i] && flag[i]==0)
				{
					min = dist[i];
					p = x[i],q = y[i],ind = i;
				}
			}
				flag[ind]=1;
				ans+=min;
				a=p,b=q;
		}
	return ans;
}

int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		a=0,b=0,count=0,ans=0;
		min = INT_MAX;
		get_inp();
        initialize();
        ans=mst();
		printf("%lld\n",ans);
	}
	return 0;
}
