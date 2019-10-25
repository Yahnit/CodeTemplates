#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

int main(){
  int n,i,a[1000], ind[1000];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  for(i=0;i<n;i++)
    cin >> ind[i];

  i=0;

  while(i<n){
    while(ind[i]!=i){
      swap(a[i], a[ind[i]]);
      swap(ind[i],ind[ind[i]]);
    }
    i++;
  }

  for(i=0;i<n;i++)
    cout << a[i] << ' ';

  return 0;
}
