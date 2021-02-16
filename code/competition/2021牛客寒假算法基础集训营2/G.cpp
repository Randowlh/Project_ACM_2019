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
const int maxn = 510000;
int n,m,sz;
int tree[410000];
vector<int> v;
pair<int,int> opt[110000];
map<int,int> M;
void work()
{
    rd(n),rd(m);
    v.push_back(-llinf),v.push_back(1),v.push_back(n+1);
    for(int i=1;i<=m;i++){
        rd(opt[i].first),rd(opt[i].second);
        v.push_back(opt[i].first),v.push_back(opt[i].second+1);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    for(int i=1;i<v.size();i++)
        M[v[i]]=i;
    for(int i=1;i<=m;i++){
        tree[M[opt[i].first]]++;
        tree[M[opt[i].second+1]]--;
        // cout<<M[opt[i].first]<<' '<<M[opt[i].second+1]<<endl;
    }
    int now=0;
    for(int i=1;i<v.size()-1;i++){
        now+=tree[i];
        tree[i]=now;
    }
    vector<pair<int,int>> tmp,aa;
    for(int i=1;i<M[n+1];i++)
        tmp.push_back(make_pair(tree[i],v[i+1]-v[i]));
    sort(tmp.begin(),tmp.end(),greater<pair<int,int>>());
    for(int i=0;i<tmp.size();i++){
        if(i+1<tmp.size()&&tmp[i].first==tmp[i+1].first)
            tmp[i+1].second+=tmp[i].second;
        else aa.push_back(tmp[i]);
    }
    int go=(n+9)/10,sev=(n+3)/4,br=(n+1)/2;
    int a1=0,a2=0,a3=0;
    for(int i=0;i<aa.size();i++){
        if(aa[i].first==0)
            continue;
        if(a1<go){
            a1+=aa[i].second;
        }else if(a2+a1<sev){
            a2+=aa[i].second;
        }else if(a1+a2+a3<br){
            a3+=aa[i].second;
        }
    }
    cout<<a1<<' '<<a2<<' '<<a3<<endl;
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