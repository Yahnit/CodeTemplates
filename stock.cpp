#include<iostream>
using namespace std;
#include<math.h>

int single_stock(int a[], int n){
  int min = INT_MAX;
  int max = 0;

  for(int i=0;i<n;i++){
    int min_ele = min(min,a[i]);
    int profit = a[i] - min;
    max = max(profit,max);
  }
  return max;
}

int main(){
  int n, a[1000],i,dp[1000];
  memset(dp,-1,sizeof(dp));
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];

}
