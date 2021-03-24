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
pair<int,int> date[210000];
void work()
{
    int n;
    cin>>n;
    if(n==2){
        cout<<1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cin>>date[i].first;
        date[i].second=i;
    }
    sort(date+1,date+n+1);
    map<int,int> M;
    for(int i=1;i<n;i++)
        M[date[i+1].first-date[i].first]++;
    int mix=0,ma=0;
    if(M.size()==1){
        cout<<date[1].second<<endl;
        return;
    }
    if(M.size()==2){
        set<int> s;
        for(int i=2;i<n;i++){
            s.insert(date[i+1].first-date[i].first);
        }
        if(s.size()==1){
            cout<<date[1].second<<endl;
            return;
        }
        s.clear();
        for(int i=1;i<n-1;i++){
            s.insert(date[i+1].first-date[i].first);
        }
        if(s.size()==1){
            cout<<date[n].second<<endl;
            return;
        }
    }
    vector<int> mixs;
    for(auto i=M.begin();i!=M.end();i++){
        if(ma==i->second)
            mixs.push_back(i->first);
        if(ma<i->second){
            ma=i->second;
            mixs.clear();
            mixs.push_back(i->first);
        }
    }
    if(mixs.size()>2&&ma>=2){
        cout<<-1<<endl;
        return;
    }
    if(mixs.size()==2&&ma>2){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<mixs.size();i++){
        mix=mixs[i];
        int flag=0;
        for(int i=1;i<n;i++){
            if(date[i+1].first-date[i].first!=mix){
                if(!flag)
                    flag=i+1;
                else {flag=llinf;break;}
                if(i+2<=n&&date[i+2].first-date[i].first!=mix){
                    flag=llinf;
                    break;
                }
                i++;
            }
        }
        if(flag!=llinf){
            cout<<date[flag].second<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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