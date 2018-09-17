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
int sum[10001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    sum[1]=2;
    for(int i=2;i<=10000;i++)
    {
        sum[i]=sum[i-1]+6*(i-1);
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        cout<<sum[N]<<endl;
    }
    return 0;
}