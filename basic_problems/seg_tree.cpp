#include<iostream>
using namespace std;
#include<cmath>

int seg[1000009] = {0}, a[1000009];
int n,m;
  void construct(int block,int low,int high, int level)
  {
  	if(low!=high)
  	{
  		int mid=(low+high)>>1;
  		construct(2*block,low,mid, level+1);
  		construct(2*block+1,mid+1,high, level+1);

      if (n%2!= level%2)
        seg[block] = seg[2*block] | seg[2*block+1];
      else
        seg[block] = seg[2*block] ^ seg[2*block+1];

  	}
  	else
  		seg[block] = a[high]; // high = low

  	return;
  }

  void update(int block,int low,int high,int ind,int value,int level)
  {
  	int mid;
  	if(low!=high)
  	{
  		mid=(low+high)>>1;
  		if(low<=ind && ind<=mid)
  			update(2*block,low,mid,ind,value, level+1);
  		else
  			update(2*block+1,mid+1,high,ind,value, level+1);

      if (n%2!= level%2)
        seg[block] = seg[2*block] | seg[2*block+1];
      else
        seg[block] = seg[2*block] ^ seg[2*block+1];
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

  int main(){
  	int i;
    cin >> n >> m;

    for(i=1;i<=pow(2,n);i++){
      cin >> a[i];
    }

    construct(1,1,pow(2,n),0);

    for(i=0;i<m;i++){
      int p,b;
      cin >> p >> b;
      update(1,1,pow(2,n),p,b,0);
      cout << seg[1] << '\n';
    }

  return 0;
}
