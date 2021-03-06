#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Rec
{
	long long int h,r;

}rec;

rec heap[100001],tp;
long long int size=0,ans=0;
typedef struct Temp
{
	long long int val,ht,oth;
	char pos;

}temp;

temp res[300001];
int compare(const void* a,const void * b)
{
	temp *studentA=(temp *)a;
	temp *studentB=(temp *)b;
	return(studentA->val-studentB->val);
}


int lis(int arr[], int n)
{
    int max_lis_length = 1;
 
    find_max_val( arr, n, &max_lis_length );
 
    return max_lis_length;
}

void insert(long long int max,long long int z,long long int w)
{

	while (max>=1)
	{
		long long int parent=(max-1)>>1;
		if (z<=heap[parent].h)
		{
			heap[max].h= z;
			heap[max].r = w;
			return;
		}
		heap[max].h = heap[parent].h;
		heap[max].r = heap[parent].r;
		max= parent;
	}
	heap[0].h=z;
	heap[0].r=w;
}

long long int max_heap(rec heap[100001], long long int n, long long int i)

{

	long long int big=i,left=2*i+1,right=2*i+2;

	if (right<n && heap[right].h > heap[big].h)
		big=right;

	if (left<n && heap[left].h > heap[big].h)
		big=left;

	tp=heap[i];
	heap[i]=heap[big];
	heap[big]=tp;

	if(big!=i) max_heap(heap,n,big);

	return 0;

}
long long int hpsize=0,mod=1000000009;

int main()
{
	long long int n,i,h,p,q,r;
	scanf("%lld",&n);

	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&p,&q,&r);
		res[size].val=q,res[size].pos='l',res[size].ht=p,res[size].oth=r;
		size++;
		res[size].val=r,res[size].pos='r',res[size].ht=p,res[size].oth=q;
		size++;
	}
	qsort(res,size,sizeof(temp),compare);

/*	for(i=0;i<size;i++)
	{
		printf("%lld %lld %lld %lld\n",res[i].val,res[i].pos,res[i].ht,res[i].oth);
	}*/


	heap[hpsize].h=res[0].ht;
	heap[hpsize].r=res[0].oth;
	hpsize++;

	for(i=1;i<size;i++)
	{
		if(res[i].pos=='l')
		{
			while(res[i].val>=heap[0].r && hpsize>0)
			{
				tp=heap[0];
				heap[0]=heap[hpsize-1];
				heap[hpsize-1]=tp;
				hpsize--;
				max_heap(heap,hpsize,0);
			}
		   if(hpsize==0)
			   h=0;
		   else
		   h=heap[0].h;
	//		printf("%lld\n",hpsize);
			ans=(ans+(res[i].val- res[i-1].val)*h)%mod;
	//		printf("%lld %lld %lld %lld\n",res[i].val,res[i-1].val,h,ans);

			insert(hpsize,res[i].ht,res[i].oth);
			hpsize++;
		}

		else if(res[i].pos=='r')
		{
           while(res[i].val>heap[0].r && hpsize>0)
             {
				tp=heap[0];
				heap[0]=heap[hpsize-1];
				heap[hpsize-1]=tp;
				hpsize--;
				max_heap(heap,hpsize,0);
             }
		   if(hpsize==0)
			   h=0;
		   else
		   h=heap[0].h;

		//		printf("%lld\n",hpsize);
		   ans=(ans+(res[i].val-res[i-1].val)*h)%mod;

	//	printf("%lld %lld %lld %lld\n",res[i].val,res[i-1].val,h,ans);
		  // printf("%lld\n",ans);
		}
	}
	printf("%lld\n",ans%mod);

	return 0;
}
 

