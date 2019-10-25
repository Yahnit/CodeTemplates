#include<iostream>
using namespace std;
#include<vector>

typedef struct node{
	int start, end, overlaps;
}Node;

Node seg[1000009];
vector<Node> disjoint_intervals;

Node createNode(int start, int end, int overlaps){
	Node interval;
	interval.start = start;
	interval.end = end;
	interval.overlaps = overlaps;

	return interval;
}

// https://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/
vector<Node> overlappingIntervals(int start[], int end[], int n){
	sort(start, start + n);
	sort(end, end + n);

	int i = 0, j = 0, overlaps = 0, tym = 0;
	vector<Node> disjoint_intervals;
	disjoint_intervals.push_back(createNode(-1, -1, 0));
	while(i < n && j < n){

		if(end[j] <= start[i]){

      if(tym != end[j]){
          Node interval = createNode(tym, end[j], overlaps);
			    disjoint_intervals.push_back(interval);
        }

			tym = end[j];
			while(end[j] == tym){
				j++;
				overlaps--;
			}
		}

		else{

      if(tym != start[i]){
          Node interval = createNode(tym, start[i], overlaps);
			     disjoint_intervals.push_back(interval);
         }

			tym = start[i];
			while(start[i] == tym){
				i++;
				overlaps++;
			}
		}

	}

  while(j < n){
    if(tym != end[j]){
        Node interval = createNode(tym, end[j], overlaps);
        disjoint_intervals.push_back(interval);
      }

    tym = end[j];
    while(end[j] == tym){
      j++;
      overlaps--;
  }
}
return disjoint_intervals;
}

void print_disjoint_intervals(vector<Node> arr){
  for(auto i = arr.begin(); i!=arr.end();i++)
    cout << i->start << "  " << i->end << "  " << i->overlaps << endl;
  return;
}

void construct(int block, int low, int high){
	if(low != high){

		int mid = (high + low) >> 1;
		construct(2*block, low, mid);
		construct(2*block+1, mid+1, high);

		seg[block].start = seg[2*block].start;
		seg[block].end = seg[2*block+1].end;
		seg[block].overlaps = max(seg[2*block].overlaps, seg[2*block+1].overlaps);
	}

	else
		seg[block] = disjoint_intervals[low];

	return;
}

int query(int block, int low, int high, int p, int q){
	//find lower bound of start time and upper bound of end time
	// use them as p and q for quering the max overlapping intervals between p and q
}

int main(){
  int start[] = {1, 2, 10, 5 ,5};
  int end[] = {4, 5, 12, 9, 12};
  int n = 5;

  disjoint_intervals = overlappingIntervals(start, end, n);
  print_disjoint_intervals(disjoint_intervals);
  // build a segment tree with these intervals
  // For queries, we should fo range max query on seg tree

	int size = disjoint_intervals.size();
	construct(1, 1, size);

  return 0;
}
