#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;
#include <cstdlib>


int isPalindrome(string a){
  for(int i=0;i<a.size()/2;i++)
    if(a[i] != a[a.size()-i-1])
      return 0;

  return 1;
}

int max_palindrome_substring(string a){
  int n = a.size(); 
  int dp[1000][1000] = {0};

  for(int i=0;i<n;i++)
    dp[i][i] = 1;

  for(int i=0;i<n-1;i++)
    if(a[i] == a[i+1])
      dp[i][i+1] = 1;

  int ans = 1;

  for(int k=3;k<=n;k++){
    for(int i=0;i<n-k+1;i++){
      int j = i+k-1;
      if(dp[i+1][j-1] == 1 && a[i] == a[j]){
        dp[i][j] = 1;
        if(j-i>ans)
          ans = j-i;
      }
    }
  }

return ans+1;
}

int max_palindrome_subseq(int dp[][1000], string a, int low, int high){
  if(dp[low][high] != -1)
    return dp[low][high];

  if(low>high)
    return 0;

  if(low == high)
    return 1;

  if(a[low] == a[high]){
    dp[low+1][high-1] = max_palindrome_subseq(dp, a, low+1, high-1);
    return 2+dp[low+1][high-1];
  }

  dp[low][high-1] = max_palindrome_subseq(dp, a, low, high-1);
  dp[low+1][high] = max_palindrome_subseq(dp, a, low+1, high);

  dp[low][high] = max(dp[low][high-1], dp[low+1][high]);
 return dp[low][high];
}


// COUNT AND SAY
string next_pattern(string a){
  string res = "";

  int len = a.size();
  for(int i=0;i<len;i++){
    char current = a[i];
    int count = 0;
    while(a[i]==current)
      i++,count++;

    // res.append(to_string(count));
    res += to_string(count);
    res += a[i-1];

    i--;
  }

return res;
}

int main(){
  string a;
  cin >> a;
  int ans = 0;

  int len = a.size();
  int dp[1000][1000] = {0};

  // for(int j=len;j>=1;j--)
  //   for(int i=0; i+j<=len ;i++)
  //     if(isPalindrome(a.substr(i,j))){
  //       cout << a.substr(i,j)<< endl;
  //       return 0;
  //   }
  //
  // cout << "No Palindrome exists" << endl;

  // for(int i=0;i<len;i++)
  //   dp[i][i] = 1;

  // cout << dp[2][3] << endl;
  for(int i=0;i<len;i++)
    for(int j=0;j<len;j++)
      dp[i][j] = -1;

  // cout << max_palindrome_subseq(dp, a,0,len-1) << endl;
  cout << next_pattern(a) << endl;
  return 0;
}
