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
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        scanf("%d",&p);
        for(int i=1;i<=p;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=q;i++)
            scanf("%d",&c[i]);
        hanoi()
    }
}