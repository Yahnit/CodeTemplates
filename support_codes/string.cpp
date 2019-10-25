#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;

void erase(){
  // deletes 'len' characters after index 'ind'
  string str = "Hiiiiiiii! Iam Yahnit Sirineni";
  int ind = 2, len = 7;

  str.erase(ind, len);
  cout << str << endl;

  // deletes all the characters after index 'ind'
  ind = 25;
  str.erase(ind);
  cout << str << endl;

return;
}

void substring(){
  string s1 = "Hello! How are you?", s2 = "are";

  // IF a string is a substring of other
  if (s1.find(s2) != string::npos)
    cout << "found!" << '\n';

    // returns a string from 4th place with a length of 10
  string s3 = s1.substr(4 , 10);
  cout << s3 << endl;


  // string addition
  string s4 = "Hi!";
  string s5 = " Iam Yahnit Sirineni";
  cout << s4+s5 << endl;

  return;
}

void UpperLowerCase(){
  string s = "hello";
  cout << (char)toupper(s[0]);
  cout << (char)tolower(s[0]);


  return;
}

int main()
{
    // erase();
    substring();

  return 0;
}
