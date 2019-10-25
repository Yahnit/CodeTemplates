#include<iostream>
using namespace std;
#include "/Users/yahnit/Documents/stdc++.h"

map <string, vector<string> > adj;
vector <string> res;

string find_min_lex(string str){
  vector <string> adj_list = adj[str];

  if(adj_list.size() <= 0)
    return "";

  string minm = adj_list[0];
  auto min_ind = adj_list.begin();

  for(auto i = adj_list.begin(); i!=adj_list.end(); ++i)
    if(*i < minm)
      minm = *i, min_ind = i;

    adj_list.erase(min_ind);
    adj[str] = adj_list;

return minm;
}

vector<string> findItinerary(vector<pair<string, string> > tickets) {
  for(int i=0;i<tickets.size();i++)
    adj[tickets[i].first].push_back(tickets[i].second);

  string src = "JFK";
  vector <string> res;
  res.push_back(src);

  while(src != ""){
    string next_dest = find_min_lex(src);
    if(next_dest != ""){
      res.push_back(next_dest);
      src = next_dest;
    }
    else
      src = "";
  }
return res;
}

int main(){
  int n,m,i;
  // cin >> n >> m;
  // string x,y;
  //
  // for(i=0;i<m;i++){
  //   cin >> x >> y;
  //   adj[x].push_back(y);
  // }
  //
  // string src = "jfk";
  // res.push_back(src);
  // while(src != ""){
  //   string next_dest = find_min_lex(src);
  //   if(next_dest != ""){
  //     res.push_back(next_dest);
  //     src = next_dest;
  //   }
  //   else
  //     src = "";
  // }
  //
  // for(int i=0;i<res.size();i++)
  //   cout << res[i] << " ";

  vector<pair<string, string> > tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]];
  // cin >> tickets;
  // cout << findItinerary(tickets) << endl;
  return 0;
}
