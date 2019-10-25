#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

int main(){
  vector <char> stack;
  string str;
  cin >> str;

  int i = 0,ans = 1;
  for(i=0;i<str.size();i++){
    if(str[i] == '{' || str[i] == '[' || str[i] == '(')
      stack.push_back(str[i]);

    else{
      char top = stack[stack.size()-1];
      stack.pop_back();
      if(top != '{' && str[i] == '}')
        ans = 0;
      if(top != '[' && str[i] == ']')
        ans = 0;
      if(top != '(' && str[i] == ')')
        ans = 0;
      if(ans == 0)
        break;
    }
  }

  if(ans == 1)
    cout << "YEAYEYA" << endl;
  else
    cout << "NAHEE" << endl;

  return 0;
}
