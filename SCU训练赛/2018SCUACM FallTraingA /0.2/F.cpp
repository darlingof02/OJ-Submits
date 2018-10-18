#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct item
{
    int candyCount;
    int nextCandyCount;
};
item people[1000];
int n;
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(people[i].candyCount!=people[1].candyCount)
        {
            return false;
        }
    }
    return true;
}
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
            scanf("%d",&people[i].candyCount);
        }
        while(!check())
        {
            ans++;
            for(int i=2;i<=n;i++)
            {
                people[i].nextCandyCount=people[i].candyCount/2+people[i-1].candyCount/2;
            }
            people[1].nextCandyCount=people[1].candyCount/2+people[n].candyCount/2;
            for(int i=1;i<=n;i++)
            {
                people[i].candyCount=people[i].nextCandyCount;
                if(people[i].candyCount%2)
                {
                    people[i].candyCount++;
                }
            }
        }
        cout<<ans<<" "<<people[1].candyCount<<endl;
    }
    return 0;
}