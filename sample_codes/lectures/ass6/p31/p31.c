#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long int n,m,q,i,j,n,x,y;
long long int par[100009],ans[100009],res[100009];
typedef struct graphs
{
	long long int u,v,edge;
}Graph;

Graph graph[200009];
Graph query[100009];

int compare(const void* a,const void * b)
{
	Graph *studentA=(Graph *)a;
	Graph *studentB=(Graph *)b;
	return(studentA->edge-studentB->edge);
}

long long int find(long long int ind)
{
	if(par[ind]<0)
		return ind;
	par[ind] = find(par[ind]);
	return par[ind];
}

int main()
{
	long long int t;
		long long int indx=0,k=0;
	scanf("%lld",&t);
	for(j=1;j<=t;j++)
	{
		scanf("%lld%lld%lld",&n,&m,&q);
		for(i=0;i<m;i++)
			scanf("%lld%lld%lld",&graph[i].u,&graph[i].v,&graph[i].edge);
		qsort(graph,m,sizeof(Graph),compare);

		for(i=0;i<q;i++)
		{
			scanf("%lld%lld",&query[i].u,&query[i].edge);
			query[i].v = i;
		}
		qsort(query,q,sizeof(Graph),compare);
		for(i=1;i<=n;i++)
		{
			par[i] = -1;
			ans[i] = 0;
		}
        k=0;
		for(i=0;i<q;i++)
		{
			while(graph[k].edge<=query[i].edge && k<m)
			{
				x = find(graph[k].u);
				y = find(graph[k].v);
				if(x!=y)
				{
					if(par[x]>par[y])
					{
						par[y]+=par[x];
						par[x] = y;
						ans[y]= ans[y]+ans[x]+graph[k].edge;
					}
					else
					{
						par[x]+=par[y];
						par[y] = x;
						ans[x] = ans[x]+ans[y]+graph[k].edge;
					}
				}
				else
					ans[x] = ans[x]+graph[k].edge;
				k++;
			}
			res[query[i].v] = ans[find(query[i].u)]; 
		}	
		for(i=0;i<q;i++)
			printf("%lld\n",res[i]);
	}
	return 0;
}
