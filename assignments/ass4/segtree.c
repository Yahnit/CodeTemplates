int construct(long long int block,long long int low,long long int high)
{
	long long int mid;
	if(low!=high)
	{
		mid=(low+high)>>1;
		construct(2*block,low,mid);
		construct(2*block+1,mid+1,high);
		seg[block]=seg[2*block]+seg[2*block+1];
	}
	else
		seg[block]=a[high];
	return 0;
}

long long int update(long long int block,long long int low,long long int high,long long int ind,long long int value)
{
	long long int mid;
	if(low!=high)
	{
		mid=(low+high)>>1;
		if(!(low<=ind && ind<=mid))
			update(2*block+1,mid+1,high,ind,value);
		else
			update(2*block,low,mid,ind,value);

		seg[block]=seg[2*block]+seg[2*block+1];
	}
	else
	{
		seg[block]=value;
		a[ind]=value;
	}

	return 0;
}

long long int query(long long int block,long long int low,long long int high,long long int p,long long int q)
{
	long long int mid,x,y;
	if(p<=low && high<=q)
		return seg[block];
	else if(q<low || high<p)
		return 0;
	mid=(high+low)>>1;
	x=query(2*block,low,mid,p,q);
	y=query(2*block+1,mid+1,high,p,q);

	seg[block]=seg[2*block]+seg[2*block+1];
	return 0;
}

