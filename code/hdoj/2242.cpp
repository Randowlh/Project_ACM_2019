#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int maxm=400010;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
struct node{
	int nxt,to;
}eg[2][maxm];
int cnt1,cnt2,ecnt[2],tt,ans;
int head[2][maxn];
inline void add(int u,int v,int flag){
	ecnt[flag]++;
	eg[flag][ecnt[flag]].nxt=head[flag][u];
	eg[flag][ecnt[flag]].to=v;
	head[flag][u]=ecnt[flag];
}
int n,m;
int dfn[maxn],low[maxn],belong[maxn],vl[maxn],vl2[maxn],sz[maxn],du[maxn];
bool vis[maxn],brg[maxm];
pair<int,int> egs[maxm];
int tail;
void tarjan(int x,int fa){
	dfn[x]=low[x]=++cnt1;
	for(int i=head[0][x];i!=-1;i=eg[0][i].nxt){
		int to=eg[0][i].to;
        if(i==fa)
			continue;
		if(!dfn[to]){
			tarjan(to,i^1);
			if(low[to]>dfn[x]){
				brg[i]=brg[i^1]=1;
				egs[++tail]=make_pair(x,to);
			}
			MIN(low[x],low[to]);
		}else{
			MIN(low[x],dfn[to]);
		}
	}
}
void dfs(int x){
	vis[x]=1;
	belong[x]=cnt2;
    vl2[cnt2]+=vl[x];
	for(int i=head[0][x];i!=-1;i=eg[0][i].nxt){
		if(!vis[eg[0][i].to]&&brg[i]==0)
			dfs(eg[0][i].to);
	}
}
void dfs2(int now,int fa){
    sz[now]=vl2[now];
    for(int i=head[1][now];i!=-1;i=eg[1][i].nxt){
        int to=eg[1][i].to;
        if(to==fa)
            continue;
        dfs2(to,now);
    	MIN(ans,abs(tt-sz[to]*2)); 
		sz[now]+=sz[to];
    }
}
int main(){
    // freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF){
        tt=tail=0;
        ans=0x7FFFFFFF;
		for(int i=0;i<n;i++)
			rd(vl[i]),tt+=vl[i];
		int u,v;
		for(int i=0;i<=m*2;i++)
			brg[i]=0;
        ecnt[0]=ecnt[1]=-1;
        cnt1=cnt2=0;
		for(int i=0;i<=n;i++){
			head[1][i]=head[0][i]=-1;
			dfn[i]=vis[i]=vl2[i]=0;
		}
		for(int i=1;i<=m;i++){
			rd(u),rd(v);
            // egs[i].first=u,egs[i].second=v;
			add(u,v,0);
			add(v,u,0);
		}
		for(int i=0;i<n;i++)
            if(!dfn[i])
			    tarjan(i,-1);
		for(int i=0;i<n;i++){
			if(!vis[i]){
				cnt2++;
				dfs(i);
			}
		}
		if(cnt2==1){
            printf("impossible\n");
            continue;
        }
        for(int i=1;i<=tail;i++){
                add(belong[egs[i].first],belong[egs[i].second],1);
                add(belong[egs[i].second],belong[egs[i].first],1);
        }
        dfs2(1,-1);
        wt(ans),putchar('\n');
	}
}