// #include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
#include<string>
using namespace std;

int substrng(string a, string b){
  if(b.find(a) == string::npos)
    return -1;

  int ind;
  for(int i=0;i<b.size();i++){
    if(b.substr(i,a.size()) == a){
      ind = i;
      break;
    }
  }

  for(int j=ind+a.size()+1;j<b.size() && j!=ind;j=(j+1)%b.size()){
    if
  }

  return ind;
}


int main(){
  string a,b,temp;
  int m,n,ans = 0;

  cin >> a >> b;
  temp = a;
  m = a.size();
  n = b.size();

  // for(int i=1;i<1000;i++){
  //   if(temp.find(b) == string::npos){
  //     temp = temp.append(a);
  //     // continue;
  //   }
  //   else{
  //     cout << i << endl;
  //     break;
  //   }
  // }

 cout << substrng(a, b) << endl;

  return 0;
}
