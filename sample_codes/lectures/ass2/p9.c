#include<stdio.h>
long long int ans[1000000],m3[1000000],m5[1000000],m7[1000000];

void insert(int heap[][100],int max,int a,int b)
{
	while (max>=1)
	{
		int parent=(max-1)>>1;
		if (a>=heap[parent][1])
		{
			heap[max][1] = a;
			heap[max][0] = b;
			return;
		}
		heap[max][1] = heap[parent][1];
		heap[max][0] = heap[parent][0];
		max= parent;
	}
	heap[0][1]=a;
	heap[0][0]=b;
}
long long int min_ind(long long int i,long long int j,long long int k)
{
	if(i<=j && i<=k)
		return 1;
	else if(j<=i && j<=k)
		return 2;
	else if(k<=i && k<=j)
		return 3;

}

int main()
{
	long long int counter=2,l1=2,l2=2,l3=2,x=1,y=1,z=1,n,mid;
	m3[1]=3,m5[1]=5,m7[1]=7;
	ans[1]=1;

	scanf("%lld",&n);
	if(n==1)
	{
		printf("%lld",ans[1]);
		return 0;
	}

	while(counter<=n)
	{
		mid=min_ind(m3[x],m5[y],m7[z]);

		if(mid==1)
		{
			m3[l1++]=m3[x]*3;
			m5[l2++]=m3[x]*5;
			m7[l3++]=m3[x]*7;
			ans[counter++]=m3[x++];
		}

		else if(mid==2)
		{
			m5[l2++]=m5[y]*5;
			m7[l3++]=m5[y]*7;
			ans[counter++]=m5[y++];
		}
		else
		{
			m7[l3++]=m7[z]*7;
			ans[counter++]=m7[z++];
		}

	}
	printf("%lld",ans[n]);

	return 0;
}
int temp[1000000];
void merge(int arr[],int low, int mid, int high) 
{
	int x=low;
	int y=mid+1;
	int i=low;

	while(y<=high && x<=mid) 
	{
		if(arr[x]<=arr[y])
		{
			temp[i]=arr[x++];
		}
		else
		{
			temp[i]=arr[y++];
		}
		i++;
	}
	while(x<=mid)    
	{
		temp[i++] = arr[x++];
	}
	while(y<=high)   
	{
		temp[i++]=arr[y++];
	}
	for(i=high-1;i>=0;i--)
	{
		arr[i]=temp[i];
	}
}

void sort(int a[],int low, int high)
{
	int mid;
	if(low < high) 
	{
		mid=(low+high)>>1;
		sort(a,low, mid);
		sort(a,mid+1, high);
		merge(a,low, mid, high);
	}
	else  
		return;

}
