#include<stdio.h>

long long int b[100001][2];

long long int upper_bound(long long int a[100001][2],long long int low, long long int high, long long int n,long long int last)
{
	long long int ans = last;
	while(low <= high)
	{
		long long int mid=(low+high)>>1;
		if(a[mid][0]>n)
			ans=mid,high=mid-1;
		else
			low=mid+1;
	}
	return ans;
}
void merge(long long int a[100001][2],long long int low, long long int mid, long long int high) 
{
	long long int x=low;
	long long int y=mid+1;
	long long int i=low,k;

	while(x<=mid && y<=high)
	{
		if(a[x][0]<=a[y][0])
		{
			b[i][0]=a[x][0],b[i++][1]=a[x++][1];
		}

		else
		{
			b[i][0]=a[y][0],b[i++][1]=a[y++][1];
		}
	}

	for(k=0;x<=mid;k++)    
	{
		b[i][0]=a[x][0],b[i++][1]=a[x++][1];
	}

	for(k=0;y<=high;k++)   
	{
		b[i][0]=a[y][0],b[i++][1]=a[y++][1];
	}

	for(i=low;i<=high;i++)
	{
		a[i][0]=b[i][0],a[i][1]=b[i][1];
	}
}

void merge_sort(long long int a[100001][2],long long int low, long long int high)
{
	if(low<high) 
	{
		long long int mid=(low+high)>>1;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
	else return;

}

void merge_1(long long int a[100001][2],long long int low, long long int mid, long long int high) 
{
	long long int x=low;
	long long int y=mid+1;
	long long int i=low,k;

	while(x<=mid && y<=high)
	{
		if(a[x][1]<=a[y][1])
		{
			b[i][1]=a[x][1],b[i++][0]=a[x++][0];
		}

		else
		{
			b[i][1]=a[y][1],b[i++][0]=a[y++][0];
		}
	}

	for(k=0;x<=mid;k++)    
	{
		b[i][1]=a[x][1],b[i++][0]=a[x++][0];
	}

	for(k=0;y<=high;k++)   
	{
		b[i][0]=a[y][0],b[i++][1]=a[y++][1];
	}

	for(i=low;i<=high;i++)
	{
		a[i][0]=b[i][0],a[i][1]=b[i][1];
	}
}

void merge_sort_1(long long int a[100001][2],long long int low, long long int high)
{
	if(low<high) 
	{
		long long int mid=(low+high)>>1;
		merge_sort_1(a,low,mid);
		merge_sort_1(a,mid+1,high);
		merge_1(a,low,mid,high);
	}
	else return;
}

int main()
{
	long long int n,i,a[100001][2];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i][0],&a[i][1]);

	}
//	merge_sort(a,0,n-1);
	/*	for(i=0;i<n;i++)
		printf("%lld %lld\n",a[i][0],a[i][1]);*/

	long long int time=a[0][1],counter=a[0][1],size=n;

	while(size>1)
	{

		int k=upper_bound(a,0,size-1,time,size);

	/*	for(i=1;i<size;i++)
		{
			if(a[i][0]>time)
			{
				k=i;
				break;
			}
		}*/

		//			  printf("k=%d\n",k);
		merge_sort_1(a,1,k-1);
		counter+=(time-a[1][0])+a[1][1];
		time+=a[1][1];
		 //  printf("counter=%d time=%d \n",counter,time);
		//delete the first element and movw the elements to the left...
		for(k=1;k<size;k++)
		{
			a[k-1][0]=a[k][0];
			a[k-1][1]=a[k][1];
		}
		size--;
		merge_sort(a,1,size-1);

	}

	printf("%d\n",counter/n);

	return 0;
}
