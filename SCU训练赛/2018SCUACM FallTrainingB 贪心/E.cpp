#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
priority_queue<double>que;
int n;
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		double x;
		scanf("%lf",&x);
		que.push(x);
	}
	while(!que.empty())
	{
		double x=que.top();
		que.pop();
		if(que.empty())
		{
			printf("%.3f\n",x);
			return 0;
		}
		double y=que.top();
		que.pop();
		que.push(2*sqrt(x*y));
	}
	return 0;
}
