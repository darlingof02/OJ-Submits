#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int F[55];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    F[1]=1;
    F[2]=2;
    F[3]=3;
    for(int i=4;i<=54;i++)
    {
        F[i]=F[i-1]+F[i-3];
    }
    while(~scanf("%d",&n))
    {
        if(!n) break;
        cout<<F[n]<<endl;
    }
    return 0;
}