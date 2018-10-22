#include<iostream>
using namespace std;

typedef struct node{
  int num = 0;
  int ind = -1000;
}Node;

bool compare(Node a, Node b){
  return (a.num > b.num );
}

void heap_insert(Node heap[], int n, int x, int y){
  while(n>=1){
    int parent = (n-1)>>1;
    if(heap[parent].num >= x){
        heap[n].num = x;
        heap[n].ind = y;
        return;
      }
    else
      heap[n].num = heap[parent].num;
      heap[n].ind = heap[parent].ind;
      n = parent;
  }
  heap[0].num = x;
  heap[0].ind = y;
  return;
}

void heapify(Node heap[], int n, int i){
  int largest = i, left = 2*i+1, right = 2*i+2;

  if(left<n && heap[left].num > heap[i].num)
    largest = left;
  if(right<n && heap[right].num > heap[i].num)
    largest = right;

  Node temp = heap[largest];
  heap[largest] = heap[i];
  heap[i] = temp;

  if(largest!=i)
    heapify(heap,n,largest);

  return;
}

int main(){
  int n,k, a[1000];
  Node freq[1000];

  cin >> n >> k;

  for(int i=0;i<n;i++){
    cin >> a[i];
    freq[a[i]].num += 1;
    freq[a[i]].ind = a[i];
  }

  Node heap[10000];
  int size = 0;
  for(int i=1;i<=n;i++){
    if(freq[i].num!=0){
      heap_insert(heap, size,freq[i].num,freq[i].ind);
      size++;
    }
  }
  Node temp[10000];
  int job[10000],tim = 0, len=0;

  while(!(size==0 && len==0)){
      int interval = k+1;
      while(interval > 0 && size>0){
        Node largest = heap[0];
        largest.num -=1;
        job[tim++] = largest.ind;
        if(largest.num>0)
          temp[len++] = largest;

        heap[0] = heap[size-1];
        size--;
        heapify(heap,size,0);
        interval--;
      }
      while(interval > 0)
        {
          job[tim++] = -1;
          interval--;
        }
      for(int i=0;i<len;i++){
        heap_insert(heap,size,temp[i].num,temp[i].ind);
        size++;
      }
      len = 0;
    }
    for(int i=0;i<tim;i++)
      cout << job[i] << " ";

    for(int i=tim-1;i>=0;i--)
      if(job[i]!=0){
        cout << "\nRequired Time interval is " << i << endl;
        break;
      }

  return 0;
}
