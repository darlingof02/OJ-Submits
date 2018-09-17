#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int F[31];
int T;
int n;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    F[0]=1;
    F[1]=1;
    for(int i=2;i<=30;i++)
    {
        F[i]=F[i-1]+F[i-2]*2;
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cout<<F[n]<<endl;
    }
    return 0;
}