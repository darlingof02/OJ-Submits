#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char str[10000];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int len=strlen(str);
        int ans=0;
        for(int j=0;j<len;j++)
        {
            if(str[j]>='0'&&str[j]<='9')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}