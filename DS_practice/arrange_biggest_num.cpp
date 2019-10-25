#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

bool compare(string a , string b){
  if(a.append(b) > b.append(a))
    return true;

    return false;
}

int main(){

  int i,n,a[10000];
  cin >> n;
  vector<string> vect;

  for(i=0;i<n;i++){
    cin >> a[i];
    vect.push_back(to_string(a[i]));
  }

  sort(vect.begin(),vect.end(),compare);
  for(i=0;i<n;i++)
    cout << vect[i];

    cout << endl;

  return 0;
}
