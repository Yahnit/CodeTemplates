#include "/Users/yahnit/Documents/stdc++.h"
#include<iostream>
using namespace std;

typedef struct node{
  int rating;
  string str;
}Node;

bool compare(Node a, Node b){
  return a.rating > b.rating;
}

int main(){
  int i,n;
  Node movies[1000];
  cin >> n;
  // cout << n << endl;

  for(i=0;i<n;i++){
    string st;
    cin >> st;
    movies[i].str = st;
    int ratn;
    cin >> ratn;
    movies[i].rating = ratn;
  }

  sort(movies,movies+n,compare);

  for(i=0;i<min(10,n);i++){
    cout << movies[i].str << endl;
  }

  return 0;
}
