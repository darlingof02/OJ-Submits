#include <iostream>
using namespace std;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int a,b;
    while(~scanf("%d %d",&a,&b))
    {
        cout<<a+b<<endl;
    }
    return 0;
}