int topoSort(int n, bool visited[], vector<int> adj[]){
  visited[n] = true;

}

int TopoSort(){
  int n, m;
  bool visited[n+1];
  vector<int> adj[n+1];
  stack<int> stck;

  for(int i=0;i<n;i++){
    if(!visited[i]){
      topoSort(i, visited, adj);
    }
  }
  return;
}
