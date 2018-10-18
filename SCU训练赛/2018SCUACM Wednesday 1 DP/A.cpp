#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[101][101];
int map[101][101];
char name[1000];
int T;
int R,C;
int ans;
int max(int a,int b,int c,int d)
{
	if(a>=b&&a>=c&&a>=d)
	{
		return a;
	}
	if(b>=a&&b>=c&&b>=d)
	{
		return b;
	}
	if(c>=a&&c>=b&&c>=d)
	{
		return c;
	}
	else
	{
		return d;
	}
}
int dfs(int x,int y)
{
	if(dp[x][y])
	{
		return dp[x][y];
	}
	int downMax=0,upMax=0,leftMax=0,rightMax=0;
	if(x+1<=R&&map[x][y]>map[x+1][y])
	{
		downMax=dfs(x+1,y);
	}
	if(x-1>=1&&map[x][y]>map[x-1][y])
	{
		upMax=dfs(x-1,y);
	}
	if(y+1<=C&&map[x][y]>map[x][y+1])
	{
		rightMax=dfs(x,y+1);
	}
	if(y-1>=1&&map[x][y]>map[x][y-1])
	{
		leftMax=dfs(x,y-1);
	}
	dp[x][y]=max(downMax,upMax,rightMax,leftMax)+1;
	return dp[x][y];
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(map,0,sizeof(map));
		ans=0;
		scanf("%s %d %d",name,&R,&C);
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
			{
				if(!dp[i][j])
				{
					ans=max(ans,dfs(i,j));
				}
			}
		}
		cout<<name<<": "<<ans<<endl;
	}
	return 0;
}