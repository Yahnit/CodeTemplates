#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;


int main(){
  int n,x,i,a[100];
  cin >> n >> x;
  map<int ,int> mp;

  for(i=0;i<n;i++)
    cin >> a[i];

  for(i=0;i<n;i++){
    if(mp[x-a[i]] == 1){
      cout << "YEAYYYY!" << endl;
      break;
    }
    else
      mp[a[i]] = 1;
  }

  return 0;
}
