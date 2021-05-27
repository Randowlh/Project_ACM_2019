#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxn = 210000;
vector<int> mp[maxn];
int n;
int sz[maxn];
int faa[maxn];
int ans[maxn];
int aa[maxn];
int dep[maxn];
int flag[maxn];
int tl,tr;
int l,r;
set<int> s;
void getsz(int pos,int fa,int step){
    dep[pos]=step;
    sz[pos]=1;
    faa[pos]=fa;
    for(int i=0;i<mp[pos].size();i++){
        int to=mp[pos][i];
        if(to==fa)
            continue;
        getsz(to,pos,step+1);
        sz[pos]+=sz[to];
    }
}
int find(int pos,int fa,int ff){
    if(pos==ff){
        s.insert(pos);
        flag[pos]=1;
        return pos;
    }
    for(int i=0;i<mp[pos].size();i++){
        int to=mp[pos][i];
        if(to==fa)
            continue;
        if(flag[to])
            continue;
        int t=0;
        if(t=find(to,pos,ff)){
            s.insert(pos);
            flag[pos]=1;
            return pos==0?t:pos;
        }
    }
    return 0;
}
void work()
{
    s.clear();
    cin>>n;
    int u,v;
    for(int i=0;i<n;i++)
        mp[i].clear();
    for(int i=0;i<=n;i++)
        ans[i]=flag[i]=0;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    getsz(0,-1,1);
    ans[0]=n*(n-1)/2;
    l=r=0;
    tl=tr=sz[0];
    
    ans[1]=ans[0];
    for(int i=0;i<mp[0].size();i++){
        ans[1]-=sz[mp[0][i]]*(sz[mp[0][i]]-1)/2;
    }
    s.insert(0);
   
    for(int i=2;i<=n;i++){
        if(s.count(i-1)==0){
            int t=0;
            if(dep[l]<dep[r]){
                swap(l,r);
                swap(tl,tr);
            }
            if(t=find(l,faa[l],i-1)){
                l=i-1;
                tl=sz[i-1];
                    MIN(tr,sz[0]-sz[t]);
            }else if(t=find(r,faa[r],i-1)){
                r=i-1;
                tr=sz[i-1];
                if(l==0)
                    MIN(tl,sz[0]-sz[t]);
            }else
                break;
        }
        ans[i]=tl*tr;
    }
    int tot=0;
    for(int i=n;i>=0;i--){
        aa[i]=ans[i]-tot;
        tot=ans[i];
    }
    for(int i=0;i<=n;i++){
        cout<<aa[i]<<' ';
    }
    cout<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}