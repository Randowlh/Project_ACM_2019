#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define lowbit(x) (x&-x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 110000;
set<int> mp[maxn];
int sz[maxn];
map<int,int> M;
int f[1000];
int tog[2];
int ff=0;
pair<int,int> ut;
int cnt[101000];
int tot=0;
void dfs(int pos,int fa){
    sz[pos]=1;
    for(auto i=mp[pos].begin();i!=mp[pos].end();i++){
        int to=*i;
        if(to==fa)
            continue;
        dfs(to,pos);
        if(ff)
            return;
        for(int i=0;i<2;i++)
            if(sz[to]==tog[i])
                ff=1;
        if(ff){
            ut.first=pos;
            ut.second=to;
            cnt[to]=sz[to];
            cnt[pos]=tot-sz[to];
            mp[pos].erase(to);
            mp[to].erase(pos);
            return;
        }
        sz[pos]+=sz[to];
    }
}
void work()
{
    f[1]=1;
    f[2]=1;
    for(int i=3;i<10000;i++){
        f[i]=f[i-1]+f[i-2];
        M[f[i]]=i;
        if(f[i]>1000000)
            break;
    }
    int n;
    cin>>n;
    if(M.count(n)==0){
        cout<<"NO"<<endl;
        return;
    }
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    queue<int> q;
    q.push(1);
    cnt[1]=n;
    int flag=0;
    while(!q.empty()){
        int to=q.front();
        q.pop();
        ff=0;
        tot=sz[to];
        tog[0]=f[M[cnt[to]]-2];
        tog[1]=f[M[cnt[to]]-1];
        dfs(1,-1);
        if(!ff){
            flag=1;
            break;
        }
    }
    // cout<<tog[0]<<' '<<tog[1]<<endl;
    if(!flag){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}