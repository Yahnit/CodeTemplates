#include<iostream>
using namespace std;

int main(){

  int n, a[10001];
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> a[i];
  int ele;
  cin >> ele;
  cout << lower_bound(a, a+n, ele) - a << endl;

  return 0;
}
