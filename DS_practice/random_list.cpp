#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

int main(){
  int a[1000],n,i,m;
  cin >> n >> m;
  for(i=0;i<n;i++)
    cin >> a[i];

  set <int> st;

  int count = 0;
  while(st.size()<=m){
    int temp = rand()%m;
      st.insert(temp);
      cout << temp;
  }
  for(auto j=st.begin(); j!=st.end();++j){
    cout << *j << endl;
  }

  return 0;
}
