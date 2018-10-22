#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

long long int mod=200009,ans[100009],p=3;
typedef struct node
{
	long long int freq;
	char * str;
}Node;
Node hash[200009];

long long int HASH(long long int value,long long int size,char string[])
{
	if(hash[value].freq==0)
	{
		hash[value].str= (char *)malloc((size)*sizeof(char));
		hash[value].str=string;
		(hash[value].freq)++;
		return value;
	}
	else
	{
		if(strcmp(hash[value].str,string)==0)
		{
			hash[value].freq+=1;
			return value;
		}
		else
		{  
			long long int k=1,check=0;
			while(hash[(value+k*k)%mod].freq!=0)
			{
				if(strcmp(hash[(value+k*k)%mod].str,string)==0)
				{
					hash[(value+k*k)%mod].freq+=1;
					check=1;
					return (value+k*k)%mod;
				}
				else k++;
			}
			if(check==0)
			{
				hash[(value+k*k)%mod].freq+=1;
	hash[(value+k*k)%mod].str= (char *)malloc((size)*sizeof(char));
				hash[(value+k*k)%mod].str=string;
				return (value+k*k)%mod;
			}

		}
	}

}

long long int place(char str[],long long int length)
{
	long long int j,flag[200]={0},sum=0,count=0,temp,size=0;
	char string[1000009];
	for(j=0;j<length;j++)
		flag[str[j]]++;
	for(j=47;j<130;j++)
		if(flag[j]!=0)
		{
			sum=(sum*p+j)%mod;
			string[size++]=j;
		}
	string[size]='\0';
	return HASH(sum,size,string);
}

		long long int n,ans[100009];
		char seq[1000009];
int main()
{
	long long int t,i;
	scanf("%lld",&t);

	while(t--)
	{
		for(i=0;i<mod;i++)
		{
			hash[i].freq=0;
//			if(hash[i].str!=NULL)
//				free(hash[i].str);
		}

		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",seq);
			ans[i]=place(seq,strlen(seq));
		}
		for(i=0;i<n-1;i++)
			printf("%lld ",hash[ans[i]].freq);
		printf("%lld\n",hash[ans[n-1]].freq);
	}

	return 0;
}
