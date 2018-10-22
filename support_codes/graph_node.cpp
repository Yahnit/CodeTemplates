#include<iostream>
#include "/Users/yahnit/Documents/stdc++.h"
using namespace std;

typedef struct node{
  int val;
  node * right;
  node * left;
}Node;

Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  temp->val = val;
  temp->left = NULL,temp->right = NULL;
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

    if (val < root->key)
        root->left  = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


int main(){
  Node * root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->right = createNode(4);
  root->right->left = createNode(5);


  return 0;
}
