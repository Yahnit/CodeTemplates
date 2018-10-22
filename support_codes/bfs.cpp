#include<iostream>
using namespace std;
#include<list>

list <int> queue;

void bfs(int node, bool visited[], list <int>adj[]){
  visited[node] = true;
  queue.push_back(node);

  while(!(queue.empty())){
    int top = queue.front();
    queue.pop_front();
    cout << top << " ";

    for(auto i=adj[top].begin(); i!=adj[top].end();++i){
      if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
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
    if(visited[i] == false)
      bfs(i,visited,adj);

  return 0;
}
