#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct item
{
    int goldMedal;
    int medal;
    int population;
    double goldMedalRatio;
    double medalRatio;
    int bestRank;
    int rankKind;
    int rank;
};
item country[10000];
int n,m;
int x;
int target[10000];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&country[i].goldMedal,&country[i].medal,&country[i].population);
            country[i].goldMedalRatio=country[i].goldMedal*1.0/country[i].population;
            country[i].medalRatio=country[i].medal*1.0/country[i].population;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&target[i]);
            target[i]++; //习惯从1开始编号
        }
        //按金牌总数排序
        for(int i=1;i<=m;i++)
        {
            int x=target[i];
            country[x].rank=1;
            for(int j=1;j<=m;j++)
            {
                int y=target[j];
                if(country[x].goldMedal<country[y].goldMedal)
                {
                    country[x].rank++;
                }
            }
            country[x].bestRank=country[x].rank;
            country[x].rankKind=1;
        }
        //按奖牌总数排序
        for(int i=1;i<=m;i++)
        {
            int x=target[i];
            country[x].rank=1;
            for(int j=1;j<=m;j++)
            {
                int y=target[j];
                if(country[x].medal<country[y].medal)
                {
                    country[x].rank++;
                }
            }
            if(country[x].rank<country[x].bestRank)
            {
                country[x].bestRank=country[x].rank;
                country[x].rankKind=2;
            }
        }
        //按金牌人口比例排序
        for(int i=1;i<=m;i++)
        {
            int x=target[i];
            country[x].rank=1;
            for(int j=1;j<=m;j++)
            {
                int y=target[j];
                if(country[x].goldMedalRatio<country[y].goldMedalRatio)
                {
                    country[x].rank++;
                }
            }
            if(country[x].rank<country[x].bestRank)
            {
                country[x].bestRank=country[x].rank;
                country[x].rankKind=3;
            }
        }
        //按奖牌人口比例排序
        for(int i=1;i<=m;i++)
        {
            int x=target[i];
            country[x].rank=1;
            for(int j=1;j<=m;j++)
            {
                int y=target[j];
                if(country[x].medalRatio<country[y].medalRatio)
                {
                    country[x].rank++;
                }
            }
            if(country[x].rank<country[x].bestRank)
            {
                country[x].bestRank=country[x].rank;
                country[x].rankKind=4;
            }
        }
        for(int i=1;i<=m;i++)
        {
            int x=target[i];
            cout<<country[x].bestRank<<":"<<country[x].rankKind<<endl;
        }
        cout<<endl;
    }
    return 0;
}