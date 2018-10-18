#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a,b,c;
char graph[500][500];
void print()
{
   for(int i=1;i<=2*c+1+2*b;i++)
    {
        for(int j=1;j<=2*a+1+2*b;j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        memset(graph,0,sizeof(graph));
        scanf("%d %d %d",&a,&b,&c);

        //共2c+1+2b行 2a+1+2b列
        for(int i=1;i<=2*c+1+2*b;i++)
        {
            for(int j=1;j<=2*a+1+2*b;j++)
            {
                graph[i][j]='.';
            }
        }
        
        //画长的部分
        for(int i=1;i<=2*c+2*b+1;i+=2)
        {
            if(i<=2*b)
            {
                for(int j=2*b+2-i;j<=2*a+2*b+2-i;j+=2)
                {
                    graph[i][j]='+';
                    if(j+1<=2*a+2*b+2-i) 
                    {
                        graph[i][j+1]='-';
                    }
                }
            }
            else
            {
                for(int j=1;j<=2*a+1;j+=2)
                {
                    graph[i][j]='+';
                    if(j+1<=2*a+1) graph[i][j+1]='-';
                }
            }
        }

        //画高的部分
        for(int i=1;i<=2*a+1+2*b;i+=2)
        {
            if(i<=2*a+1)
            {
                for(int j=2*b+1;j<=2*c+1+2*b;j+=2)
                {
                    graph[j][i]='+';
                    if(j+1<=2*c+1+2*b) graph[j+1][i]='|';
                }
            }
            else
            {
                for(int j=2*b+1-(i-2*a-1);j<=2*c+1+2*b-(i-2*a-1);j+=2)
                {
                    graph[j][i]='+';
                    if(j+1<=2*c+1+2*b-(i-2*a-1))graph[j+1][i]='|';
                }
            }
        }

        //画宽的部分
        for(int i=2;i<=2*b;i+=2)
        {
            for(int j=2*b-i+2;j<=2*b-i+2+2*a;j+=2)
            {
                graph[i][j]='/';
            }
        }
        for(int i=4;i<=2*c+2;i+=2)
        {
            for(int k=0;k<b;k++)
            {
                graph[i+k*2][2*a+2*b-2*k]='/';
            }
        }
        print();
    }
    return 0;
}