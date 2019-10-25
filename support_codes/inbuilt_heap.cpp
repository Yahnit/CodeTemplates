#include<iostream>
using namespace std;
#include "/Users/yahnit/Documents/stdc++.h"

typedef struct node{
  int x,y;
}Node;

class mycompare
{
public:
    int operator() (const Node& p1, const Node& p2)
    {
        return p1.y > p2.y;
    }
};

int main(){
  int n,a[10000], i;
  Node points[1000];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    points[i].x = i;
    points[i].y = a[i];
  }

  // MAX HEAP
  // priority_queue<int> pq;
  // MIN HEAP
  // priority_queue<int, vector<int>, greater<int> > pq;
  //
  //
  // for(i=0;i<n;i++)
  //   pq.push(a[i]);
  //
  //   cout << pq.size() << endl;
  //   cout << pq.top() << endl;
  //   pq.pop();
  //


  priority_queue<Node, vector<Node>, mycompare> pq;
  // priority_queue<int, vector<int>, greater<int> > pq;
  for(i=0;i<n;i++)
    pq.push(points[i]);

      cout << pq.size() << endl;
      cout << pq.top().x << endl;
      pq.pop();

      cout << "------------\n";

      cout << pq.size() << endl;
      cout << pq.top().x << endl;
      pq.pop();



return 0;
}
