#include<iostream>
using namespace std;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int x,sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        cout<<sum<<endl;
    }
    return 0;
}