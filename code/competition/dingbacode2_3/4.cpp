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
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
struct node
{
    ll l, r;
    mutable ll v; 
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {} 
    inline bool operator<(const node &a) const { return l < a.l; } 
};
set<node> KDL;
inline auto split(int pos) {
	auto it=KDL.lower_bound(node(pos,0,0));
	if(it!=KDL.end()&&it->l==pos) return it;
	--it;
	int l=it->l,r=it->r;
	ll v=it->v;
	KDL.erase(it);
	KDL.insert(node(l,pos-1,v));
	return KDL.insert(node(pos,r,v)).first;
}

inline void assign(int l,int r,ll v) {
	auto itr=split(r+1),itl=split(l);
	KDL.erase(itl,itr);
	KDL.insert(node(l,r,v));
}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int date[110000];
pair<int,int> tpp[110000];
void work()
{
    int n,m;    
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
        rd(date[i]);
    date[n+1]=llinf;
    int pre=1;
    int now=date[1];
    for(int i=2;i<=n+1;i++){
        if(date[i]!=now){
            KDL.insert(node(pre,i-1,now));
            now=date[i];
            pre=i;
        }
    }
    int opt,l,r,x;
    for(int i=1;i<=m;i++){
        rd(opt);
        if(opt==1){
            rd(l),rd(r),rd(x);
            auto bg=split(l);
            auto ed=split(r+1);
            while(bg!=ed){
                bg->v+=x;
                bg++;
            }
        }else if(opt==2){
            rd(l),rd(r),rd(x);
            auto bg=split(l);
            auto ed=split(r+1);
            while(bg!=ed){
                bg->v^=x;
                bg++;
            }
        }else if(opt==3){
            rd(l),rd(r),rd(x);
            assign(l,r,x);
        }else if(opt==4){
            rd(l),rd(r);
            int ans=0;
            auto bg=split(l);
            auto ed=split(r+1);
            while(bg!=ed){
                ans=(ans+(bg->r-bg->l+1)*bg->v%mod)%mod;
                bg++;
            }
            wt(ans),pt('\n');
        }else if(opt==5){
            rd(l),rd(r);
            vector<int> v;
            auto bg=split(l);
            auto ed=split(r+1);
            int tail=0;
            while(bg!=ed){
                tpp[++tail]=make_pair(bg->v,bg->r-bg->l+1);
                bg++;
            }
            int flag=(r-l+1)%2;
            sort(tpp+1,tpp+tail+1);
            int to=(r-l+2)/2;
            for(int i=1;i<=tail;i++){
                to-=tpp[i].second;
                if(to<=0){
                    if(flag){
                        if(to==0){
                            wt((tpp[i].first+tpp[i+1].first)/2),pt('\n');
                        }else wt(tpp[i].first),pt('\n');
                        break;
                    }else{
                        wt(tpp[i].first),pt('\n');
                        break;
                    }
                }
            }
        }else if(opt==6){
            rd(l),rd(r),rd(x);
            auto bg=split(l);
            auto ed=split(r+1);
            int ans=0;
            while(bg!=ed){
                ans=(ans+powmod(x,bg->v)%mod*(bg->r-bg->l+1)%mod)%mod;
                bg++;
            }
            wt(ans),pt('\n');
        }
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
