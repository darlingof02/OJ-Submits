#include<iostream>
using namespace std;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        int x,sum=0;
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&x);
            sum+=x;
        }
        cout<<sum<<endl;
    }
    return 0;
}