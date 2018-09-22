#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long long int temp[10000][2];

void merge(long long int arr[10000][2],long long int low, long long int mid, long long int high) 
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
			temp[i][1]=arr[y++][1];
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

void merge_sort(long long int a[10000][2],long long int low, long long int high) {
	if(low<high)
	{
		long long int mid =(low+high)>>1;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	} 
	else  
		return;
	   
}
int main()
{
	long long int n,arr[10000][2],i,j,temp[10000][2],k;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&arr[i][0]);
		arr[i][1]=i;
	}
	merge_sort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			temp[j][0]=arr[j][1];
			//	   printf("%lld ",arr[j][1]+1);
		}
		merge_sort(temp,0,j-1);
		for(k=0;k<j-1;k++)
			printf("%lld ",temp[k][0]+1);
		printf("%lld\n",temp[j-1][0]+1);

		//printf("%lld\n",arr[j][1]+1);
	}	   
	return 0;
}
