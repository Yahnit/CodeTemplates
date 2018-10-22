#include<stdio.h>
#include<limits.h>

int min(int w,int e)
{
	if(w>e)
		return e;
	return w;
}

int max(int w,int e)
{
	if(w>e)
		return w;
	return e;
}
int a[100009],b[100009],low,high;
int x[100009],y[100009];
int main()
{
   int t,i;
   scanf("%d",&t);
   while(t--)
   {
      int n,k;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
		  scanf("%d",&a[i]);
	  scanf("%d",&k);
	  for(i=0;i<k;i++)
		  scanf("%d",&b[i]);
       int l1=b[0];
	   int l2=b[k-1];
       x[0]=a[0];
	   y[0]=a[0];
	   int p=1,q=1;
	   low=-INT_MAX;
	   high=INT_MAX;
	   if(a[0]<b[0])
		   low=a[0];
	   else high=a[0];

	   for(i=1;i<n;i++)
	   {
           if(a[i]>low && a[i]<high)
		   {
			   x[p++]=a[i];
			   if(a[i]>l1)
				   high=min(a[i],high);
			   else low=max(a[i],low);
		   }
          if(a[i]==b[0])
		  { x[p++]=a[i];break;}
	   }

	   low=-INT_MAX;
	   high=INT_MAX;
	   if(a[0]<b[k-1])
		   low=a[0];
	   else high=a[0];

	   for(i=1;i<n;i++)
	   {
           if(a[i]>low && a[i]<high)
		   {
			   y[q++]=a[i];
			   if(a[i]>b[k-1])
				   high=min(a[i],high);
			   else low=max(a[i],low);
		   }
          if(a[i]==b[k-1])
		  {  y[q++]=a[i];break;}
        }
	   p--;q--;
	/*  for(i=0;i<p;i++)
		  printf("%d ",x[i]);
         printf("\n");
	  for(i=0;i<q;i++)
		  printf("%d ",y[i]);
         printf("\n");*/
		 int flag;
      for(i=0;i<min(p,q);i++)
	  {
		  if(x[i]!=y[i])
          { flag=i;break;}
	  }
	  int len=0,final[100009];
   for(i=p-1;i>=flag;i--)
	    final[len++]=x[i];
   for(i=flag-1;i<q;i++)
	   final[len++]=y[i];
   /* for(i=0;i<len;i++)
      printf("%d ",final[i]);
	printf("\n");*/
    int res=1;
	for(i=0;i<min(len,k);i++)
        {
           if(b[i]!=final[i])
		   {
			   res=0;
			   break;
		   }
		}
	if(res==1)
		printf("Yes\n");
	else printf("No\n");

   }

}
