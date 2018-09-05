#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int C;
int n,m;
struct object
{
    int p,h;
}rice[1001];
bool cmp(const object &a,const object &b)
{
    return a.p<b.p;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&rice[i].p,&rice[i].h);
        }
        sort(rice+1,rice+1+m,cmp);

        double money=n*1.00;
        double ans=0.00;
        for(int i=1;i<=m;i++)
        {
            if(money>=rice[i].p*1.00*rice[i].h)
            {
                ans+=(rice[i].h*1.00);
                money-=(rice[i].p*1.00*rice[i].h);
                continue;
            }
            else
            {
                ans+=money/(rice[i].p*1.00);
                break;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}