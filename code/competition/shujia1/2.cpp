#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
//#include <unordered_set>
//#include <unordered_map>
//#include <bits/stdc++.h>

#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define fi first
#define se second

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod eps=1e-11;
const lod pi=acos(-1);
const int oo=1<<30;
const ll loo=1ll<<62;
const int mods=1e9+7;
const int MAXN=30005;
const int INF=0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
struct enode{int to,c; };
vector<enode> e[MAXN],E[MAXN];
int DFN=0,n,m,Case,num,dist[MAXN],sum[MAXN],Fa[MAXN],flag[MAXN];
int dfn[MAXN],low[MAXN],fa[MAXN][15],sm[MAXN][15],dep[MAXN],Log[MAXN];
void add_edge(int x,int y,int c)
{
	// cout<<"Edge:"<<x<<"->"<<y<<endl;
	E[x].PB(((enode){y,c}));
	E[y].PB(((enode){x,c}));
}
void solve(int x,int y,int c)
{
	sum[++num]=dist[y]-dist[x]+c;
	add_edge(x,num,0);
	for (int p=y;p!=x;p=Fa[p])
	{
      // cout<<"now="<<p<<endl;
		int Dis=min(dist[p]-dist[x],sum[num]-(dist[p]-dist[x]));
		// cout<<"ddis"<<Dis<<endl;
      add_edge(p,num,Dis);
		flag[p]=(Dis==(dist[p]-dist[x]));
	}
}
void tarjan(int x,int father)
{
	dfn[x]=low[x]=++DFN,Fa[x]=father;
	for (auto V:e[x])
	{
		int v=V.to,c=V.c;
		if (!dfn[v]) dist[v]=dist[x]+c,tarjan(v,x),upmin(low[x],low[v]);
		else if (v!=father) upmin(low[x],dfn[v]);
		if (dfn[x]<low[v]) add_edge(x,v,c);
	}
	for (auto V:e[x])
	{
		int v=V.to,c=V.c;
		if (Fa[v]!=x&&dfn[v]>dfn[x]) solve(x,v,c);
	}
}
void dfs(int x,int father)
{
   // cout<<"fa["<<x<<"]="<<father<<endl;
	dep[x]=dep[father]+1;
	for (int i=1;i<=Log[dep[x]];i++) 
		fa[x][i]=fa[fa[x][i-1]][i-1],sm[x][i]=sm[fa[x][i-1]][i-1]+sm[x][i-1];
	for (auto v:E[x])
	{
		if (v.to==father) continue;
		fa[v.to][0]=x;
		sm[v.to][0]=v.c;
		dfs(v.to,x);
	}
}
int getans(int x,int y)
{
	int s=0;
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=Log[dep[x]];i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) s+=sm[x][i],x=fa[x][i];
//	cout<<x<<" "<<y<<" "<<fa[x][0]<<" "<<s<<endl;
	if (x==y) return s;
	for (int i=Log[dep[x]];i>=0;i--)
		if (fa[x][i]!=fa[y][i]) s+=sm[x][i]+sm[y][i],x=fa[x][i],y=fa[y][i];
	
//	cout<<x<<" "<<y<<" "<<fa[x][0]<<" "<<s<<endl;
	if (fa[x][0]<=n) return s+sm[x][0]+sm[y][0];
	int Dis;
	if (flag[x]^flag[y]) Dis=sm[x][0]+sm[y][0];
	else Dis=abs(sm[x][0]-sm[y][0]);
	return s+min(Dis,sum[fa[x][0]]-Dis);
}
int main()
{
   freopen("in.txt", "r", stdin);
	n=read(),m=read(),Case=read(),num=n;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),c=read();
		e[u].PB(((enode){v,c}));
		e[v].PB(((enode){u,c}));
	}
   for(int i=1;i<=n;i++)
      reverse(e[i].begin(),e[i].end());
	tarjan(1,0);
	dep[0]=-1,Log[1]=0;
	for (int i=2;i<=num;i++) Log[i]=Log[i>>1]+1;
	dfs(1,0);
	for (int i=1;i<=num;i++) cout<<"cd" <<i<<" "<<sm[i][0]<<' '<<dist[i]<<' '<<fa[i][0]<<endl;
	while (Case--)
	{
		int x=read(),y=read();
		printf("%d\n",getans(x,y));
	}
	return 0;
}