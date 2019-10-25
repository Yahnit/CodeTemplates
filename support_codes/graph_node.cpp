#include<iostream>
// #include "/Users/yahnit/Documents/stdc++.h"
using namespace std;

int MAX = 100000000;

typedef struct node{
  int val,key;
  node * right;
  node * left;
}Node;

typedef struct node1{
  int val,key;
  node1 * right;
  node1 * left;
  int root_sum, non_root_sum;
}Node1;

Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  temp->val = val;
  temp->left = NULL,temp->right = NULL;
  return temp;
}

Node1 * createNode1(int val){
  Node1 * temp = (Node1 *)malloc(sizeof(Node1));
  temp->val = val;
  temp->left = NULL,temp->right = NULL;
  temp->root_sum = 0, temp->non_root_sum = 0;
  return temp;
}

Node * LCA(Node * root, int x, int y){
  if(root == NULL)
      return NULL;

  if(root->val == x || root->val == y)
    return root;

  Node * left_lca = LCA(root->left,x,y);
  Node * right_lca = LCA(root->right,x,y);

  if(left_lca && right_lca)
    return root;

  return (left_lca!=NULL)?  left_lca : right_lca;
}

// BINARY SEARCH TREE INSERT
Node * insert(Node* root, int val)
{
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left  = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

Node * search(Node* root, int val){
  if(root == NULL)
    return NULL;

  if(root->val == val)
    return root;

  Node * left_tree = search(root->left, val);
  Node * right_tree = search(root->right, val);

  if(left_tree)
    return left_tree;

  if(right_tree)
    return right_tree;

  return NULL;
}

int find_nearest_leaf(Node * root, int near){
  if(root == NULL)
    return near;

  int left_tree = find_nearest_leaf(root->left, near+1);
  int right_tree = find_nearest_leaf(root->right, near+1);

  return min(left_tree, right_tree);
}

int sum_k_distance_nodes(Node1 * root, int k){
  if(root == NULL)
    return 0;

  if(k == 0)
    return root->val;

  int left_tree = sum_k_distance_nodes(root->left, k-1);
  int right_tree = sum_k_distance_nodes(root->right, k-1);

return left_tree + right_tree + root->val;
}

int find_upper_bound(Node1 * root, int val){
  if(root == NULL)
    return MAX;

  int left_tree = find_upper_bound(root->left, val);
  int right_tree = find_upper_bound(root->right, val);

  if(root->val >= val)
    return min(min(left_tree, right_tree), root->val);

  return min(left_tree, right_tree);
}

int find_max_sum_path(Node1* root){
  if(root == NULL)
    return 0;

  // if(!root->right && !root->left){
  //   root->root_sum = root->val;
  //   root->non_root_sum = root->val;
  // }

  root->root_sum = root->val + find_max_sum_path(root->right) + find_max_sum_path(root->left);
  root->non_root_sum = root->val + max(find_max_sum_path(root->right),find_max_sum_path(root->left));

  return root->non_root_sum;
}

int find_max_val(Node1 * root){
  if(root == NULL)
    return 0;

  int child_max = max(find_max_val(root->right), find_max_val(root->left));
  int node_max = max(root->root_sum, root->non_root_sum);

  return max(child_max , node_max);
}

int find_diameter(Node1* root){
  if(root == NULL)
    return -1;

  int right = find_diameter(root->right);
  int left = find_diameter(root->left);
  root->root_path = 2 + right + left;
  root -> nonroot_path = 1 + max(right, left);

  return root->nonroot_path;
}

int main(){
  Node1 * root = createNode1(1);
  root->left = createNode1(2);
  root->right = createNode1(3);
  root->left->right = createNode1(9);
  root->right->left = createNode1(5);

  // Node * pivot = search(root,6);
  // cout << find_upper_bound(root,4) << endl;


  // sets the root sum and non_root_sum of all the nodes
  find_max_sum_path(root);
  // now return the max val
  int ans = find_max_val(root);

  // int ans = sum_k_distance_nodes(root,1);
  cout << ans << endl;
  return 0;
}
