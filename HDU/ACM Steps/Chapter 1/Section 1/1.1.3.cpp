#include <iostream>
using namespace std;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int a,b;
    while(~scanf("%d %d",&a,&b))
    {
        if(!a&&!b) break;
        cout<<a+b<<endl;
    }
    return 0;
}