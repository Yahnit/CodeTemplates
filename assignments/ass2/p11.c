#include<stdio.h>
long long int t[100001][2],heap[100001][2];
long long int p[100001],q[100001];
long long int per;
int f=0;
void merge(long long int arr[100001][2],long long int low, long long int mid, long long int high)
{
	long long int x=low;
	long long int y=mid+1;
	long long int i=low;

	while(x<=mid && y<=high)
	{
		if(arr[x][0]<=arr[y][0])
		{
			p[i]=arr[x][0];
			q[i++]=arr[x++][1];
		}
		
		else
		{
			p[i]=arr[y][0];
			q[i++]=arr[y++][1];
		}
	}

	while(x<=mid)
	{
		p[i]=arr[x][0];
		q[i++]=arr[x++][1];
	}

	while(y<=high)
	{
		p[i]=arr[y][0];
		q[i++]=arr[y++][1];
	}

	for(i=low;i<=high;i++)
	{
		arr[i][0]=p[i];
		arr[i][1]=q[i];
	}
}

void merge_sort(long long int arr[100001][2],long long int low, long long int high) {
	if(low<high)
	{
		long long int mid =(low+high)>>1;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	else
		return;

}

void swap(long long int a[] ,long long int b[])
{
	long long int temp=*a;
	*a=*b;
	*b=*temp;
}

long long int min_heap(long long int heap[100001][2], long long int n, long long int i)
{
	long long int small=i,left=2*i+1,right=2*i+2;
	if (right<n && heap[right][1]<heap[small][1])
		small=right;
	if (left<n && heap[left][1]<heap[small][1])
		small=left;
	//	swap(&heap[i],&heap[small]);
	//	swap(heap[i][0],heap[small][0]);

	per=heap[i][0];
	heap[i][0]=heap[small][0];
	heap[small][0]=per;

	per=heap[i][1];
	heap[i][1]=heap[small][1];
	heap[small][1]=per;

	if(small!=i) min_heap(heap,n,small);
	return 0;
}

int lis(int arr[], int n)
{
	int max_lis_length = 1;

	find_max_val( arr, n, &max_lis_length );

	return max_lis_length;
}
void insert(long long int size,long long int a,long long int b)
{
	while (size>=1)
	{
		long long int parent=(size-1)/2;
		if (a>=heap[parent][1])
		{
			heap[size][1] = a;
			heap[size][0] = b;
			return;
		}
		heap[size][1] = heap[parent][1];
		heap[size][0] = heap[parent][0];
		size=parent;
	}
	heap[0][1]=a;
	heap[0][0]=b;
}


int main()
{
	long long int n,i,k;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&t[i][0],&t[i][1]);
	}
	merge_sort(t,0,n-1);
	//	for(i=0;i<n;i++)
	//		printf("%lld %lld\n",t[i][0],t[i][1]);

	long long int time=t[0][0] ;
	long long int sum=0;
	i=0;
	long long int x=0,y=0;
	while(x<n)
	{
		while(t[y][0]<=time && y<n)
		{
			insert(i,t[y][1],t[y][0]);
			i++;
			y++;
		}
		sum=sum+time-heap[0][0]+heap[0][1];
		time+=heap[0][1];
		//    printf("%lld %lld\n",heap[0][0],heap[0][1]);

		if(i!=1)
		{
			per=heap[0][0];
			heap[0][0]=heap[i-1][0];
			heap[i-1][0]=per;

			per=heap[0][1];
			heap[0][1]=heap[i-1][1];
			heap[i-1][1]=per;
		}
		i--;
		min_heap(heap,i,0);
		//	printf("%lld %lld %lld %lld\n",i,y,time,sum);
		x++;
	}
	printf("%lld\n",sum/n);

	return 0;
}

int find_max_val(int arr[], int n, int *max_lis_length)
{
	if (n == 1)
		return 1;

	int current_lis_length = 1,i;
	for (i=0; i<n-1; i++)
	{
		int subproblem_lis_length = find_max_val(arr, i, max_lis_length);
		if (arr[i] < arr[n-1] &&
				current_lis_length < (1+subproblem_lis_length))
			current_lis_length = 1+subproblem_lis_length;
	}
	if (*max_lis_length < current_lis_length)
		*max_lis_length = current_lis_length;

	return current_lis_length;
}
