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

void merge_sort(int a[],int low, int high)
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
