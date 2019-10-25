#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;
#include<string>


#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int subsetSum(map<pair<int, int>, int>hash, int a[], int n, int sum_diff){
    if(hash[make_pair(n, sum_diff)])
        return hash[make_pair(n, sum_diff)];

    if(n == 0 && sum_diff != 0){
        hash[make_pair(n, sum_diff)] = 0;
        return 0;
    }

    if(n == 0 && sum_diff == 0){
        hash[make_pair(n, sum_diff)] = 1;
        return 1;
    }

    int res = 0;

    pair<int, int> pair1 = make_pair(n-1, sum_diff+a[n-1]);
    hash[pair1] = subsetSum(hash, a, n-1, sum_diff+a[n-1]);
    res = res || hash[pair1];

    pair<int, int> pair2 = make_pair(n-1, sum_diff-a[n-1]);
    hash[pair2] = subsetSum(hash, a, n-1, sum_diff-a[n-1]);
    res = res || hash[pair2];

    pair<int, int> pair3 = make_pair(n, sum_diff);
    hash[pair3] = res;

    return hash[pair3];
}



int main(){

  map<int, int> mp;
  mp[1] = 2,mp[2] = 3, mp[3] = 4;
  for(auto i=mp.begin();i!=mp.end();++i)
    cout << i->first << " " << mp[i->first] << endl;

  map<string, int> hash;
  hash["Hello"] = 1;
  hash["Hey"] = 2;
  hash["Hi"] = 3;
  hash["Heya"] = 4;
  cout << hash["Hi"] << endl;

  return 0;
}
