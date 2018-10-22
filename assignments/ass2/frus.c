#include<stdio.h>
#include<math.h>

long long int c[2002],d[2002],a[2002][2002]={0},dist[2002],max=1000000009,cost[2002][2002]; 

long long int  shortest_dist(long long int n)
{
	long long int i,u,count,w,flag[2002],min,v=0;
	for(i=1;i<=n;i++)
		flag[i]=0,dist[i]=cost[v][i];
	count=2;
	while(count<=n)
	{
		min=max;
		for(w=1;w<=n;w++)
			if(dist[w]<min && !flag[w])
				min=dist[w],u=w;
		flag[u]=1; count++;
		for(w=1;w<=n;w++)
			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
				dist[w]=dist[u]+cost[u][w];
		printf("%lld ",dist[w]);
	}
	for(i=1;i<=n;i++)
		printf("%lld ",dist[i]);
	return dist[n];
}


int main()
{
	long long int n,i,j;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(i=1;i<=n-1;i++)
		scanf("%lld",&d[i]);

	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=i+d[i] && j<=n;j++)
		{
			a[i][j]=c[j];
		} 
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			if(a[i][j]==0)
				cost[i][j]=max;
			else
				cost[i][j]=a[i][j];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%lld ",cost[i][j]);
		printf("\n");
	}
	long long int ans= shortest_dist(n)+c[1];
	printf("%lld\n",ans);
	return 0;
}

