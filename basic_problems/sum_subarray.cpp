#include<iostream>
using namespace std;
#include "/Users/yahnit/Documents/stdc++.h"

int max_sum_subarray(int a[], int n, int dp[]){
  if(dp[n] != -1)
    return dp[n];

  if(n == 0)
    return a[n];

  dp[n-1] = max_sum_subarray(a, n-1, dp);
  dp[n] = max(dp[n-1]+a[n], a[n]);

  return dp[n];
}

int min_sum_subarray(int a[], int n, int dp[]){
  if(dp[n] != -1)
    return dp[n];

  if(n == 0)
    return a[n];

  dp[n-1] = min_sum_subarray(a, n-1, dp);
  dp[n] = min(dp[n-1]+a[n], a[n]);

  return dp[n];
}

// Counts the no.of ways to sum to 'SUM' using array elements with repetition allowed
int count_ways_sum(int a[], int sum, int n, int dp[][100]){
    if(sum < 0)
      return 0;

    if(dp[sum][n] != -1)
      return dp[sum][n];

    if(sum == 0)
      return 1;

    if(n <= 0)
      return 0;

    dp[sum][n-1] = count_ways_sum(a, sum, n-1, dp);
    dp[sum-a[n-1]][n] = count_ways_sum(a, sum-a[n-1], n, dp);
    dp[sum][n] = dp[sum][n-1] + dp[sum-a[n-1]][n];


  return dp[sum][n];
}

int count_ways_sum1(int a[], int sum, int n, int dp[]){
    if(sum < 0)
      return 0;

    if(dp[sum] != -1)
      return dp[sum];

    if(sum == 0)
      return 1;

    dp[sum] = 0;
    for(int i=0;i<n;i++){
      dp[sum - a[i]] = count_ways_sum1(a, sum - a[i], n, dp);
      dp[sum] += dp[sum - a[i]];
    }

  return dp[sum];
}



int main(){
  int n,sum,i,a[10000];
  int dp[10000];
  // int dp[100][100];
  cin >> n;

  for(i=0;i<n;i++)
    cin >> a[i];

    for(int i=0;i<=14;i++)
      for(int j=0;j<=n;j++)
        dp[i] = -1;

    // max_sum_subarray(a, n-1, dp);
    // min_sum_subarray(a, n-1, dp);
    // cout << count_ways_sum(a, 7, n, dp) << endl;
    cout << count_ways_sum1(a, 5, n, dp) << endl;

  // int max = INT_MIN;
  // int min = INT_MAX;
  // for(int i=0;i<n;i++){
  //   if(max < dp[i])
  //     max = dp[i];
  //   if(min > dp[i])
  //     min = dp[i];
  //   }
  //
  //
  //   // cout << max << endl;
  //   cout << min << endl;
  return 0;
}
