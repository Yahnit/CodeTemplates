#include<stdio.h>

long long int n,arr[2001][2001],heap[2001][2001],size[2001]={0},c[2001],d[2001];

void initialize()
{

        long long int i,j;
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              arr[i][j]=c[i];
      for(i=0;i<n;i++)
        size[i]=0;
return;
}

long long int heapify(long long int n, long long int i,long long int j)
{
	long long int small=i,left=2*i+1,right=2*i+2,temp;  
	if (right<n && arr[heap[j][right]][j]<arr[heap[j][small]][j])
		small=right;
	if (left<n && arr[heap[j][left]][j]<arr[heap[j][small]][j])
		small=left;
           // temp=a[j][i],a[j][i]=a[j][small],a[j][small]=temp;          
 
	if(small!=i)
	{
           temp=heap[j][i],heap[j][i]=heap[j][small],heap[j][small]=temp;          
	//	temp=small,small=i,i=temp;
		heapify(n,small,j);
	}
	return 0;
}

void insert(long long int max,long long int i,long long int j)

{
	while (max>=1)
	{
		long long int parent=((max-1)/2);
		if (arr[i][j]>=arr[heap[j][parent]][j])
		{
			heap[j][max]= i;
			return;
		}
		heap[j][max] = heap[j][parent];
		max= parent;
	}
	heap[j][0]=i;
}

int main()
{
	long long int temp,i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&c[i]);
	for(i=0;i<n-1;i++)
		scanf("%lld",&d[i]);
         initialize();
     for(i=n-2;i>=0;i--)
     {
	     for(j=i;j>=0;j--)
	     {

			     insert(size[j+1],i+1,j+1);
			     size[j+1]++;
			     while(i+d[j]<heap[j+1][0])
			     {
                                temp= heap[j+1][0];
				heap[j+1][0]=heap[j+1][size[j+1]-1];
				heap[j+1][size[j+1]-1]=temp;
				size[j+1]--;
				heapify(size[j+1],0,j+1);
			     }
			   arr[i][j]+=arr[heap[j+1][0]][j+1];
	     }
     } 

 printf("%lld\n",arr[0][0]);
	return 0;
}
