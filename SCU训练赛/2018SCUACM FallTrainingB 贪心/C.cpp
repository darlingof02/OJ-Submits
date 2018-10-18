#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define ll long long 
using namespace std;
int n;
struct object
{
	ll x;
	friend bool operator < (object a,object b)
	{
		return a.x>b.x;
	}
};
priority_queue<object>que;
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		object t;
		scanf("%lld",&t.x);
		que.push(t);
	}
	ll ans=0;
	while(!que.empty())
	{
		object a=que.top();
		que.pop();
		ans+=a.x;
		if(que.empty())
		{
			break;
		}
		object b=que.top();
		ans+=b.x;
		que.pop();
		if(que.empty())
		{
			break;
		}
		object c;
		c.x=a.x+b.x;
		que.push(c);
	}
	cout<<ans<<endl;
	return 0;
}
