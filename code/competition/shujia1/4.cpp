#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
	x=0;char o,f=1;
	while(o=getchar(),o<48)if(o==45)f=-f;
	do x=(x<<3)+(x<<1)+(o^48);
	while(o=getchar(),o>47);
	x*=f;
}
const int M=1e5+5;
int n,m,tot,head[M],to[M<<1],nxt[M<<1];
inline void add_edge(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
}
int dfsid,fa[M],dfn[M],bot[M];
int all,from[M];
int dp[M][3][3][2],DP[8][3][3][2],tmp[8][3][3][2];
//dp[i][j][k][t] i的子树，i-fa[i]的权值为j，i-fa[i]所在的环的非树边为k，环的和为t
bool check(int s,int x){
	if((s&1<<0)&&x==1)return 1;
	if((s&1<<1)&&x==0)return 1;
	if((s&1<<2)&&x==2)return 1;
	return 0;
}
void dfs(int x,int f){
	fa[x]=f;
	dfn[x]=++dfsid;
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(y==f)continue;
		if(!dfn[y])dfs(y,x);
		else if(dfn[y]<dfn[x]){
			all++;
			bot[x]=1;
			for(int k=x;k!=y;k=fa[k]){
				if(from[k]){puts("-1");exit(0);}
				from[k]=all;
			}
		}
	}
	memset(DP,63,sizeof(DP));
	if(bot[x]){
		for(int j=0;j<3;j++)for(int k=0;k<3;k++){
			if((j+k)%3==1)continue;
			DP[(1<<j)|(1<<k)][j][k][(j+k)%2]=j+k;
		}
	}
	else{
		for(int j=0;j<3;j++)DP[1<<j][j][0][j]=j;
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if(fa[y]!=x)continue;
		memset(tmp,63,sizeof(tmp));
		for(int s=0;s<8;s++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int t=0;t<2;t++){
			if(DP[s][j][k][t]>1e9)continue;
			for(int a=0;a<3;a++)for(int b=0;b<3;b++)for(int c=0;c<2;c++){
				if(dp[y][a][b][c]>1e9)continue;
				if(check(s,a))continue;
				if(from[y]==0){
					MIN(tmp[s|1<<a][j][k][t],DP[s][j][k][t]+dp[y][a][b][c]);
				}
				else if(from[y]!=from[x]){
					if(check(s,b))continue;
					if((a+b)%3==1)continue;
					if(c==0)continue;
					MIN(tmp[s|1<<a|1<<b][j][k][t],DP[s][j][k][t]+dp[y][a][b][c]);
				}
				else if(from[y]==from[x]){
					MIN(tmp[s|1<<a][j][b][(c+j)%2],DP[s][j][k][t]+dp[y][a][b][c]);
				}
			}
		}
		for(int s=0;s<8;s++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int t=0;t<2;t++)DP[s][j][k][t]=tmp[s][j][k][t];
	}
	for(int s=0;s<8;s++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int t=0;t<2;t++)MIN(dp[x][j][k][t],DP[s][j][k][t]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("jiedai.in","r",stdin);
#endif
	memset(dp,63,sizeof(dp));
	rd(n),rd(m);
	for(int i=1;i<=m;i++){
		int a,b;
		rd(a),rd(b);
		add_edge(a,b);
		add_edge(b,a);
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(!dfn[i]){
		dfs(i,0);
		int res=1e9;
		for(int j=0;j<3;j++)for(int k=0;k<3;k++)for(int t=0;t<2;t++)MIN(res,dp[i][j][k][t]-j);
		if(res==1e9){ans=-1;break;}
		ans+=res;
	}
	printf("%d\n",ans);
	return 0;
}