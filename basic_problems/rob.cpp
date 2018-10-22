#include<iostream>
using namespace std;

int maxMoney(int arr[], int size,int dp[]){
  if(dp[size]>0)
    return dp[size];
  if(size <= 0)
    return 0;
  if(size == 1)
    return arr[0];

  dp[size-1] = maxMoney(arr,size-1,dp);
  dp[size-2] = maxMoney(arr,size-2,dp);

  return max(dp[size-1], dp[size-2]+arr[size-1]);
}

int main(){
    int n, a[1000],i,dp[1000];
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(i=0;i<n;i++)
      cin >> a[i];

    int max_money = maxMoney(a,n,dp);

    cout << "Maximim money that can be robbed is " << max_money << endl;

  return 0;
}
