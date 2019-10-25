#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

map <string, vector<pair<string,double> > > adj;
vector <double> res;

double dfs(string strt, string dest, map<string, bool> visited){
  if(strt == dest)
    return 1.0;

  visited[strt] = true;

  double found = 0.0;
  for(int i=0;i<adj[strt].size();i++){
    if(visited.find(adj[strt][i].first) == visited.end()){
      found = dfs(adj[strt][i].first, dest, visited);
      if(found>0.0){
        cout << found*adj[strt][i].second << endl;
        return found*adj[strt][i].second;
      }
    }
  }
  return -1.0;
}

vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
  for(int i=0;i<equations.size();i++){
    pair<string,double> pair1 = make_pair(equations[i].second, values[i]);
    pair<string,double> pair2 = make_pair(equations[i].first, 1.0/values[i]);
    adj[equations[i].first].push_back(pair1);
    adj[equations[i].second].push_back(pair2);
  }

  for(int i=0;i<queries.size();i++){
      string src = queries[i].first, dest = queries[i].second;
      map < string, bool> visited;

      // EITHER OF THE KEY IS NOT THERE IN THE GRAPH
      if(adj.find(src) == adj.end() || adj.find(dest) == adj.end())
        res.push_back(-1.0);

      else{
        double ans = dfs(src, dest, visited);
        res.push_back(ans);
      }
  }
return res;
}

int main(){
  vector<pair<string, string> > equations;
  vector<double> values;
  vector<pair<string, string> > queries;

  vector <double> res = calcEquation(equations, values, queries);
  for(int i=0;i<res.size();i++)
    cout << res[i] << " ";

  return 0;
}
