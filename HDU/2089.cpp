#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int num[10];
int dp[10][2];
int dfs(int pos,int pre,int state,bool isLimit)
{
	int sum=0;
	if(pos==0)
	{
		return 1;
	}
	else if(!isLimit&&dp[pos][state]!=-1)
	{
		return dp[pos][state];
	}
	else
	{
		int maxNum=isLimit?num[pos]:9;
		for(int i=0;i<=maxNum;i++)
		{
			if(pre==6&&i==2) 
			{
				continue;
			}
			if(i==4)
			{
				continue;
			}
			sum+=dfs(pos-1,i,i==6,isLimit&&i==maxNum);
		}
	}
	if(!isLimit)
	{
		dp[pos][state]=sum;
	}
	return sum;
}
int calc(int x)
{
	int cnt=0;
	if(!x)
	{
		num[++cnt]=0;
	}
	else
	{
		while(x)
		{
			num[++cnt]=x%10;
			x/=10;
		}
	}
	return dfs(cnt,-1,-1,true);
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d %d",&n,&m))
	{
		for(int i=0;i<=9;i++)
		{
			dp[i][0]=-1;
			dp[i][1]=-1;
		}
		if(!n&&!m) 
		{
			break;
		}
		cout<<calc(m)-calc(n-1)<<endl;
	}
	return 0;
}
