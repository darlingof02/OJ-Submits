#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxN=200000;
int T;
int n;
int edgeNum;
int first[maxN<<1];
int degree[maxN<<1];
int D[maxN<<1];
int F[maxN<<1];
bool vis[maxN<<1];
struct Edge{
	int next;
	int to;
	int capacity;
};
Edge e[(maxN<<2)+2];
void addEdge(int x,int y,int c){
	edgeNum++;
	e[edgeNum].next=first[x];
	e[edgeNum].to=y;
	e[edgeNum].capacity=c;
	first[x]=edgeNum;
}
void calcD(int now){
	vis[now]=true;
	for(int i=first[now];i;i=e[i].next){
		int next=e[i].to;
		if(!vis[next]){
			calcD(next);
			if(degree[next]==1){
				D[now]+=e[i].capacity;
			}
			else{
				D[now]+=min(D[next],e[i].capacity);
			}
		}
	}
}
void calcF(int now){
	vis[now]=true;
	for(int i=first[now];i;i=e[i].next){
		int next=e[i].to;
		if(!vis[next]){
			if(degree[now]==1){
				F[next]=e[i].capacity+D[next];
			}
			else{
				F[next]=D[next]+min(F[now]-min(D[next],e[i].capacity),e[i].capacity);
			}
			calcF(next);
		}
	}
}
void init(){
	edgeNum=0;
	memset(e,0,sizeof(e));
	memset(first,0,sizeof(first));
	memset(degree,0,sizeof(degree));
	memset(D,0,sizeof(D));
	memset(F,0,sizeof(F));
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int x,y,c;
			scanf("%d %d %d",&x,&y,&c);
			addEdge(x,y,c);
			addEdge(y,x,c);
			degree[x]++;
			degree[y]++;
		}
		memset(vis,false,sizeof(vis));
		calcD(1);  //假设1为根节点
		memset(vis,false,sizeof(vis));
		F[1]=D[1];
		calcF(1);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,F[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
