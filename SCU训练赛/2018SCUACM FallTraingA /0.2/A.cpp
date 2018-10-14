#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int money[7]={0,100,50,10,5,2,1};
int n;
int calc(int x)
{
    int cnt=1;
    int sum=0;
    while(cnt<=6)
    {
        if(x>=money[cnt])
        {
            x-=money[cnt];
            sum++;
        }
        else 
        {
            cnt++;
        }
    }
    return sum;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int ans=0;
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ans+=calc(x);
        }
        cout<<ans<<endl;
    }
    return 0;
}