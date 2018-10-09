#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-9;
int T;
double Y;
double f(double x)
{
	return 8.0*x*x*x*x + 7.0*x*x*x + 2.0*x*x + 3.0*x + 6.0;
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf",&Y);
		if(fabs(f(0)>Y)||fabs(f(100))<Y)
		{
			printf("No solution!\n");
			continue;
		}
		double L=0.0,R=100.0;
		double mid;
		while(R-L>eps)
		{
			mid=(L+R)/2.0;
			if(f(mid)<Y)
			{
				L=mid;
			}
			else if(f(mid)>=Y)
			{
				R=mid;
			}
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}