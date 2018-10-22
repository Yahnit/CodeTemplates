#include<iostream>
using namespace std;

int dp[100][100] = {-1};

int maxsum_subarray(int a[], int low, int high){
  if(dp[low][high] != -1)
    return dp[low][high];

  if(low>high)
    return 0;

  if(low == high)
    return a[low];

  dp[low][high] = max(max(maxsum_subarray(a,low,high-1), maxsum_subarray(a,low,high-1) + a[high]), max(maxsum_subarray(a,low+1,high), maxsum_subarray(a,low+1,high) + a[low]));

  return dp[low][high];
}


int main(){
  int n,sum,i,a[10000];
  cin >> n >> sum;

  for(i=0;i<n;i++)
    cin >> a[i];

  cout << maxsum_subarray(a,0,n-1) << endl;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cout << dp[i][j] << " ";
    cout << "\n";

  return 0;
}
