#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include "/Users/yahnit/Documents/stdc++.h"

/*
Some probs to be solved using dfs
1) farthest node from a particular node
2) given a directed graph, find the longest path between any 2 nodes
*/

void dfs(int node, bool visited[], list <int>adj[]){
  visited[node] = true;
  cout << node << " ";

  for(auto i=adj[node].begin(); i!=adj[node].end();++i){
    if(!visited[*i])
      dfs(*i,visited,adj);
  }
  return;
}

// int checkCyclic(int node, list <int>adj[]){
//   color[node] = 'GREY';
//
//   for(auto i=adj[node].begin(); i!=adj[node].end();++i){
//       if(color[*i] == 'GREY')
//         return 1;
//
//       if(color[*i] == 'WHITE')
//         if(recheckCyclic(*i, adj))
//           return 1;
//       }
//
//   color[node] = 'BLACK';
//   return 0;
// }

void topoSort(int v, int visited[], vector<int> stack, list <int>adj[]){
  visited[v] = true;

  for(auto i=adj[v].begin(); i!=adj[v].end();++i){
    if(!visited[*i])
      topoSort(*i, visited, stack, adj);
  }
  stack.push_back(v);

  return;
}

int bipartite(int v, bool visited[], int color[], list <int>adj[], int colr){
  visited[v] = true;
  color[v] = colr;

  for(auto i=adj[v].begin(); i!=adj[v].end();++i){
    if(!visited[*i]){
      if(!bipartite(*i, visited, color,adj,1-color[v]))
        return 0;

      else{
      if(color[*i] == color[v])
        return 0;
      }
    }

  }
return 1;
}
int MAX = INT_MIN, MAX_NODE;
int farthest_node(int v, bool visited[], int dist, list <int>adj[]){
  visited[v] = true;
  dist = dist + 1;
  for(auto i=adj[v].begin(); i!=adj[v].end();++i){
    if(!visited[*i]){
      if(dist > MAX){
        MAX = dist;
        MAX_NODE = *i;
      }
      farthest_node(*i, visited, dist, adj);
    }
  return ;
}

int main(){
  int n,m,i;
  // cin >> n >> m;

  n = 6, m = 6;
  int s_x[] = {1,2,3,4,5,6};
  int s_y[] = {2,3,4,5,6,1};

  list <int> adj[n+1];

  bool visited[n+1];
  for(i=1;i<=n;i++)
    visited[i] = false;

  int x,y;
  for(i=0;i<m;i++){
    // cin >> x >> y;
    x = s_x[i], y = s_y[i];
    adj[x].push_back(y);
    // adj[y].push_back(x);
  }
  int color[100] = {-1};
  for(i=1;i<=n;i++)
    if(visited[i] == false){
      // dfs(i,visited,adj);
      if(!bipartite(1, visited,color, adj,0)){
        cout << "NOT BIPARTITE" << endl;
        return 0;
      }
    }
    cout << "BIPARTITE" << endl;
  return 0;
}
