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
vector<int> mp[600000];
void work()
{
    multiset<int> ss;
    set<int> s;
    int n,m;
    cin>>n>>m;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        mp[i].push_back(tmp);
        s.insert(tmp);
    }
    int ans1=llinf,ans2=llinf;
    for(auto i=s.begin(); i != s.end(); i++){
        auto j=i;
        j++;
        if(j!=s.end())
            MIN(ans2,*j-*i);
    }
    for(int i=1;i<n;i++){
        int dis=abs(mp[i][0]-mp[i+1][0]);
        MIN(ans1,dis);
        ss.insert(dis);
    }
    string opt;
    int pos,x;
    for(int i=1;i<=m;i++){
        cin>>opt;
        // cout<<"optis"<<opt<<endl;
        if(opt[0]=='i'){
            cin>>pos>>x;
            if(s.count(x))
                ans2=0;
            else{
                s.insert(x);
                auto now=s.find(x);
                if(now!=s.begin()){
                    auto tnow=now;
                    tnow--;
                    MIN(ans2,*now-*tnow);
                }
                auto tnow=now;
                tnow++;
                if(tnow!=s.end()){
                    MIN(ans2,*tnow-*now);
                }
            }
            if(pos==n)
                ss.insert(abs(mp[pos][mp[pos].size()-1]-x));
            else{
                ss.erase(ss.find(abs(mp[pos][mp[pos].size()-1]-mp[pos+1][0])));
                ss.insert(abs(mp[pos][mp[pos].size()-1]-x));
                ss.insert(abs(mp[pos+1][0]-x));
            }
            mp[pos].push_back(x);
            ans1=*ss.begin();
        }else if(opt[6]=='1'){
            cout<<ans1<<'\n';
        }else cout<<ans2<<'\n';
        // cout<<ans1<<' '<<ans2<<endl;
    }
    return;
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}