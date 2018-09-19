#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int n;
int horizon[21];
int vertical[21];
int F[21];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    F[0]=1;
    vertical[0]=0;
    horizon[0]=2;
    for(int i=1;i<=20;i++)
    {
        horizon[i]=horizon[i-1]+vertical[i-1]*2;
        vertical[i]=F[i-1];
        F[i]=horizon[i]+vertical[i];
    }
    while(T--)
    {
        scanf("%d",&n);
        cout<<F[n]<<endl;
    }
    return 0;
}