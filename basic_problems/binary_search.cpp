#include<iostream>
using namespace std;

int lowerBound(int a[], int n, int ele){
	int l = 0, r = n-1;
	int ans = n;

	while(l <= r){
		int mid = (l+r) >> 1;

		if(a[mid] < ele){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int upperBound(int a[], int n, int ele){
	int l = 0, r = n-1;
	int ans = n;

	while(l <= r){
		int mid = (l+r) >> 1;

		if(a[mid] <= ele){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int bin_search(int arr[], int n, int a){
  int left = 0,right = n-1;
  while(left<=right){
    int mid = (right+left)>>1;
    if(arr[mid] == a)
      return 1;
    else if(arr[mid] > a)
      right = mid-1;
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

  int bound = lowerBound(arr,n,a);
  cout << bound << endl;

// there = bin_search(arr,n,a);
// if(there)
//   printf("Yeayyy! found\n");
// else
//   printf("Am sorry!\n");
  return 0;
}
