// #include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;
#include<list>

list <int> queue;
int dist[10000];
list <int> adj[10000];
bool visited[10000];


int bfs(int node, int n, int k){
  visited[node] = true;
  dist[node] = 0;
  queue.push_back(node);

  while(!(queue.empty())){
    int top = queue.front();
    queue.pop_front();
    cout << top << " ";

    for(auto i=adj[top].begin(); i!=adj[top].end();++i){
      if(!visited[*i]){
        visited[*i] = true;
        dist[*i] = dist[top] + 1;
        queue.push_back(*i);
      }
    }
  }
  int count = 0;
  for(int i=1;i<=n;i++)
    if(dist[i]<=k){
      count++;
      cout << i << " ";
    }

  return count;
}

int main(){
  int n,m,i,k;
  cin >> n >> m >> k;

  for(i=1;i<=n;i++){
    visited[i] = false;
    dist[i] = 1000000;
  }

  int x,y;
  for(i=0;i<m;i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // for(i=1;i<=n;i++)
  //   if(visited[i] == false)
  //     bfs(i,visited,adj);

    bfs(1,n,k);


  return 0;
}
