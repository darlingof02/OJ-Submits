#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
ll ans;
struct object
{
	ll P;
	ll C;
};
object people[3001];
int voteNum[3001];
int adjustVoteNum[3001];
bool cmp(object a,object b)
{
	return a.C>b.C;
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&people[i].P,&people[i].C);
		voteNum[people[i].P]++;
		ans+=people[i].C;
	}
	sort(people+1,people+1+n,cmp);
	bool zeroFlag=true;
	for(int i=2;i<=m;i++)
	{
		if(voteNum[i]>=voteNum[1])
		{
			zeroFlag=false;
			break;
		}
	}
	if(zeroFlag)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=voteNum[1];i<=n;i++)
	{
		ll totalCost=0;
		int deltaNum=n-i;
		memset(adjustVoteNum,0,sizeof(adjustVoteNum));
		for(int j=1;j<=n;j++)
		{
			if(people[j].P!=1&&deltaNum>0)
			{
				if(adjustVoteNum[people[j].P]<i-1)
				{
					adjustVoteNum[people[j].P]++;
					deltaNum--;
				}
				else
				{
					totalCost+=people[j].C;
				}
			}
			else if(people[j].P!=1)
			{
				totalCost+=people[j].C;	
			}
		}
		ans=min(ans,totalCost);
	}
	cout<<ans<<endl;
	return 0;
}