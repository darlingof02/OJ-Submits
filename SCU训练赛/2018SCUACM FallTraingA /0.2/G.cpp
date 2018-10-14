#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char str[10010];
char newStr[10010];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int len=strlen(str);
        int cnt=1;
        int x=0;
        while(x<len)
        {
            if(str[x]==str[x+1])
            {
                cnt++;
            }
            else
            {
                if(cnt==1)
                {
                    cout<<str[x];
                }
                else
                {
                    cout<<cnt<<str[x];
                }
                cnt=1;
            }
            x++;
        }
        cout<<endl;
    }
    return 0;
}