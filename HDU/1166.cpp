#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=50000;
int T;
int n;
int num[maxn+1];
int bitArray[maxn+1];
char opt[10];
int testCase;
int lowbit(int x)
{
	return x&-x;
}
void buildBitTree()
{
	for(int i=1;i<=n;i++)
	{
		bitArray[i]=num[i];
	}
	for(int i=1;i<=n;i++)
	{
		int j=i+lowbit(i);
		if(j<=n)
		{
			bitArray[j]+=bitArray[i];
		}
	}
}
int prefixSum(int x)
{
	int result=0;
	while(x>0)
	{
		result+=bitArray[x];
		x-=lowbit(x);
	}
	return result;
}
void add(int x,int addValue)
{
	while(x<=n)
	{
		bitArray[x]+=addValue;
		x+=lowbit(x);
	}
}
void sub(int x,int subValue)
{
	while(x<=n)
	{
		bitArray[x]-=subValue;
		x+=lowbit(x);
	}
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		testCase++;
		cout<<"Case "<<testCase<<":"<<endl;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		buildBitTree();
		while(~scanf("%s",opt))
		{
			if(!strcmp(opt,"End"))
			{
				break;
			}
			else if(!strcmp(opt,"Query"))
			{
				int L,R;
				scanf("%d %d",&L,&R);
				cout<<prefixSum(R)-prefixSum(L-1)<<endl;
			}
			else if(!strcmp(opt,"Add"))
			{
				int pos,value;
				scanf("%d %d",&pos,&value);
				add(pos,value);
			}
			else
			{
				int pos,value;
				scanf("%d %d",&pos,&value);
				sub(pos,value);
			}
		}
	}
	return 0;
}