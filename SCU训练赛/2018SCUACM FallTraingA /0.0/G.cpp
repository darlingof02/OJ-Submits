#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        int ans=1;
        for(int i=1;i<n;i++)
        {
            ans=(ans+1)*2;
        }
        cout<<ans<<endl;
    }
    return 0;
}