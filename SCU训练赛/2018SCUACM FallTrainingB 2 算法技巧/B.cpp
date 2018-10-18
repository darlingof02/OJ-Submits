#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
char t[51];
char prefix[51],suffix[51];
char ansStr[5001];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",t);
	int len=strlen(t);
	int repeatLen=0;
	for(int k=len-2;k>=0;k--)  //[0,k]与[len-k-1,len-1]重复
	{
		memset(prefix,0,sizeof(prefix));
		memset(suffix,0,sizeof(suffix));
		for(int i=0;i<=k;i++)
		{
			prefix[i]=t[i];
		}
		for(int i=len-k-1,j=0;i<=len-1;i++,j++)
		{
			suffix[j]=t[i];
		}
		if(!strcmp(prefix,suffix))
		{
			repeatLen=k+1;
			break;
		}
	}
	int startPos=0;
	int strCount=0;
	while(strCount<k)
	{
		for(int i=startPos,j=0;i<startPos+len;i++,j++)
		{
			ansStr[i]=t[j];
		}
		strCount++;
		startPos+=(len-repeatLen);
	}
	cout<<ansStr<<endl;
	return 0;
}
