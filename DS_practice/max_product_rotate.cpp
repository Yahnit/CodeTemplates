#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<cmath>

int main(){
  int a[100], n ,i, sum=0;
  int ans[100] = {0};

  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }

  for(i=0;i<n;i++)
    ans[0] += i*a[i];

  for(int k=1;k<n;k++)
    ans[k] = ans[k-1] + sum - n*a[n-k];

  int max = 0;
  for(i=0;i<n;i++){
    if(ans[i] > max)
      max = ans[i];
  }
  cout << max << endl;

  return 0;
}
