#include<iostream>
using namespace std;

void heap_insert(int heap[], int n, int x){
  while(n>=1){
    int parent = (n-1)>>1;
    if(heap[parent]>=x){
        heap[n] = x;
        return;
      }
    else
      heap[n] = heap[parent],n = parent;
  }
  heap[0] = x;
  return;
}

void heapify(int heap[], int n, int i){
  int largest = i, left = 2*i+1, right = 2*i+2;

  if(left<n && heap[left] > heap[i])
    largest = left;
  if(right<n && heap[right] > heap[i])
    largest = right;

  int temp = heap[largest];
  heap[largest] = heap[i];
  heap[i] = temp;

  if(largest!=i)
    heapify(heap,n,largest);

  return;
}

int main()
{
  int n,i,a[100],k, heap[100], size = 0;
  cin >> n >> k;

  for(i=0;i<n;i++){
    cin >> a[i];

    if(size<k){
      heap_insert(heap,size,a[i]);
      size++;
    }
    else{
      if(heap[0]>a[i])
        {
          heap[0] = a[i];
          heapify(heap,size,0);
        }
    }
    cout << heap[0] << endl;
  }

  return 0;
}
