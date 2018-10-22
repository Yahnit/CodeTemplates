#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;

typedef struct node{
  int u,v,w;
}Node;

bool compare(Node a, Node b){
  return (a.w < b.w);
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

  return 0;
}
