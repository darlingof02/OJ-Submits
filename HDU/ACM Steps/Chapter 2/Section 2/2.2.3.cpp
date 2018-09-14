#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int N;
int m,p,q;
int a[65],b[65],c[65];
bool hanoi(int n,int *a,int *c,int *b) //*a：当前n-1个盘子所在柱子 *c：目标柱子 *b：过渡柱子
{
    if(b[0]==n)
    {
        return false;
    }
    if(a[0]==n)
    {
        return hanoi(n-1,a+1,b,c);
    }
    if(c[0]==n)
    {
        return hanoi(n-1,b,c+1,a);
    }
    return true;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);

        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);

        scanf("%d",&p);
        for(int i=0;i<p;i++)
            scanf("%d",&b[i]);

        scanf("%d",&q);
        for(int i=0;i<q;i++)
            scanf("%d",&c[i]);

        a[m]=b[p]=c[q]=-1;
        if(hanoi(N,a,c,b))
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
    }
    return 0;
}