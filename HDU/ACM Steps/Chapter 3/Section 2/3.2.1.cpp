#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=0x7ffffff;
int T;
int N;
int maxSum[100001];
int start[100001];
int end[100001];
int ans,ansStart,ansEnd;
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&T);
    int count=0;
    while(T--)
    {
        count++;
        scanf("%d",&N);
        int x;
        ans=-inf;
        ansStart=1;
        ansEnd=1;
        for(int i=0;i<=N;i++)
        {
            maxSum[i]=-inf;
            start[i]=i;
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&x);
            if(x>maxSum[i-1]+x)
            {
                start[i]=i;
                maxSum[i]=x;
            }
            else
            {
                start[i]=start[i-1];
                maxSum[i]=maxSum[i-1]+x;
            }
            if(ans<maxSum[i])
            {
                ans=maxSum[i];
                ansStart=start[i];
                ansEnd=i;
            }
        }
        cout<<"Case "<<count<<":"<<endl;
        cout<<ans<<" "<<ansStart<<" "<<ansEnd<<endl;
        if(T>=1) cout<<endl;
    }
    return 0;
}