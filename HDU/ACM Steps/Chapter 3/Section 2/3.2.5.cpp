#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=0x7fffffff;
int n;
int caseCount;
struct item
{
    int x;
    int y;
    int z;
    bool operator < (item &a)
    {
        return (x<a.x&&y<a.y);
    }
};
item block[1000];
int dp[1001];
void setBlock(int num,int x,int y,int z)
{
    block[num].x=x;
    block[num].y=y;
    block[num].z=z;
}
bool cmp(item a,item b)
{
    if(a.x!=b.x) return a.x>b.x;
    if(a.x==b.x&&a.y!=b.y) return a.y>b.y;
    else return a.z>b.z;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        caseCount++;
        if(!n) break;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            setBlock(++cnt,x,y,z);
            setBlock(++cnt,x,z,y);
            setBlock(++cnt,y,x,z);
            setBlock(++cnt,y,z,x);
            setBlock(++cnt,z,x,y);
            setBlock(++cnt,z,y,x);
        }
        sort(block+1,block+1+cnt,cmp);
        block[0].x=inf;
        block[0].y=inf;
        block[0].z=inf;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=cnt;i++)
            for(int j=0;j<i;j++)
                if(block[i]<block[j])
                {
                    dp[i]=max(dp[i],dp[j]+block[i].z);
                }
        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            ans=max(ans,dp[i]);
        }
        cout<<"Case "<<caseCount<<": "<<"maximum height = "<<ans<<endl;
    }
    return 0;
}