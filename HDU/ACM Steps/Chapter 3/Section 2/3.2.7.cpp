#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
struct item
{
    int pos;
    int time;
}
item food[100001];
int dp[100001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scand("%d",&n))
    {
        if(!n) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&food[i].pos,&food[i].time);
        }
    }
}
