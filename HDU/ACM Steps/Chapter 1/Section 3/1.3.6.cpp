#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string str;
int interval[1001];
int data[1001];
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    while(cin>>str)
    {
        int len=str.length();

        int cnt=1;
        interval[1]=-1;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='5')
            {
                interval[++cnt]=i;
            }
        }
        interval[++cnt]=len;

        int num=0;
        for(int i=1;i<cnt;i++)
        {
            int x=0;
            for(int j=interval[i]+1;j<interval[i+1];j++)
            {
                x=x*10+str[j]-'0';
            }
            if(interval[i]+1!=interval[i+1])
            {
                data[++num]=x;
            }
        }

        sort(data+1,data+1+num);

        for(int i=1;i<num;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<data[num]<<endl; 
    }
    return 0;
}