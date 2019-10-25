#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

int main(){

  string a, temp_str;
  cin >> a;

  vector <string> words;

  int n, len = a.size();
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> temp_str;
    words.push_back(temp_str);
  }

  vector <int> ans;
  int res = 1;

  int word_len = words[0].size();
  for(int i=0;i<len-n*word_len+1;i++){
    res = 1;
    string check_str = a.substr(i, n*word_len);
    for(int j=0;j<n;j++){
      if(check_str.find(words[j]) == string::npos){
        res = 0;
        break;
      }
    }
    if(res == 1)
      ans.push_back(i);
  }

  for(int i=0;i<ans.size();i++)
    cout << ans[i] << ' ';

  return 0;
}
