#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int T[1001];
int K[1001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&T[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&K[i]);
        }
        sort(T+1,T+1+n);
        sort(K+1,K+1+n);
        int slowT=1,fastT=n;
        int slowK=1,fastK=n;
        while(slowT<=fastT&&slowK<=fastK)
        {
            if(T[slowT]<K[slowK]) //田忌最慢跑不过齐王最慢，消耗齐王最快
            {
                slowT++;
                fastK--;
                ans-=200;
                continue;
            }
            if(T[slowT]>K[slowK]) //如果田忌最慢跑得过齐王最慢
            {
                slowT++;
                slowK++;
                ans+=200;
                continue;
            }
            if(T[slowT]==K[slowK]) //如果田忌最慢和齐王最慢跑的速度一样
            {
                if(T[fastT]>K[fastK])
                {
                    fastT--;
                    fastK--;
                    ans+=200;
                    continue;
                }
                if(T[fastT]<=K[fastK])
                {
                    if(T[slowT]<K[fastK])
                    {
                        slowT++;
                        fastK--;
                        ans-=200;
                        continue;
                    }
                    if(T[slowT]==K[fastK])
                    {
                        slowT++;
                        fastK--;
                        continue;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}