#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
string str;
priority_queue<int>que;
int data[1001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(cin>>str)
    {
        int len=str.length();
        int x=0;
        int cnt=0;
        int st=0;
        while(str[st]=='5')
        {
            st++;
        }
        for(int i=st;i<len;i++)
        {
            if(str[i]!='5')
            {
                x=x*10+str[i]-'0';
            }
            else
            {
                que.push(x);
                x=0;
            }
        }
        if(str[len-1]!='5')
        {
            que.push(x);
        }
        while(!que.empty())
        {
            data[++cnt]=que.top();
            que.pop();
        }
        for(int i=cnt;i>=1;i--)
        {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}