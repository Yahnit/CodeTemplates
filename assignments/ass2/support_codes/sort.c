#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void * b)
{
	int *studentA=(int *)a;
	int *studentB=(int *)b;
	return(*studentA-*studentB);
}
int main()
{
    int n,arr[100],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	qsort(arr,n,sizeof(int),compare);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
