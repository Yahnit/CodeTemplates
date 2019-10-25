#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;

typedef struct node{
  int u,v,w;
}Node;

typedef struct vert{
  int parent, rank;
}Vert;

bool compare(Node a, Node b){
  return (a.w < b.w);
}

int find_parent(int v, Vert subsets[]){
  if(subsets[v].parent != v)
    subsets[v].parent = find_parent(subsets[v].parent,subsets);

  return subsets[v].parent;
}

void Union(int x, int y, Vert subsets[]){
  int parx = find_parent(x, subsets);
  int pary = find_parent(y, subsets);

  if(subsets[parx].rank < subsets[pary].rank){
    subsets[parx].parent = pary;
    subsets[pary].rank += 1;
  }
  else{
    subsets[pary].parent = parx;
    subsets[parx].rank += 1;
  }

  return;
}

void kruskal(Node graph[], int n, int m){

  Vert subsets[10000];
  for(int i=0;i<n;i++){
    subsets[i].parent = i;
    subsets[i].rank = 0;
  }

  vector<int> edges;
  int u,v,w;
  for(int i=0;i<m;i++){
    u = graph[i].u;
    v = graph[i].v;
    w = graph[i].w;

    int par_u = find_parent(u, subsets);
    int par_v = find_parent(v, subsets);

    if(par_u != par_v){
      Union(u,v,subsets);
      edges.push_back(i);
    }
    
  if(edges.size() == n-1)
    break;
  }
  return;
}

int main(){
  int n,m,i;
  cin >> n >> m;
  Node graph[10000];

  for(i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    graph[i].u = u;
    graph[i].v = v;
    graph[i].w = w;
  }
  sort(graph,graph+m,compare);

  kruskal(graph,n,m);

  return 0;
}
