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

