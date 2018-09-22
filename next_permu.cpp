#include<iostream>
using namespace std;
#include<string>
#include<algorithm>


int main(){
  string str;
  cin >> str;
  int len = str.size(),ind;

  for(int i=len-1;i>0;i--){
    if(str[i] > str[i-1]){
      int min = 1000000;
      for(int j=i;j<len-1;j++){
        if(str[j] > str[i-1] && str[j] < min)
          min = str[j];
          ind = j;
      }
      swap(str[i-1],str[ind]);
      sort(str.begin()+i,str.begin()+len);
      break;
    }
  }
  cout << str << endl;
  return 0;
}
