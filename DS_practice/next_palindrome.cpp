#include<iostream>
using namespace std;

int checkAllNines(int a[], int n){
  for(int i=0;i<n;i++)
    if(a[i] != 9)
      return 0;
  return 1;
}

void nextPalindrome(int a[], int n){
  if(checkAllNines(a,n)){
    cout << "1";
    for(int i=0;i<n-1;i++)
      cout << "0";
    cout << "1";
    return;
  }

    int mid = n >> 1;
    int l,r;

    if(n%2)
      l = mid -1, r = mid + 1;

    else
      l = mid-1, r = mid;

    while(a[l] == a[r] && l>=0)
      l--, r++;

      // PALINDROME
      // increase the middle ele and mirror
    if(l<0 || a[l] < a[r]){

      if(n%2)
        mid = n >> 1;
      else
        mid = (n>>1) -1;

      a[mid] += 1;
      int carry = a[mid]/10;
      a[mid] = a[mid]%10;

      a[mid-1] += carry;

      for(int i=0;i<n/2;i++){
        a[n-i-1] = a[i];
      }

    }
    // replace right part by mirroring the left part
    if(a[l] > a[r]){
      while(l>=0){
        a[r] = a[l];
        l--, r++;
      }
    }

return;
}

void printArr(int a[], int n){
  for(int i=0;i<n;i++)
    cout << a[i] << " ";
  cout << "\n";
return;
}

int main(){
  int n,a[10000], i;

  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];

  nextPalindrome(a,n);
  printArr(a,n);

return 0;
}
