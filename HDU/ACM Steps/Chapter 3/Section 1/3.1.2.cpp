#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int T;
int a,b;
ll F[51];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&a,&b);
        memset(F,0,sizeof(F));
        F[a]=1;
        F[a+1]=1;
        for(int i=a+2;i<=b;i++)
        {
            F[i]=F[i-1]+F[i-2];
        }
        cout<<F[b]<<endl;
    }
    return 0;
}