#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int n,m,i,j,indicator[500009],ans;

typedef struct set
{
	int prev,num;
}Set;
Set cycle[100009];
int find(int ind)
{
	if(cycle[ind].prev<0)
		return ind;
	return find(cycle[ind].prev);
}

int unio(int i,int j)
{
	int p,q;
	p = find(i);
	q = find(j);
	// path compression
	if(cycle[i].prev>=0 && cycle[i].prev!=p)
		cycle[i].prev = p;

	if(cycle[j].prev>=0 && cycle[j].prev!=q)
		cycle[j].prev = q;
	if(p!=q)
		return 1;   // cycle does not exist
		return 0;   // cycle exists
}
typedef struct data
{
	int a,b,c;
}Data;

Data details[500009];

int compare(const void* a,const void * b)
{
	Data *studentA=(Data *)a;
	Data *studentB=(Data *)b;
	return(studentA->c-studentB->c);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{ 
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{

			indicator[i]=0;
			scanf("%d%d%d",&details[i].a,&details[i].b,&details[i].c);
			if(i<=n)
			{
				cycle[i].prev = -1;
			}

		}
		qsort(details,m,sizeof(Data),compare);
		int count=0,temp=1,x,y,show=0,val,g,h;
		long long int ans = 0;
		i = 0;
		while(count<n-1 && i<m)
		{
				if(unio(details[i].a,details[i].b)==1)
				{
					ans+=details[i].c;
					indicator[i]=-1;
					count++;
					temp = i;
					g = find(details[i].a);
					h = find(details[i].b);
					if(cycle[g].prev<=cycle[h].prev)
					{
						cycle[h].prev = g;
						cycle[g].prev = cycle[g].prev-1;
					}
					else
					{
						cycle[g].prev = h;
						cycle[h].prev = cycle[h].prev-1;
					}

				}
			if(indicator[i]==0 && show==0)
				show = 1,val = i;
			i++;
		}
		if(show==0)
			ans+=details[temp+1].c;
		else
			ans+=details[val].c;
		printf("%lld\n",ans);	
	}
	return 0;
}

