#include<iostream>
using namespace std;
// #include<bits/stdc++.h>
#include "/Users/yahnit/Documents/stdc++.h"
int visited[200009];
int level[200009];

int bfs(int n){

    // int visited[20009], level[20009];
    for(int i=0;i<n;i++){
        visited[i] = 0;
        level[i] = 0;
    }

    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!(q.empty())){
        int top = q.front();
        q.pop();

        if(top == n){
            return level[top];
        }

        int nbr1 = 2*top;
        if(!visited[nbr1]){
            visited[nbr1] = true;
            q.push(nbr1);
            level[nbr1] = level[top] + 1;
        }

        int nbr2 = top + 1;
        if(!visited[nbr2]){
            visited[nbr2] = true;
            q.push(nbr2);
            level[nbr2] = level[top] + 1;
        }
    }
    return 0;
}

int main()
 {
    int t = 3;
    // cin >> t;
    while(t--){
        int a = 10000;
        // cin >> a;
        int ans = bfs(a);
        cout << ans << endl;
    }
	return 0;
}
