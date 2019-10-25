typedef struct node{
  int parent, rank;
}Node;

int find_parent(int v, Node subsets[]){
  if(subsets[v].parent != v)
    subsets[v].parent = find_parent(subsets[v].parent,subsets);

  return subsets[v].parent;
}

void Union(int x, int y, Node subsets[]){
  int parx = find_parent(x, subsets);
  int pary = find_parent(y, subsets);

  if(subsets[parx].rank < subsets[pary].rank){
    subsets[parx].parent = pary;
    subsets[pary].rank += 1;
  }
  else{
    subsets[pary].parent = parx;
    subsets[parx].rank += 1;
  }

  return;
}
