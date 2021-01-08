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
vector<int> v,fl;int n;
int ck(int i){
    if(i-1>=0&&v[i-1]<v[i]&&i+1<n&&v[i+1]<v[i])
        return 1;
    if(i-1>=0&&v[i-1]>v[i]&&i+1<n&&v[i+1]>v[i])
        return 1;
    return 0;
}
void work()
{

    cin>>n;
    int tmp;
    v.clear();
    fl.clear();
    for(int i=1;i<=n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(i-1>=0&&v[i-1]<v[i]&&i+1<n&&v[i+1]<v[i]){
            ans++;
            fl.push_back(1);
        }else
        if(i-1>=0&&v[i-1]>v[i]&&i+1<n&&v[i+1]>v[i]){
            ans++;
            fl.push_back(1);
        }else fl.push_back(0);
    }
    int dis=0;
    for(int i=1;i<n-1;i++){
        int pr=0;
        for(int j=i-1;j<=i+1;j++)
            pr+=fl[j];
        int now1=0,now2=0;
        int t=v[i];
        v[i]=v[i-1];
        for(int j=i-1;j<=i+1;j++)
            now1+=ck(j);
        v[i]=v[i+1];
        for(int j=i-1;j<=i+1;j++)
            now2+=ck(j);
        v[i]=t;
        MAX(dis,max(pr-now1,pr-now2));
    }
    // // cout<<"ans="<<ans<<endl;
    // int ma=0;
    // for(int i=0;i<n;i++){
    //     // cout<<fl[i]<<' ';
    //     int l=0,r=0;
    //     if(i-1>=0)
    //         l=fl[i-1];
    //     if(i+1<n)
    //         r=fl[i+1];
    //     if(l!=0&&r!=0){
    //         if(l==r)
    //             MAX(ma,2+abs(fl[i]));
    //         else MAX(ma,1LL+abs(fl[i]));
    //     }else MAX(ma,abs(l+r)+abs(fl[i]));
    //     // cout<<"is="<<ma<<endl;
    // }
    cout<<ans-dis<<endl;
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