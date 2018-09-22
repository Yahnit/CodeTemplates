#include<stdio.h>
long long int t[100001][2];

long long int temp[100001][2];

void merge(long long int arr[100001][2],long long int low, long long int mid, long long int high) 
{
	long long int x=low;
	long long int y=mid+1;
	long long int i=low;

	while(x<=mid && y<=high)
	{
		if(arr[x][0]<=arr[y][0])
		{
			temp[i][0]=arr[x][0];
			temp[i++][1]=arr[x++][1];
		}
		else
		{
			temp[i][0]=arr[y][0];
			temp[i++][1]=arr[y++][1];
		}
	}

	while(x<=mid)    
	{
		temp[i][0]=arr[x][0];
		temp[i++][1]=arr[x++][1];
	}

	while(y<=high)   
	{
		temp[i][0]=arr[y][0];
		temp[i++][1]=arr[y++][1];
	}

	for(i=low;i<=high;i++)
	{
		arr[i][0]=temp[i][0];
		arr[i][1]=temp[i][1];
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

void swap(long long int *a,long long int *b)
{
	long long int temp=*a;
	*a=*b;
	*b=temp;
}

long long int min_heap(long long int a[], long long int n, long long int i)
{
	long long int small=i,left=2*i+1,right=2*i+2;  
	if (right<n && a[right]<a[small])
		small=right;
	if (left<n && a[left]<a[small])
		small=left;
	swap(&a[i],&a[small]); 
	if(small!=i) min_heap(a,n,small);
	return 0;
}
int main()
{
	long long int n,i,heap[100001];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&t[i][0],&t[i][1]);
	}
	merge_sort(t,0,n-1);
//	for(i=0;i<n;i++)
//		printf("%lld %lld\n",t[i][0],t[i][1]);
 
	 int time=t[0][1],ans=t[0][1];
     i=1,k=0; 
	   while(time>t[i][0])
	   {
           heap[k++]=t[i][1];
          min_heap(heap,k,(k-1)/2);
          time+=heap[0];
		  ans+=
         i++;
	   }





	return 0;
}
