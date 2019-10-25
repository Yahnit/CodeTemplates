#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<cmath>

void rotate(int a[], int l, int r){
  int temp = a[r;]
  for(int i=l;i<r;i++){
    a[l+1] = a[l];
  }
  a[l] = temp;
  return;
}

void print_arr(int arr[], int n){
  for(int i=0;i<n;i++)
    cout << arr[i] << " ";
  cout << "\n";
  return;
}

int gcd(int a, int b){
    if(b==0)
      return a;

    return gcd(b, a%b);
}

void rotate(int a[], int d, int n){
  for(int i=0;i<gcd(n,d);i++){
    int temp = a[i];
    int ind = i;

    while(1){
      a[ind] = a[(ind+d)%n];
      ind = (ind+d)%n;
      if(ind == i)
        break;
    }
    a[(ind-d+n)%n] = temp;
  }
return;
}

// int main(){
//
//   int n,d,i,a[1000];
//   cin >> n >> d;
//   for(i=0;i<n;i++)
//     cin >> a[i];
//
//   int count = 1,ind = 0,prev=a[0],temp;
//   int hel = a[d];
//
// // THIS METHOD IS WRONG
// // YOU SHOULD REPEAT THIS PROCESS FOR SETS OF SIZE GCD(n,d)
//
//   while(count<n){
//     int replace_ind = (ind+n-d)%n;
//
//     temp = a[replace_ind];
//     a[replace_ind] = prev;
//     prev = temp;
//
//     ind = replace_ind;
//
//     count++;
//
//     for(i=0;i<n;i++)
//       cout << a[i]<< " ";
//     cout << "\n";
//   }
//   a[0] = hel;
//
//   for(i=0;i<n;i++)
//     cout << a[i]<< " ";
//
//   return 0;
// }

int main(){
  int a[100], n,k,d,i;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> k;
    a[i] = k;
  }
  rotate(a,3,n);
  for(i=0;i<n;i++)
    cout << a[i] << " ";

  return 0;
}
