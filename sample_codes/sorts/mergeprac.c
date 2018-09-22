#include<stdio.h>
int b[1000000];
void sort(int a[],int low,int high);
void merging(int a[],int low,int mid,int high);
int main()
{
   int i,n,a[1000000];
   scanf("%d",&n);
   for(i=1;i<=n;i++)
     scanf("%d",&a[i]);
     sort(a,1,n);
   for(i=1;i<=n;i++)
      printf("%d\n",a[i]);
 return 0;
}

void sort(int a[],int low,int high)
 {
   if(low<high)
     {
        int mid=(high+low)/2;
	sort(a,low,mid);
	sort(a,mid+1,high);
	merging(a,low,mid,high);
     }

 }

void merging(int a[],int low,int mid,int high)
  {
     int x,y,i;
     for(x=low,y=mid+1,i=low;x<=mid,y<=high;i++)
          {
             if(a[x]<=a[y])
	      b[i]=a[x++];
	      else
	      b[i]=a[y++];
	  }
      while(x<=mid)
	   b[i++]=a[x++];
      while(y<=high)
	   b[i++]=a[y++];
    for(i=low;i<=high;i++)
        a[i]=b[i];
  }

