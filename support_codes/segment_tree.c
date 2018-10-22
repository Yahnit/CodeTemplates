#include<stdio.h>
#include<limits.h>

int seg[1000009] = {0}, a[1000009];

void construct(int block,int low,int high)
{
	if(low!=high)
	{
		int mid=(low+high)>>1;
		construct(2*block,low,mid);
		construct(2*block+1,mid+1,high);

    // CHANGE IT ACCORDING TO UR NEED
    seg[block] = seg[2*block] + seg[2*block+1];
  //  seg[block] = max(seg[2*block],seg[2*block+1]);
	}
	else
		seg[block] = a[high]; // high = low

	return;
}

void update(int block,int low,int high,int ind,int value)
{
	int mid;
	if(low!=high)
	{
		mid=(low+high)>>1;
		if(low<=ind && ind<=mid)
			update(2*block,low,mid,ind,value);
		else
			update(2*block+1,mid+1,high,ind,value);

      // CHANGE IT ACCORDING TO UR NEED
	  seg[block] = seg[2*block] + seg[2*block+1];
	}
	else
	{
		seg[block] = value;
		a[ind] = value;
	}

	return;
}

int query(int block,int low,int high,int p,int q)
{
	int mid,x,y;

  if(p<=low && high<=q)
		return seg[block];
	else if(q<low || high<p)
		return 0;

  mid=(high+low)>>1;

  // CHANGE IT ACCORDING TO UR NEED
	return query(2*block,low,mid,p,q) + query(2*block+1,mid+1,high,p,q);
}

int main()
{
	int n,m,i,p,q,j,max,min,c,v;
	scanf("%d %d",&n,&m);
	int ch;

	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	construct(1,1,n);

	while(m--)
	{
    scanf("%d%d%d",&ch,&p,&q);

		if(ch==1)
		{
			v = query(1,1,n,p,q);
			printf("%d\n", v);
		}

		else if(ch==2)
			update(1,1,n,p,q);

	}
	return 0;
}
