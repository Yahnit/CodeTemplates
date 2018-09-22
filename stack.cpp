#include<iostream>
using namespace std;
int stack[100000],size = 0;

void push(int ele){
  stack[size++] = ele;
  return;
}

int pop(){
  if(!size)
    return -1;
  else{
    size--;
    return stack[size];
  }
}

int top(){
  if(!size)
    return -1;
  else
    return stack[size-1];
}


int main(){



  return 0;
}
