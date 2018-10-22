#include<stdio.h>

int upper_bound(int a[],int low, int high, int n,int last)
{
	int ans = high+1;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(a[mid] > n)
			ans = mid, high = mid-1;
		else
			low = mid + 1;
	}
	return ans+1;
}

long long int b[10000000];
void merging(long long int a[],long long int low, long long int mid, long long int high) {
	long long int l1, l2, i;

	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
		if(a[l1] <= a[l2])
			b[i] = a[l1++];
		else
			b[i] = a[l2++];
	}

	while(l1 <= mid)    
		b[i++] = a[l1++];

	while(l2 <= high)   
		b[i++] = a[l2++];

	for(i = low; i <= high; i++)
		a[i] = b[i];
}

void sort(long long int a[],long long int low, long long int high) {
	long long int mid;

	if(low < high) {
		mid = (low + high) / 2;
		sort(a,low, mid);
		sort(a,mid+1, high);
		merging(a,low, mid, high);
	} else { 
		return;
	}   
}

int main()
{
	int n,m,c[1000000],l[1000000],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
		scanf("%d",&l[i]);
	sort(c,0,n-1);
      //  for(i=0;i<n;i++)
      //   printf("%d ",c[i]);
	for(i=0;i<m;i++)
	{
          int ans=n+1-upper_bound(c,0,n-1,l[i],n);
            printf("%d\n",ans);         
	}
	return 0;
}








