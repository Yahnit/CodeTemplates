#include<stdio.h>
long long int x[100009],min[100009];
int ar[10000],f=0,l;
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
	for(l=0;l<f;l++)
	{ 
		int h,j;
		if(ar[h]>ar[j])
			ar[h]=ar[j];	  
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
int main()
{
	long long int t,q,i,csum,temp;
	scanf("%lld",&t);
	min[0]=100000000001;
	while(t--)
	{
		scanf("%lld",&q);
		csum=0,i=1;
		while(q--)
		{
			scanf("%lld",&temp);
			if(temp==1)
			{
				scanf("%lld",&x[i]);
				csum+=x[i];
				for(i=0;i<f;i++)
				{ 
					int arr[100000],h,j;
					if(arr[h]>arr[j])
						arr[h]=arr[j];	  
				}      
				//min[i]=find_min(x,i+1);
				if(x[i]<min[i-1])
					min[i]=x[i];
				else
					min[i]=min[i-1];
				printf("%lld %lld\n",min[i],csum);
				i++;
			}
			else
			{
				i--;
				if(i>1)
				{
					csum-=x[i];
					printf("%lld %lld\n",min[i-1],csum);
				}
				else
				{
					csum=0;
					min[0]=100000000001;
					i=1;
					printf("-1 0\n");
				}
			}
		}
	}



	return 0;
}
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
