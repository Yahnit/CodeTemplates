void insert(int heap[100001],int max,int z)
{
	while (max>=1)
	{
		int parent=(max-1)>>1;
		if (z<=heap[parent])
		{
			heap[max]= z;
			return;
		}
		heap[max] = heap[parent];
		max= parent;
	}
	heap[0]=z;
	return;
}

int max_heap(int heap[100001], int n, int i)
{
	int big=i,left=2*i+1,right=2*i+2;
	if (right<n && heap[right] > heap[big])
		big=right;
	if (left<n && heap[left]> heap[big])
		big=left;

	tp=heap[i];
	heap[i]=heap[big];
	heap[big]=tp;

	if(big!=i) max_heap(heap,n,big);
		return 0;
}
