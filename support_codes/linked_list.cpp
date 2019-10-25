#include<iostream>
using namespace std;
#include "/Users/yahnit/Documents/stdc++.h"

typedef struct node{
  int val;
  node * next;
}Node;

Node * createNode(int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  temp->val = val;
  temp->next = NULL;
  return temp;
}

void printList(Node * head){
  Node * cur = head;

  while(cur != NULL){
    cout << cur-> val << " ";
    cur = cur->next;
  }
  cout << "\n";
  return;
}

Node * swap(Node * head, int x, int y){
  Node * node1 = head, *prev1 = NULL;

  while(node1!=NULL){
    if(node1->val == x){
      break;
    }
    prev1 = node1;
    node1 = node1->next;
  }

  Node * node2 = head, *prev2 = NULL;

  while(node2!=NULL){
    if(node2->val == y){
      break;
    }
    prev2 = node2;
    node2 = node2->next;
  }

  if(node1->val != x || node2->val !=y){
    cout << "Elements not found" << endl;
    return head;
  }

  Node * temp = node1->next;
  node1->next = node2->next;
  node2->next = temp;

  if(prev1 == NULL){
    prev2->next = node1;
    head = node2;
  }

  if(prev2 == NULL){
    prev1->next = node2;
    head = node1;
  }

  if(prev1 != NULL && prev2 != NULL){
    prev1->next = node2;
    prev2->next = node1;
  }

return head;
}

Node * reverse(Node * head){
  Node * cur = head, *prev = NULL;
  Node * temp;
  while(cur != NULL){
    temp = cur->next;
    cur->next = prev;
    prev = cur;
    cur = temp;
  }
  head = prev;
  return head;
}

Node * insert(Node * head, int val){
  Node * temp = (Node *)malloc(sizeof(Node));
  temp->val = val;
  temp->next = NULL;

  Node * cur = head;

  while(cur!= NULL && cur->next!= NULL)
    cur = cur->next;

  if(!cur)
    head = temp;
  else
    cur->next = temp;

  return head;
}

Node * delete_node(Node* head, int val){
  Node * cur = head, *prev = NULL;

  while(cur!=NULL){
    if(cur->val == val)
      break;

    prev = cur;
    cur = cur->next;
  }
  if(!prev)
    head = cur->next;
  else
    prev->next = cur->next;
  free(cur);

  return head;
}

int main(){
  // Node * head = createNode(0);
    Node * head = NULL;
    Node * cur = head;

    for(int i=0;i<10;i++){
      // Node* node = createNode(i);
      // cur->next = node;
      // cur = node;
      head = insert(head,i);
    }

    printList(head);
    // head = reverse(head);
    // head = swap(head, 0,7);
    head = insert(head,10);
    printList(head);
    head = insert(head,17);
    head = delete_node(head,0);
    printList(head);

  return 0;
}
