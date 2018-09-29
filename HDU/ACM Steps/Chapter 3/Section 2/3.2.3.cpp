#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int N;
int data[1010];
int maxScore[1010];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&N))
    {
        if(!N) break;
        memset(maxScore,0,sizeof(maxScore));
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&data[i]);
            maxScore[i]=data[i];
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(data[j]<data[i])
                {
                    maxScore[i]=max(maxScore[i],maxScore[j]+data[i]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            ans=max(ans,maxScore[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}