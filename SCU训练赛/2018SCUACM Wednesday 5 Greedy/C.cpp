#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int cnt;
char map[101][101];
bool flag[101][101];
struct Point
{
	int x;
	int y;
	int r;
};
Point star[100001];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>map[i][j];
			flag[i][j]=(map[i][j]=='.')?false:true;
		}
	}
	for(int i=2;i<=n-1;i++)
	{
		for(int j=2;j<=m-1;j++)
		{
			if(map[i][j]=='*')
			{
				int radius=1;
				while(i-radius>=1&&i+radius<=n&&j-radius>=1&&j+radius<=m)
				{
					if(map[i-radius][j]=='*'&&map[i+radius][j]=='*'&&map[i][j-radius]=='*'&&map[i][j+radius]=='*')
					{
						flag[i][j]=false;
						flag[i-radius][j]=false;
						flag[i+radius][j]=false;
						flag[i][j-radius]=false;
						flag[i][j+radius]=false;
						radius++;
					}
					else
					{
						break;
					}
				}
				if(radius>=2)
				{
					cnt++;
					star[cnt].x=i;
					star[cnt].y=j;
					star[cnt].r=radius-1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]=='*'&&flag[i][j]==true)
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<star[i].x<<" "<<star[i].y<<" "<<star[i].r<<endl;
	}
	return 0;
}