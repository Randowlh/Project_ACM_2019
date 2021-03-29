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
set<int> ind;
int pre(int pos){
    auto i=ind.find(pos);
    if(i==ind.begin())
        return -1;
    i--;
    return *i;
}
void work()
{
    set<char> aa;
    ind.clear();
    multiset<char> s;
    string tmp;
    cin>>tmp;
    int n=tmp.size();
    for(int i=0;i<n;i++){
        ind.insert(i);
        s.insert(tmp[i]);
    }
    set<int> es;
    for(int i=0;i<n;i++){
        if(aa.count(tmp[i])){
            es.insert(i);
            continue;
        }
        else
            aa.insert(tmp[i]);
        while(1){
            int pr=pre(i);
            if(pr==-1||tmp[pr]>tmp[i]||s.count(tmp[pr])==1)
                break;
            s.erase(s.find(tmp[pr]));
            if(aa.find(tmp[pr])!=aa.end())
                aa.erase(aa.find(tmp[pr]));
            ind.erase(pr);
        }
    }
    for(auto i=ind.begin();i!=ind.end();i++){
        if(es.count(*i)==0)
        cout<<tmp[*i];
    }
    cout<<endl;
    // string ans;
    // for(int i=0;i<n;i++)
    //     ans.push_back('a');
    // for(char i='a';i<='z';i++){
    //     set<int> lo;
    //     set<char> aa;
    //     aa.clear();
    //     for(auto j=ind.begin();j!=ind.end();j++){
    //         if(tmp[*j]>=i&&aa.count(tmp[*j])==0){
    //             lo.insert(*j);
    //         aa.insert(tmp[*j]);
    //         }
    //     }
    //     auto j=ind.end();
    //     j--;
    //     for(;;j--){
    //         if(tmp[*j]<i&&aa.count(tmp[*j])==0){
    //             lo.insert(*j);
    //             aa.insert(tmp[*j]);
    //         }
    //         if(j==ind.begin())
    //             break;
    //     }
    //     string tt;
    //     for(auto j=lo.begin();j!=lo.end();j++)
    //         tt.push_back(tmp[*j]);
    //     // cout<<"tt="<<tt<<endl;
    //     MAX(ans,tt);
    // }
    // cout<<ans<<endl;
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