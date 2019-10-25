#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

int longestValidParentheses(string s) {
  vector <char> stack;

  int len = s.size(), max = 0,temp_max = 0;

  for(int i=0;i<len;i++){
    if(s[i] == '('){
      if(stack.size() > 0)
        stack.push_back('(');
      else{
        if(max>temp_max)
          max = temp_max;
          temp_max = 0;
      }
    }


    if(s[i] == ')'){
      if(stack.size() > 0){
        char top = stack[stack.size()-1];
        stack.pop_back();
        if(top == '(')
          temp_max+=2;
      }
      else
        if(max<temp_max)
          max = temp_max,temp_max = 0;
    }
  }
  if(temp_max > max)
    max = temp_max;

return max;
}

int main(){
  string a;
  cin >> a;

  cout << longestValidParentheses(a) << endl;

  return 0;
}
