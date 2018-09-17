#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n;
int F[10001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    F[1]=2;
    for(int i=2;i<=10000;i++)
    {
        F[i]=F[i-1]+4*i-3;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cout<<F[n]<<endl;
    }
    return 0;
}