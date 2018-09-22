#include<stdio.h>
#include<limits.h>

long long int ans = 0;
int flag[510],dist[510];
int a[510][510]={0},n,m,j,i,k;

void initialize(int source)
{
	for(i=1;i<=n;i++)
		flag[i] = 0,dist[i] = INT_MAX;
	dist[source] = 0;
	return;
}

void compute(int ind)
{
	for(j=1;j<=n;j++)
		if(flag[j]==0)
			if(a[ind][j]!=0 && dist[ind]!=INT_MAX)
				if(dist[ind]+a[ind][j]<dist[j])
					dist[j] = a[ind][j]+dist[ind];
	return;
}

long long int dijstra(int source)
{
	long long int res = 0;
	int temp = n-1,ind;
	initialize(source);
	while(temp--)
	{
		long long int min = INT_MAX;
		for(j=1;j<=n;j++)
			if(flag[j]==0 && dist[j]<=min)
				min = dist[j],ind = j;

		flag[ind]=1;
		compute(ind);
	}
	for(j=1;j<=n;j++)
		res+=dist[j];
	return res;
}

void set(int x,int y,int z)
{
	if(a[x][y]<z && a[x][y]!=0)
		a[x][y] = z,a[y][x]=z;
	else if(a[x][y]==0)
		a[x][y] = z,a[y][x]=z;
	return;
}

int main()
{

	int x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
	    set(x,y,z);
	}
	for(k=1;k<=n;k++)
		ans+=dijstra(k);

	printf("%lld\n",ans);
	return 0;
}
