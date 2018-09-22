#include<iostream>
using namespace std;
#include<list>

void dfs(int node, bool visited[], list <int>adj[]){
  visited[node] = true;
  cout << node << " ";

  for(auto i=adj[node].begin(); i!=adj[node].end();++i){
    if(!visited[*i])
      dfs(*i,visited,adj);
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
    if(visited[i] == false)
      dfs(i,visited,adj)

  return 0;
}
