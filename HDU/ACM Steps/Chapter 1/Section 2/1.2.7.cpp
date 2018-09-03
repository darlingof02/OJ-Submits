#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int T;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int x;
        scanf("%d",&x);
        cout<<char(x);
    }
    return 0;
}