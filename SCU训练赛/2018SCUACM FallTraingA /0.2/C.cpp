#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int AH,AM,AS;
int BH,BM,BS;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d %d %d %d",&AH,&AM,&AS,&BH,&BM,&BS);
        int CH,CM,CS;
        CS=AS+BS;
        CM=AM+BM;
        CH=AH+BH;
        if(CS>=60)
        {
            CM+=CS/60;
            CS%=60;
        }
        if(CM>=60)
        {
            CH+=CM/60;
            CM%=60;
        }
        cout<<CH<<" "<<CM<<" "<<CS<<endl;
    }
    return 0;
}