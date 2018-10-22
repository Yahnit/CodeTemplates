#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;

int main(){

  map<int, int>map;
  map[1] = 2,map[2] = 3, map[3] = 4;
  for(auto i=map.begin();i!=map.end();++i)
    cout << i->first << " " << map[i->first] << endl;

  return 0;
}
