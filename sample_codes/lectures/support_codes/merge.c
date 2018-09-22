int random[1000000];
void merge(long long int arr[],long long int low, long long int mid, long long int high) 
{
	long long int x=low;
	long long int y=mid+1;
	long long int i=low;

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

void merge_sort(long long int a[],long long int low, long long int high)
{
	long long int mid;
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
