#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

int main(){
  int arr[1000], n ,i;
  cin >> n;

  map<int,int> m;

for(i=0;i<n;i++){
  cin >> arr[i];
  m[arr[i]] = i;
}

int maxm = -100000;
for(i=1;i<n;i++){
  maxm = max(maxm,i-m[arr[i]-1]);
}
cout << maxm;

  return 0;
}
