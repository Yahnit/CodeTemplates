#include<iostream>
using namespace std;
#include<vector>
#include<stack>

stack <int> stck;

void topoSort(int n, bool visited[], vector<int> adj[]){
  visited[n] = true;

  for(auto i= adj[n].begin(); i!=adj[n].end();++i){
    if(!visited[*i])
      topoSort(*i, visited, adj);
  }

  stck.push(n);
  return;
}

int main(){
  int n, m;
  cin >> n >> m;
  bool visited[1001];
  vector <int> adj[1001];

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    // adj[b].push_back(a);
  }

  for(int i=0;i<n;i++){
    if(!visited[i]){
      topoSort(i, visited, adj);
    }
  }

  while(!stck.empty()){
    cout << stck.top() << " ";
    stck.pop();
  }
  return 0;
}
