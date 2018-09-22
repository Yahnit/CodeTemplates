#include<stdio.h>
#include<string.h>
long long int a[10][100009]={0},seg[10][400009]={0};

	long long int flag,k;
char str[1000009];
long long int q,pos,c,l1,l2,r1,r2,i,ch,n,j;

	long long int mid;
int construct(long long int block,long long int low,long long int high,long long int i)
{
	if(low!=high)
	{
		mid=(low+high)>>1;
		construct(2*block,low,mid,i);
		construct(2*block+1,mid+1,high,i);
		seg[i][block]=(seg[i][2*block]+seg[i][2*block+1]);
	}
	else
		seg[i][block]=a[i][high];
	return 0;
}

long long int update(long long int block,long long int low,long long int high,long long int ind,long long value,long long int i,long long int o)
{
	//	printf("%lld %lld\n",i,o);
	if(low!=high)
	{
		mid=(low+high)>>1;
		//	printf("Entered update func and is in frst step\n");
		if(!(low<=ind && ind<=mid))
			update(2*block+1,mid+1,high,ind,value,i,o);
		else
			update(2*block,low,mid,ind,value,i,o);

		seg[i][block]=seg[i][2*block]+seg[i][2*block+1];
	}
	else
	{
		seg[i][block]=o;
		a[i][ind]=o;
	}

	return 0;
}

long long int query(long long int block,long long int low,long long int high,long long int p,long long int q,long long int i)
{
	long long int x,y;
	//	printf("Entered query function...\n");
	if(p<=low && high<=q)
		return seg[i][block];
	else if(q<low || high<p)
		return 0;
	mid=(high+low)>>1;
	x=query(2*block,low,mid,p,q,i);
	//	printf("x = %lld\n",x);
	y=query(2*block+1,mid+1,high,p,q,i);
	//	printf("y = %lld\n",y);
	//	seg[i][block]=seg[i][2*block]+seg[i][2*block+1];
	return x+y;
}

void buildarray()
{

	for(i=0;i<strlen(str);i++)
	{
		a[str[i]-'0'][i+1]=1;
	}
	for(i=0;i<10;i++)
	{
		construct(1,1,n,i);
	}
}


void updt()
{

	scanf("%lld",&pos);
	scanf("%lld",&c);
	//	a[str[pos-1]-'0'][pos]=0;
	//update
	//		printf("Entered update...\n");
	update(1,1,n,pos,c,str[pos-1]-48,0);
	//		printf("Forst update done..\n");
	//	printf("charac is %c\n",c-48);
	update(1,1,n,pos,c,c,1);
	//	a[c-'0'][pos]=1;
	//update
	//	printf("Update finished..\n");
	str[pos-1]=c+48;
}
long long int g1,g2;
void qry()
{

	flag=1;
	//	printf("Entered query...\n");
	scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
	for(k=0;k<10;k++)
	{
		//  printf("k=%lld\n",k);
		 g1=query(1,1,n,l1,r1,k);
		 g2=query(1,1,n,l2,r2,k);
		// printf("q1=%lld q2=%lld\n",g1,g2);

		if(g1!=g2)
		{
			// printf("q1=%lld q2=%lld\n",g1,g2);
			flag=0;
			break;
		}
	}

}

int main()
{
	scanf("%s",str);
	n=strlen(str);

	/*	for(i=0;i<10;i++)
		{
		for(j=0;j<n;j++)
		{
		printf("%lld ",a[i][j+1]);
		}
		printf("\n");
		}
		printf("\n");
		printf("\n");

		for(i=0;i<10;i++)
		{
		for(j=0;j<4*n;j++)
		{
		printf("%lld ",seg[i][j+1]);
		}
		printf("\n");
		}
		printf("\n");
	 */	
	scanf("%lld",&q);
	for(j=0;j<q;j++)
	{
		scanf("%lld",&ch);
		if(ch==1)
		{
			updt();
		}
		else 
		{
			qry();

			if(flag==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
