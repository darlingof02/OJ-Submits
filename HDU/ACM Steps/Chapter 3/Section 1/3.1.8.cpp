#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=0x7fffffff;
int MOD=inf;
int L,M;
class Matrix
{
    public:
        int array[5][5];
        int row;  //行
        int col;  //列
        Matrix()
        {
            memset(array,0,sizeof(array));
            row=4,col=4;
            for(int i=1;i<=4;i++)
            {
                array[i][i]=1;
            }
        }
        Matrix(int R,int C)
        {
            memset(array,0,sizeof(array));
            row=R,col=C;
        }
        void clear()
        {
            memset(array,0,sizeof(array));
        }
        Matrix operator * (Matrix &B)  //C=A*B 矩阵快速幂带取模
        {
            Matrix A=(*this);
            Matrix C;
            C.clear();
            for(int i=1;i<=A.row;i++)
                for(int j=1;j<=B.col;j++)
                    for(int k=1;k<=A.col;k++)
                    {
                        C.array[i][j]+=(A.array[i][k]*B.array[k][j])%MOD;
                        C.array[i][j]%=MOD;
                    }
            C.row=A.row;
            C.col=B.col;
            return C;
        }
};
Matrix matrixQuickPower(Matrix A,int B,int C)
{
    MOD=C;
    Matrix res;
    while(B)
    {
        if(B&1) res=res*A;
        B>>=1;
        A=A*A; 
    }
    return res;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    Matrix A;
    A.clear();
    A.array[1][1]=1;A.array[1][3]=1;A.array[1][4]=1;
    A.array[2][1]=1;A.array[3][2]=1;A.array[4][3]=1;

    Matrix B(4,1);
    B.array[1][1]=6;B.array[2][1]=4;
    B.array[3][1]=2;B.array[4][1]=1;

    while(~scanf("%d %d",&L,&M))
    {
        MOD=M;
        if(L==0)
        {
            cout<<1%MOD<<endl;
        }
        else if(L==1)
        {
            cout<<2%MOD<<endl;
        }
        else if(L==2)
        {
            cout<<4%MOD<<endl;
        }
        else if(L==3)
        {
            cout<<6%MOD<<endl;
        }
        else
        {
            Matrix C=matrixQuickPower(A,L-3,M);
            int ans=0;
            for(int i=1;i<=4;i++)
            {
                ans+=(C.array[1][i]*B.array[i][1])%MOD;
                ans%=MOD;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}