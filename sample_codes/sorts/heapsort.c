#include<stdio.h>

void build_Heap(int H[],int n)
{
    int i,j,k,v,heap;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=H[k];
        heap=0;
        while(heap==0 && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(H[j]<H[j+1])
                    j++;
            }
            if(v>=H[j])
                heap=1;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}
void HeapSort(int H[],int n)
{
    int t,i;
    for(i=n;i>=1;i--)
    {
        build_Heap(H,i);
        t=H[1];
        H[1]=H[i];
        H[i]=t;
    }
}
int main()
{
  int n,H[100000],i;
  printf("Enter number of elements:");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
     scanf("%d",&H[i]);
  HeapSort(H,n);
  printf("\n");
  for(i=1;i<=n;i++)
   printf("%d ",H[i]);
 
return 0;
}
