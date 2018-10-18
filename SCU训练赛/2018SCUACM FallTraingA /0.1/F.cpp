#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int map[31][31];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    map[1][1]=1;
    for(int i=2;i<=30;i++)
    {
        for(int j=1;j<=i;j++)
        {
            map[i][j]=map[i-1][j-1]+map[i-1][j];
        }
    }
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                cout<<map[i][j]<<" ";
            }
            cout<<map[i][i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}