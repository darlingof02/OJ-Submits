#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int x;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x%2) ans*=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}