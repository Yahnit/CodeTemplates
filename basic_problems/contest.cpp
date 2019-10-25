#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int MOD = 1000000007;

void dfs(long long int v, long long int visited[], long long int dist[], vector<long long int> adj[], long long int len){
    visited[v] = 1;

    if(len%2)
        dist[v] = (dist[v]+1)%MOD;

    long long int cur_len = (len + 1)%MOD;
    for(auto i=adj[v].begin(); i!=adj[v].end();++i)
        if(!visited[*i])
            dfs(*i, visited, dist, adj, cur_len);

    visited[v] = 0;
return;
}


using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long int output to STDOUT */
    long long int t;
    cin >> t;
    while(t--){
        long long int n,m,x, u, v;
        vector<long long int> adj[100009];
        long long int dist[100009];
        cin >> n >> m >> x;
        for(long long int i=0;i<m;i++){
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int visited[100009];

        for(int i=1;i<=n;i++){
            visited[i] = 0;
            dist[i] = 0;
        }

        dfs(x, visited, dist, adj, 0);

        for(int i=1;i<=n;i++)
            cout << dist[i]%MOD << " ";
        cout << endl;
    }
    return 0;
}
