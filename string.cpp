#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;
#include<string>


// int main(){
//   vector <int> vect;
//   int n,a;
//   cin >> n;
//   for(int i=0;i<n;i++){
//     cin >> a;
//     vect.push_back(a);
//   }
//
//   for(int i=0;i<n;i++)
//     cout << vect[i] << endl;
//
//   return 0;
// }

int main()
{
     vector <string> vect = {"geekf", "geeks", "or", "keeg", "abc", "bc"};
     vector<int> vec = {1,2,3,4,5};

       for(int i=0;i<vect.size()-1;i++)
         cout << vect[i].substr(0,1) + vect[i+1].substr(1,2) << endl;

        for(vector<int>::iterator i=vec.begin();i!=vec.end();++i)
          cout << *i << endl;

    return 0;
}

// int main(){
//   string str = "45";
//   int x = stoi(str);
//
//   cout << x;
//   return 0;
// }

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
