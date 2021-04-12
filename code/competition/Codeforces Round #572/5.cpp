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
const int maxm= 20100;
const int maxn = 10100;
struct node{
    int v,num,bq;
    node(int a,int b):v(a),num(b){}
    bool operator<(node a){
        return v>a.v;
    }
};
vector<node> opt[maxn];
vector<pair<int,int>> son[maxn];
struct aa{
    int fr,to,v;
    aa(int a,int b,int c):fr(a),to(b),v(c){}
};
int du[maxn];
vector<aa> ans;
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
int ff=0;
void dfs(int pos,int fr,int fa){
    int tot=0;
    if(du[pos]==1){
        opt[pos].push_back(node(fr,pos));
        son[pos].push_back(make_pair(pos,pos));
        return;
    }
    for(int i=head[pos];i;i=eg[i].nxt){
        int to=eg[i].to;
        if(to==fa)
            continue;
        dfs(to,eg[i].w,pos);
        if(ff)
            return;
        for(int j=0;j<opt[to].size();j++){
            node aa=opt[to][j];
            aa.bq=to;
            opt[pos].push_back(aa);
            tot+=opt[to][j].v;
        }
        for(int j=0;j<son[to].size();j++){
            son[pos].push_back(make_pair(to,son[to][j].second));
        }
    }
    if((tot-fr)%2){
        ff=1;
        return;
    }
    while(1){
        if(opt[pos].size()==1&&opt[pos][0].v>fr){
            vector<int> tt;
            int flag=0;
            for(int i=0;i<son[pos].size();i++){
                if(son[pos][i].first!=opt[pos][0].bq&&(!flag||flag!=son[pos][i].first)){
                    tt.push_back(son[pos][i].second);
                    flag=son[pos][i].first;
                }
                if(tt.size()>=2)
                    break;
            }
            if(tt.size()<2){
                ff=1;
                break;
            }
            int dis=opt[pos][0].v-fr;
            dis/=2;
            ans.push_back(aa(tt[0],tt[1],-dis));
            ans.push_back(aa(tt[0],opt[pos][0].num,dis));
            ans.push_back(aa(tt[1],opt[pos][0].num,dis));
            opt[pos][0].v=fr;
            break;
        }
        if(opt[pos][0].v<opt[pos][opt[pos].size()-1].v)
            swap(opt[pos][0],opt[pos][opt[pos].size()-1]);
        node tmp=opt[pos][opt[pos].size()-1];
        if(tmp.v>tot-fr){
            ans.push_back(aa(tmp.num,opt[pos][0].num,tot-fr));
            opt[pos][0].v-=tot-fr;
            break;
        }else{
            ans.push_back(aa(tmp.num,opt[pos][0].num,tmp.v));
            opt[pos][0].v-=tmp.v;
            tot-=tmp.v;
            opt[pos].pop_back();
        }
    }
}
void work()
{
    int n;   
    cin>>n;
    int u,v,w;
    for(int i=1;i<n;i++){
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
        du[u]++,du[v]++;
    }
    if(n==2){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<u<<' '<<v<<' '<<w<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(du[i]>1){
            dfs(i,0,-1);
            break;
        }
    }
    if(ff){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        int aa=0;
        for(int i=0;i<ans.size();i++)
            if(ans[i].v)
                aa++;
        cout<<aa<<endl;
        for(int i=0;i<ans.size();i++)
            if(ans[i].v)
                cout<<ans[i].fr<<' '<<ans[i].to<<' '<<ans[i].v<<endl;
    }
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