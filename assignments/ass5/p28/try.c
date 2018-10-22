#include<stdio.h>
typedef long long int lint;
typedef struct node{
    lint u,v,w;
}Node;
lint n,m;
lint uni[100010];
Node edg[500010],test[500010];
void merge(Node first[],Node second[],lint len1,lint len2)
{
    lint f=0,r=0;
    lint len=0;
    while(f<len1&&r<len2)
    {
        if(first[f].w<second[r].w)
        {
            test[len++]=first[f];
            f++;
        }
        else
        {
            test[len++]=second[r];
            r++;
        }
    }
    while(f<len1)
    {
        test[len++]=first[f];
        f++;
    }
    while(r<len2)
    {
        test[len++]=second[r];
        r++;
    }
    for(f=0;f<len1;f++)
    {
        first[f]=test[f];
    }
    for(f=0;f<len2;f++)
    {
        second[f]=test[f+len1];
    }
    return;
}
lint lil(lint u)
{
    if(uni[u]<0)
        return u;
    else
        return lil(uni[u]);
}
lint find(lint u,lint v)
{
    lint fir = lil(u);
    lint sec = lil(v);
    if(uni[u]!=fir&&uni[u]>=0)
        uni[u]=fir;
    if(uni[v]>=0&&uni[v]!=sec)
        uni[v]=sec;
    if(fir!=sec)
        return 0;
    else
        return 1;
}

void sort(Node edg[],lint m)
{
    if(m==1)
        return;
    sort(edg,m/2);
    sort(edg+m/2,m-(m/2));
    merge(edg,edg+m/2,m/2,m-(m/2));
    return;
}
int main()
{
    lint t,i,j,x,y,w,count,sum,flag,re,re1;
 //   scanf("%lld",&t);
    //for(i=0;i<t;i++)
    //{
        count=0;
        sum=0;
        flag=0;
        scanf("%lld%lld",&n,&m);
        for(j=0;j<=n;j++)
        {
            uni[j]=-1;
        }
        for(j=0;j<m;j++)
        {
            scanf("%lld%lld%lld",&edg[j].u,&edg[j].v,&edg[j].w);
        }
        sort(edg,m);
        for(j=0;j<m;j++)
        {
            if(count==(n-1))
                break;

            if(find(edg[j].u,edg[j].v)==0)
            {
                re=lil(edg[j].u);
                re1=lil(edg[j].v);
                sum=sum+edg[j].w;
                count++;
                    if(uni[re]>uni[re1])
                    {
                        uni[re]=re1;
                        uni[re1]-=1;
                    }
                    else
                    {
                        uni[re1]=re;
                        uni[re]-=1;
                    }
            }
           /* else if(flag==0)
            {
          sum=sum+edg[j].w;
                flag=1;
            }*/
  /* for(i=0;i<n;i++)
    {
        printf("%lld ",uni[i]);
    }
        printf("\n");*/
        }
        printf("%lld\n",sum);
    //}
        return 0;
}
