#include<stdio.h>
#include<string.h>

int b[1000000];

void merging(int a[],int low, int mid, int high) {
   int l1, l2, i;

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

void sort(int a[],int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(a,low, mid);
      sort(a,mid+1, high);
      merging(a,low, mid, high);
   } else { 
      return;
   }
}   
int main()
{
  int n,k,i,j;
  char st[1000000];
  scanf("%d%d",&n,&k);
  scanf("%s",st);
   int arr[1000000];
   for(i=0;i<=k;i++)
        {
          int temp=i;
          int p=0;
         for(j=temp;j<n;j+=k)
           {
              arr[p]=st[j]-48;
              p++;
           }
      
         sort(arr,0,p-1);
          p--;
          for(j=temp;j<n;j+=k)
              {
                st[j]=arr[p]+48;
                p--;
              } 
        }
      printf("%s\n",st);

return 0;
}
