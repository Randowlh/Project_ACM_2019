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
int gcd(int a, int b){ return b ? gcd(b, a % b):a;}
int date[110000];
set<int> s;
int getpre(int pos){
    if(s.size()==1)
        return 0;
    auto i=s.find(pos);
    if(i==s.begin())
        return *s.rbegin();
    i--;
    return *i;
}
int getaf(int pos){
    if(s.size()==1)
        return 0;
    auto i=s.find(pos);
    if(*i==*s.rbegin())
        return *s.begin();
    i++;
    return *i;
}
void work()
{
    s.clear();
    int n;
    cin>>n;
    int tmp;
    date[0]=100;
    for(int i=1;i<=n;i++){
        cin>>date[i];
        s.insert(i);
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(gcd(date[i],date[i%n+1])==1){
            q.push(i%n+1);
            // cout<<"i%n+1 "<<i%n+1<<endl;
            i++;
        }
    }
    while(!q.empty()){
        // for(auto i=s.begin();i!=s.end();i++)
            // cout<<*i<<'('<<date[*i]<<')'<<' ';
        // cout<<endl;
        int t=q.front();
        // cout<<"t="<<t<<' '<<getpre(t)<<' '<<getaf(t)<<endl;
        q.pop();
        if((s.size()==1&&date[t]==1)||gcd(date[getpre(t)],date[t])==1)
            ans.push_back(t);
        else continue;
        if(s.size()==1)
            continue;
        if(gcd(date[getpre(t)],date[getaf(t)])==1)
            q.push(getaf(t));
        s.erase(t);
    }
    cout<<ans.size()<<' ';
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
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