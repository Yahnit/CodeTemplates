#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

long long int n,m,i,j,flag[500009],ans;

typedef struct set
{
	long long int parent,num;
}Set;
Set cycle[100009];
long long int find(long long int ind)
{
	if(cycle[ind].parent<0)
		return ind;
	return find(cycle[ind].parent);
}

long long int unio(long long int i,long long int j)
{
	long long int p,q;
	p = find(i);
	q = find(j);
	if(cycle[i].parent>=0 && cycle[i].parent!=p)
		cycle[i].parent = p;

	if(cycle[j].parent>=0 && cycle[j].parent!=q)
		cycle[j].parent = q;
	if(p!=q)
		return 0;
	else
		return 1;
}
typedef struct data
{
	long long int a,b,c;
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
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{ 
		scanf("%lld%lld",&n,&m);
		for(i=0;i<m;i++)
		{

			flag[i]=0;
			scanf("%lld%lld%lld",&details[i].a,&details[i].b,&details[i].c);
			if(i<=n)
			{
				cycle[i].parent = -1;
			}

		}
		qsort(details,m,sizeof(Data),compare);
		long long int count = 0,temp=1,x,y,ans=0,show=0,val,g,h;
		i = 0;
		while(count<n-1 && i<m)
		{
				if(unio(details[i].a,details[i].b)==0)
				{
					ans+=details[i].c;
					flag[i]=-1;
					count++;
					temp = i;
					g = find(details[i].a);
					h = find(details[i].b);
					if(cycle[g].parent<=cycle[h].parent)
					{
						cycle[h].parent = g;
						cycle[g].parent = cycle[g].parent-1;
					}
					else
					{
						cycle[g].parent = h;
						cycle[h].parent = cycle[h].parent-1;
					}

				}
			if(flag[i]==0 && show==0)
			{
				show = 1;
				val = i;
			}
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

