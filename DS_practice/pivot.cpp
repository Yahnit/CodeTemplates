#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<cmath>

int find_pivot(int a[], int low, int high){

  while(low<=high){
    int mid = (high+low) >> 1;

    if(a[mid] < a[mid-1] && a[mid] < a[mid+1])
        return a[mid];

    if(a[low] > a[mid])
      high = mid;

    else if(a[mid] > a[high])
      low = mid;

    else
      return a[low];

  }
  return -1;
}




int pivot(int a[], int low, int high){
  int mid;

  while(low<=high){
    int mid = (high+low)>>1;

    if(a[mid-1] > a[mid] && a[mid] < a[mid+1])
      return mid;

    if(a[low] > a[mid])
      high = mid;

    else if (a[mid] > a[high])
      low = mid;

    else
      return 0;
  }
return -1;
}


int main(){

  int n,i,a[100];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];

  int ans = pivot(a,0,n-1);

  cout << ans << endl;

  return 0;
}
