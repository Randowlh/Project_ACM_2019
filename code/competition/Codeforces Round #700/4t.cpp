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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
set<int> s;
void work()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    int cnt=0;
    int tmp;
    int now=-1;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(now==-1||now==tmp){
            now=tmp;
            cnt++;
            if(cnt>2)
                cnt=2;
        }else{
            v.push_back(make_pair(now,cnt));
            now=tmp;
            cnt=1;
        }
    }
    v.push_back(make_pair(now,cnt));
    int s1=-1;
    int la=-1;
    int lat=0;
    int ans=0;
    cnt=0;
    s.clear();
    for(int i=0;i<v.size();i++){
        if(v[i].second==2){
            int tt=v[i].first;
            if(la==-1){
                if(tt!=s1)
                    ans+=2;
                s1=tt;
                continue;
            }
            int  cnt=0;
            int ff=0;
            if(la!=tt){
                ans++;
                cnt++;
                if(lat){
                    ans++;
                    s.clear();
                    s1=tt;
                    la=-1;
                    continue;
                }
            }
            if(s1!=tt||s.size()-s.count(tt)-(la!=tt)>0){
                ans++;
                cnt++;
            }
            if(cnt){
                s.clear();
                s1=tt;
                la=-1;
            }
            s.insert(tt);
            lat=1;
            la=tt;
        }else{
            lat=0;
            s.insert(v[i].first);
            la=v[i].first;
            ans++;
        }
    }
    cout<<ans<<endl;
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