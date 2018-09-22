#include<iostream>
using namespace std;

int upper_bound(int a[], int high, int n)
{
	int res=high+1;
	int mid,low=0;
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(a[mid]<=n)
		  low=mid+1;
		else
		{
			res=mid;
		  high=mid-1;
		}
	}
	return res;
}

int lower_bound(int a[], int high, int n)
{
	int res=high+1;
	int mid,low=0;
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(a[mid]<n)
		  low=mid+1;
		else
		{
			res=mid;
		  high=mid-1;
		}
	}
	return res-1;
}

int bin_search(int arr[], int n, int a){
  int left = 0,right = n-1;
  while(left<=right){
    int mid = (right+left)>>1;
    if(arr[mid] == a)
      return 1;
    else if(arr[mid] > a)
      right = mid;
    else
      left = mid+1;
  }
  return 0;
}

int main()
{
  int i,arr[100],n,a,there;
  scanf("%d%d", &n,&a);
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

  int bound = upper_bound(arr,n-1,a);
  cout << bound << endl;

// there = bin_search(arr,n,a);
// if(there)
//   printf("Yeayyy! found\n");
// else
//   printf("Am sorry!\n");
  return 0;
}
