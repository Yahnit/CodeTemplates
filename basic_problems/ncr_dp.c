#include<stdio.h>

long long int BinCoefficient(long long int dp[][1001], long long int n, long long int r, long long int m){
  if(dp[n][r] != -1)
    return dp[n][r];

  if(dp[n][n-r] != -1)
    return dp[n][n-r];

  if(n < r){
    dp[n][r] = 0;
    return 0;
  }

  if(r == 0){
    dp[n][r] = 1%m;
    return 1%m;
  }

  if(r == 1){
    dp[n][r] = n%m;
    dp[n][n-r] = dp[n][r];
    return n%m;
  }


  dp[n-1][r] = BinCoefficient(dp, n-1, r, m);
  dp[n-1][r-1] = BinCoefficient(dp, n-1, r-1, m);

  dp[n][r] = (dp[n-1][r]%m + dp[n-1][r-1]%m)%m;
  if(n-r >= 0)
    dp[n][n-r] = dp[n][r];

  return dp[n][r]%m;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    long long int n, r , m;
    scanf("%lld%lld%lld", &n, &r, &m);

    long long int dp[1001][1001];
    for(long long int i=0;i<=n;i++)
      for(long long int j=0;j<=n;j++)
        dp[i][j] = -1;

    long long int ans = BinCoefficient(dp, n, r, m);
    printf("%lld\n", ans);
  }
return 0;
}
