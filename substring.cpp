#include<iostream>
using namespace std;
#include<string.h>

int main(){
  string s1 = "Hello! How are you?", s2 = "Are";

// IF a string is a substring of other
  if (s1.find(s2) != string::npos) {
    std::cout << "found!" << '\n';
}
  else
    cout << "Not found" << '\n';

// SUBSTRING
  string s3 = s1.substr(3,6);
  cout << s3 << endl;
  return 0;
}
