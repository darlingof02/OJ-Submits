#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N,T;
struct item
{
    int L,R;
};
item line[25001];
int cmp(item a,item b)
{
    return a.L<b.L;
}
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++)
        scanf("%d%d",&line[i].L,&line[i].R);
    sort(line,line+N,cmp);
    int temp=0,ans=0,i=0;
    while(temp<T&&i<N)
    {
        ans++;
        int top=temp;
        if(line[i].L>temp+1)
            break;
        while(line[i].L<=temp+1&&i<N)
        {
            top=max(top,line[i].R);
            i++;
        }
        temp=top;
    }
    if(temp<T)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
