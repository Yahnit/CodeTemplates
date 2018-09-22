#include<iostream>
using namespace std;

int main(){
  int arr[100], k,n,i;
  cin >> n >> k;
  for(i=0;i<n;i++)
    cin >> arr[i];

  sort(arr,arr+n);

  for(i=0;i<n;i++){
    int fix = arr[i];
    int left = i+1;
    int right = n-1;
    while(left<=right){
      int tent_sum = fix + arr[left] + arr[right];
      if(tent_sum == k){
          cout << "YEAY!!" << endl;
          return 0;
      }
      else if(tent_sum < k)
        left ++;
      else
        right--;
    }
  }
  cout << "NAHEEEE!\n";
  return 0;
}
