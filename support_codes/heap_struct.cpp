#include<iostream>
using namespace std;
#include "/Users/yahnit/Documents/stdc++.h"

typedef struct heapNode{
	int val,key;
}HeapNode;

vector<HeapNode> heap;
int position_heap[10000] = {-1};

HeapNode createNode(int key, int val){
	HeapNode newnode;
	newnode.key = key;
	newnode.val = val;
	return newnode;
}

vector<HeapNode> insert(vector<HeapNode> heap, int position_heap[], int key, int val){
	HeapNode new_node = createNode(key, val);
	heap.push_back(new_node);

	int max = heap.size()-1;

	while (max>=1){

		int parent = (max-1) >> 1;

		if (val <= heap[parent].val){
			heap[max].val = val;
			heap[max].key = key;
			position_heap[key] = max;
			return heap;
		}
		heap[max].val = heap[parent].val;
		heap[max].key = heap[parent].key;
		position_heap[heap[parent].key] = max;
		max = parent;
	}
	heap[0].val = val;
	heap[0].key = key;
	position_heap[key] = 0;

	return heap;
}

vector<HeapNode> max_heapify(vector<HeapNode> heap, int position_heap[], int i){

	int big = i , left = 2*i+1, right = 2*i+2;

	if (right<heap.size() && heap[right].val > heap[big].val)
		big=right;

	if (left<heap.size() && heap[left].val > heap[big].val)
		big=left;

	if(big!=i){
		position_heap[heap[i].key] = big;
		position_heap[heap[big].key] = i;

		HeapNode tp = heap[i];
		heap[i] = heap[big];
		heap[big] = tp;

		max_heapify(heap, position_heap, big);
	}

	return heap;
}

vector<HeapNode> extractMax(vector<HeapNode> heap, int position_heap[]){
	// *max_node = heap[0];

	// correct this statement...
	position_heap[heap[0].key] = -1;
	position_heap[heap[heap.size()-1].key] = 0;

	heap[0] = heap[heap.size()-1];

	heap.pop_back();
	// cout << heap.size()<< endl;
	heap = max_heapify(heap, position_heap, 0);

	return heap;
}

vector<HeapNode> updateKey(vector<HeapNode> heap, int position_heap[], int key, int val){
	int i = position_heap[key];
	heap[i].val = val;

	while(i && heap[i].val > heap[(i-1)>>1].val){
		position_heap[heap[i].key] = (i - 1) >> 1;
		position_heap[heap[(i-1)>>1].key] = i;

		HeapNode tp = heap[i];
		heap[i] = heap[(i-1)>>1];
		heap[(i-1)>>1] = tp;

		i = (i-1) >> 1;
	}

	return heap;
}

void print(vector<HeapNode> heap, int position_heap[]){
	for(int i=0;i<heap.size();i++)
		cout << heap[i].val << " ";
	cout << "\n";

	// for(int i=0;i<8;i++)
	// 	cout << position_heap[i] << " ";
	// cout << "\n";
return;
}

int main(){

	int x;
	for(int i=0;i<8;i++){
		cin >> x;
		heap = insert(heap, position_heap, i, x);
	}
	print(heap, position_heap);
	heap = updateKey(heap, position_heap, 7,10);

	for(int i=0;i<8;i++){
		cout << heap[0].val << endl;
		heap = extractMax(heap, position_heap);
	}


	return 0;
}
