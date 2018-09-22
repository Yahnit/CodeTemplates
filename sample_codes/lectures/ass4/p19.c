#include<stdio.h>
#include<limits.h>

long long int maxm(long long int a,long long int b);
long long int minm(long long int a,long long int b);
typedef struct Segment
{
	long long int max;
	long long int min;
}segment;

segment seg[1000009];
long long int a[1000009];

long long int construct(long long int block,long long int low,long long int high);

long long int update(long long int block,long long int low,long long int high,long long int ind,long long int value);

long long int query1(long long int block,long long int low,long long int high,long long int p,long long int q);

long long int update(long long int block,long long int low,long long int high,long long int ind,long long int value)
{
	long long int mid;
	if(low!=high)
	{
		mid=(low+high)>>1;
		if(low<=ind && ind<=mid)
			update(2*block,low,mid,ind,value);
		else
			update(2*block+1,mid+1,high,ind,value);

	seg[block].max=maxm(seg[2*block].max,seg[2*block+1].max);
	seg[block].min=minm(seg[2*block].min,seg[2*block+1].min);
	}
	else
	{
		seg[block].min=value;
		seg[block].max=value;
		a[ind]=value;
	}

	return 0;
}



long long int query2(long long int block,long long int low,long long int high,long long int p,long long int q)
{
	long long int mid,x,y;
	if(p<=low && high<=q)
		return seg[block].max;
	else if(q<low || high<p)
		return 0;
	mid=(high+low)>>1;
	return maxm(query2(2*block,low,mid,p,q),query2(2*block+1,mid+1,high,p,q));
}
int main()
{
	long long int n,m,i,p,q,j,max,min,c,v;
	scanf("%lld %lld",&n,&m);
	char ch;

	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=5*n;i++)
	{
		seg[i].max=0;
		seg[i].min=INT_MAX;
	}
	construct(1,1,n);

	long long int o=2*m;
	while(o--)
	{ 
		scanf("%c",&ch);

		if(ch=='t')
		{
			scanf("%lld%lld",&p,&q);
			c=query1(1,1,n,p,q);
			v=query2(1,1,n,p,q);
			long long int diff=q+1-p;
			if(diff<(v-c))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else if(ch=='r')
		{
			scanf("%lld%lld",&p,&q);
			update(1,1,n,p,q);
		}
	}
	return 0;
}

long long int maxm(long long int a,long long int b)
{
	if(a>b)
		return a;
	return b;
}

long long int minm(long long int a,long long int b)
{
	if(a>b)
		return b;
	return a;
}


long long int construct(long long int block,long long int low,long long int high)
{
	long long int mid;
	if(low!=high)
	{
		mid=(low+high)>>1;
		construct(2*block,low,mid);
		construct(2*block+1,mid+1,high);
		seg[block].max=maxm(seg[2*block].max,seg[2*block+1].max);
		seg[block].min=minm(seg[2*block].min,seg[2*block+1].min);
	}
	else
	{
		seg[block].min=a[high];
		seg[block].max=a[high];
	}
	return 0;
}

long long int query1(long long int block,long long int low,long long int high,long long int p,long long int q)
{
	long long int mid,x,y;
	if(p<=low && high<=q)
		return seg[block].min;
	else if(q<low || high<p)
		return INT_MAX;
	mid=(high+low)>>1;
	return minm(query1(2*block,low,mid,p,q),query1(2*block+1,mid+1,high,p,q));
}
