#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	int ans=1;
	while(n){
		if(n==1){
			cout<<ans<<endl;
			break;
		}
		else if(n==2){
			cout<<ans<<" "<<ans*2<<endl;
			break;
		}
		else if(n==3){
			cout<<ans<<" "<<ans<<" "<<ans*3<<endl;
			break;
		}
		else{
			int oddNum=(n+1)>>1;
			for(int i=1;i<=oddNum;i++){
				cout<<ans<<" ";
			}
		}
		ans<<=1;
		n>>=1;
	}
	return 0;
}