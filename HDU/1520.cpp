#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int dp[6001][2];
int value[6001];
bool vis[6001];
vector<int>node[6001];
void treeDP(int x)
{
	vis[x]=true;
	dp[x][1]=value[x];
	dp[x][0]=0;
	for(int i=0;i<node[x].size();i++)
	{
		int next=node[x][i];
		if(!vis[next])
		{
			treeDP(next);
			dp[x][0]+=max(dp[next][0],dp[next][1]);
			dp[x][1]+=dp[next][0];
		}
	}
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			node[i].clear();
			vis[i]=false;
			scanf("%d",&value[i]);
		}
		int a,b;
		while(~scanf("%d %d",&a,&b))
		{
			if(!a&&!b)
			{
				break;
			}
			node[a].push_back(b);
			node[b].push_back(a);
		}
		treeDP(1);
		cout<<max(dp[1][0],dp[1][1])<<endl;
	}
	return 0;
}