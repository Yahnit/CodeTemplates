int temp[10000000];
int merge(int arr[],int low, int mid, int high); 
void merge_sort(int a[],int low, int high)

void merge_sort(int a[],int low, int high)
{
	if(low<high)
	{
		int mid=(low+high)>>1;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
	else  
		return;
	   
}
int merge(int arr[],int low, int mid, int high) 
{
	int x=low;
	int y=mid+1;
	int i=low;
	while(x<=mid && y<=high)
	{
		if(arr[x]<=arr[y])
		{
			temp[i++] = arr[x++];
		}
		else
		{
			temp[i++] = arr[y++];
		}
	}

	while(x<=mid)    
	{
		temp[i++]=arr[x++];
	}

	while(y<=high)   
	{
		temp[i++]=arr[y++];
	}

	for(i=low;i<=high;i++)
	{
		arr[i]=temp[i];
	}
	return 0;
}

