#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

long long int n,m,t,i,j,res;
long long int a[100009],b[100009],c[100009];
long long int dij[1009][1009];

void dijstra()
{
	long long int i;
    for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
			if(dij[b[j]][i+1]-c[j]>dij[a[j]][i])
				if(c[j]+dij[a[j]][i]<=t)
					dij[b[j]][i+1] = c[j]+dij[a[j]][i];
	return;
}

int main()
{
	scanf("%lld%lld%lld",&n,&m,&t);
    for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			dij[i][j] = INT_MAX;
	dij[1][1] = 0;
   for(i=1;i<=m;i++)
	   scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	dijstra();
	for(i=1;i<=n;i++)
		if(t>=dij[n][i])
			res = i;
    printf("%lld\n",res);
	return 0;
}
