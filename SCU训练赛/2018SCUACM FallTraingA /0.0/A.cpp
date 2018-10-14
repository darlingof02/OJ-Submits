#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
char str[4];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(~scanf("%s",str))
    {
        char A=str[0];
        char B=str[1];
        char C=str[2];
        if(A<=B)
        {
            if(B<=C)
            {
                cout<<A<<" "<<B<<" "<<C<<endl;
                continue;
            }
            if(C<=B)
            {
                if(A<=C)
                {
                    cout<<A<<" "<<C<<" "<<B<<endl;
                    continue;
                }
                if(A>=C)
                {
                    cout<<C<<" "<<A<<" "<<B<<endl;
                    continue;
                }
            }
        }
        if(A>=B)
        {
            if(C>=A)
            {
                cout<<B<<" "<<A<<" "<<C<<endl;
                continue;
            }
            if(C<=A)
            {
                if(B>=C)
                {
                    cout<<C<<" "<<B<<" "<<A<<endl;
                    continue;
                }
                if(B<=C)
                {
                    cout<<B<<" "<<C<<" "<<A<<endl;
                    continue;
                }
            }
        }
    }
    return 0;
}