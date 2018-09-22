#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int compare(const void* a, const void* b)
{
	if(*(long long int*)a - *(long long int*)b < 0)
		return -1;
	if(*(long long int*)a - *(long long int*)b == 0)
		return 0;
	if(*(long long int*)a - *(long long int*)b > 0)
		return 1;
}

long long int lower_bound(long long int a[],long long int high, long long int n)
{
	long long int res=high+1;
	long long int mid,low=0;
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(a[mid]<n)
			low=mid+1;
		else
		{
			res=mid;
			high=mid-1;
		}
	}
	return res+1;
}


long long int upper_bound(long long int a[], long long int high, long long int n)
{
	long long int res=high+1;
	long long int mid,low=0;
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(a[mid]<=n)
			low=mid+1;
		else
		{
			res=mid;
			high=mid-1;
		}
	}
	return res+1;
}

long long int ans[100009],power[65],hash[100009],extra[100009];

long long int HASH(char string[],long long int len,long long int power[])
{
	long long int i,flag[65]={0},sum=0;
	for(i=0;i<len;i++)
	{
		if(string[i]>=48 && string[i]<=57)
			flag[string[i]-48]++;
		else if(string[i]>=65 && string[i]<=90)
			flag[string[i]-55]++;
		else if(string[i]>=97 && string[i]<=122)
			flag[string[i]-61]++;
	}
	for(i=0;i<62;i++)
	{
		if(flag[i]!=0)
			sum+=power[i];
	}
	return sum;
}


int main()
{
	long long int t,i,rand;
	rand=1,power[0]=1;
	for(i=1;i<65;i++)
	{
		rand=rand*2;
		power[i]=rand;
	}
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		char str[1000009];
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			hash[i]=HASH(str,strlen(str),power);
			extra[i]=hash[i];
		}

		qsort(hash,n,sizeof(long long int ),compare);
		for(i=0;i<n;i++)
		{
			ans[i]=upper_bound(hash,n-1,extra[i])-lower_bound(hash,n-1,extra[i]);
			printf("%lld ",ans[i]);
		}
		/*	for(i=0;i<n;i++)
			printf("%lld ",hash[i]);*/
		printf("\n");
	}
	return 0;
}
