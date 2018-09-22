void insert(long long int max,long long int z,long long int w)
{

	while (max>=1)
	{
		long long int parent=(max-1)>>1;
		if (z<=heap[parent].h)
		{
			heap[max].h= z;
			heap[max].r = w;
			return;
		}
		heap[max].h = heap[parent].h;
		heap[max].r = heap[parent].r;
		max= parent;
	}
	heap[0].h=z;
	heap[0].r=w;
}

long long int max_heap(rec heap[100001], long long int n, long long int i)

{

	long long int big=i,left=2*i+1,right=2*i+2;

	if (right<n && heap[right].h > heap[big].h)
		big=right;

	if (left<n && heap[left].h > heap[big].h)
		big=left;

	tp=heap[i];
	heap[i]=heap[big];
	heap[big]=tp;

	if(big!=i) max_heap(heap,n,big);

	return 0;

}
