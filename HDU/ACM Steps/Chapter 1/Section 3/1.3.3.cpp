#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n;
struct object
{
    int num;
    int len;
}arrow[51];
bool cmp(const object &a,const object &b)
{
    return a.len<b.len;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&arrow[i].len,&arrow[i].num);
        }
        sort(arrow+1,arrow+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=arrow[i].num;j++)
            {
                printf(">+");
                for(int k=1;k<=arrow[i].len-2;k++)
                {
                    printf("-");
                }
                printf("+>\n");
            }
            printf("\n");
        }
    }
    return 0;
}