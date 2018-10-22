#include<iostream>
using namespace std;

int main(){
    int a[10000],n,i;
    cin >> n;
    for(i=0;i<n;i++)
      cin >> a[i];

    int temp = 0;
    for(i=0;i<n;i++){
      if(a[i]!=0){
        a[temp++] = a[i];
      }
    }
    for(i=temp;i<n;i++){
      a[i] = 0;
    }

    for(i=0;i<n;i++)
      cout << a[i];
  return 0;
}
