#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int k;
int ans[14];
int target;
struct Seg_Tree
{
    int value;
    int L;
    int R;
}node[1000];
void Build_Seg_Tree(int now,int L,int R)
{
    node[now].L=L;
    node[now].R=R;
    if(L==R)
    {
        node[now].value=1;
        return;
    }
    int mid=(L+R)>>1;
    Build_Seg_Tree(now<<1,L,mid);
    Build_Seg_Tree(now<<1|1,mid+1,R);
    node[now].value=node[now<<1].value+node[now<<1|1].value;
}
void query(int now,int pos)
{
    if(node[now].L==node[now].R)
    {
        node[now].value=0;
        target=node[now].L;
        return;
    }
    if(pos<=node[now<<1].value)
    {
        query(now<<1,pos);
    }
    else
    {
        query(now<<1|1,pos-node[now<<1].value);
    }
    node[now].value=node[now<<1].value+node[now<<1|1].value;
}
bool check(int m)
{
    Build_Seg_Tree(1,1,2*k);
    int now=1;
    while(node[1].value>k)
    {
        now=(now+m-1)%node[1].value;
        if(!now) now=node[1].value;
        query(1,now);
        if(target<=k) return false;
    }
    return true;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&k))
    {
        if(!k) break;
        if(ans[k]) 
        {
            cout<<ans[k]<<endl;
            continue;
        }
        int baseL=k+1,baseR=2*k;
        for(int base=0;;base+=2*k)
        {
            for(int m=base+baseL;m<=base+baseR;m++)
            {
                if(check(m))
                {
                    ans[k]=m;
                    break;
                }
            }
            if(ans[k])
            {
                break;
            }
        }
        cout<<ans[k]<<endl;
    }
    return 0;
}