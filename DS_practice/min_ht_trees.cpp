#include<iostream>
using namespace std;
#include "/Users/yahnit/Documents/stdc++.h"

int height[10000];

void dfs(int node, bool visited[], list <int>adj[]){
  visited[node] = true;

  for(auto i=adj[node].begin(); i!=adj[node].end();++i){
    if(!visited[*i]){
      height[*i] = height[node]+1;
      dfs(*i,visited,adj);
    }
  }
  return;
}

int main(){
  int n,m,i;
  cin >> n >> m;

  list <int> adj[n+1];

  bool visited[n+1];
  for(i=1;i<=n;i++)
    visited[i] = false;

  int x,y;
  for(i=0;i<m;i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(i=1;i<=n;i++)
    height[i] = 0;

  // for(i=1;i<=n;i++)
  //   if(visited[i] == false){
  //     dfs(i,visited,adj);
  //   }

  dfs(3,visited,adj);

  int max = 0;
  for(i=1;i<=n;i++)
    if(max < height[i])
      max = height[i];

  cout << max << endl;

  return 0;
}
