#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n;
bool check_prime(int x)
{
    if(x==2) return true;
    for(int i=2;i<=sqrt(x)+1;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%d",&n))
    {
        int ans=0;
        int x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(check_prime(x))
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}