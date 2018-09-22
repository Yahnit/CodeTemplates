#include<iostream>
using namespace std;

int main(){
  int arr[100],i;

  for(i=0;i<5;i++)
    cin >> arr[i];
  // int n = arr.length();
  sort(arr,arr+5);

  for(i=0;i<5;i++)
    cout << arr[i] << " ";
  return 0;
}
