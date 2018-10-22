#include<stdio.h>

int A[10000009];

int lower_bound(int low, int high, int n,int last)
{
	int ans = last;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(A[mid] > n)
			ans = mid, high = mid-1;
		else
			low = mid + 1;
	}
	return ans+1;
}
//TODO: Find the upper bound using a similar idea!
int main()
{
	int n, q, a, i;
	scanf("%d%d",&n,&q);
	for(i = 0 ; i < n ; i++)
		scanf("%d",&A[i]);
	for(i = 0 ; i < q ; i++)
	{
		scanf("%d",&a);
		printf("%d\n",lower_bound(0,n-1,a,n));
	}
	return 0;
}
