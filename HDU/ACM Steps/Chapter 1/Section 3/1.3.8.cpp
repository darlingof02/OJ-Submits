#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=0x7fffffff;
int T;
int n;
struct object
{
    int l,w;
    bool flag;
}item[5001];
bool cmp(const object &a,const object &b)
{
    if(a.l<b.l) return true;
    if(a.l>b.l) return false;
    return a.w<b.w;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        int count=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&item[i].l,&item[i].w);
            item[i].flag=false;
        }
        sort(item+1,item+1+n,cmp);

        object pre;
        while(count<n)
        {
            for(int i=1;i<=n;i++)
            {
                if(!item[i].flag)
                {
                    ans++;
                    pre=item[i];
                    item[i].flag=true;
                    count++;
                    break;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(item[i].l>=pre.l&&item[i].w>=pre.w&&!item[i].flag)
                {
                    pre=item[i];
                    item[i].flag=true;
                    count++;
                    continue;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}