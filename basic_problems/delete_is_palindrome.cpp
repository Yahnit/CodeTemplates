#include<iostream>
using namespace std;
#include<string>

int dp[10000][10000];

int palindrome(string str, int low, int high){
  if(dp[low][high]!= -1)
    return dp[low][high];

  if(low>high)
    return 0;

  if(low == high)
      return 1;

  if(str[low] == str[high]){
    dp[low+1][high-1] = palindrome(str,low+1,high-1);
    dp[low][high] = 2 + dp[low+1][high-1];
    }
  else{
      dp[low+1][high] = palindrome(str,low+1,high);
      dp[low][high-1] = palindrome(str,low,high-1);
      dp[low][high] = max(dp[low+1][high],dp[low][high-1]);
  }
  return dp[low][high];
}

int main(){
  string str;
  int k;
  cin >> str >> k;
  int n = str.size();

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      dp[i][j] = -1;

  int max_length = palindrome(str,0,n-1);
  if(max_length < n-k)
    cout << "No, Its not Possinble :(\n";
  else
    cout << "YEAYEAYEAY :D\n";

  // cout << max_length << endl;
  return 0;
}
