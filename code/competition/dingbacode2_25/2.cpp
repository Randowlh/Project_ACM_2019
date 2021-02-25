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
const ll llinf = 372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int dis[][7]={ {1,1,1,0,1,1,1},
            {0,1,0,0,1,0,0},
            {0,0,1,0,0,1,0},
            {1,0,1,1,1,0,1},
            {1,0,1,1,0,1,1},
            {0,1,1,1,0,1,0},
            {1,1,0,1,0,1,1},
            {1,1,0,1,1,1,1},
            {1,0,1,0,0,1,0},
            {1,1,1,1,1,1,1},
            {1,1,1,1,0,1,1}
};
int cnt[]={6,2,5,5,4,5,6,3,7,6};
int getdis(int a,int b){
    if(a==b)
        return 0;
    if(a==1){
        if(b!=0)
            b++;
        int tt=0,ans=llinf;
        for(int i=1;i<=2;i++){
            tt=0;
            for(int j=0;j<7;j++)
                if(dis[i][j]!=dis[b][j])
                    tt++;  
            MIN(ans,tt);
        }
        return ans;
    }
    if(b==1){
        if(a!=0)
            a++;
        int tt=0,ans=llinf;
        for(int i=1;i<=2;i++){
            tt=0;
            for(int j=0;j<7;j++)
                if(dis[i][j]!=dis[a][j])
                    tt++;  
            MIN(ans,tt);
        }
        return tt;
    }
    if(a!=0)
        a++;
    if(b!=0)
        b++;
    int ans=0;
    for(int i=0;i<7;i++)
        ans+=(dis[a][i]!=dis[b][i]);
    return ans;
}
int disdis(int a,int b){
    int cnt1=0,cnt2=0;
    int ta=a,tb=b;
    while(ta){
        cnt1++;
        ta/=10;
    }
    while(tb){
        cnt2++;
        tb/=10;
    }
    if(cnt1!=cnt2)
        return llinf;
    int ans=0;
    while(a){
        ans+=getdis(a%10,b%10);
        a/=10;
        b/=10;
    }
    return ans;
}
int tot=0;
bool ck(int a,int b){
    int c=a+b;
    int ttl=0;
    int ta=a,tb=b,tc=c;
    while(ta){
        ttl+=cnt[ta%10];
        ta/=10;
    }
    while(tb){
        ttl+=cnt[tb%10];
        tb/=10;
    }
    while(tc){
        ttl+=cnt[tc%10];
        tc/=10;
    }
    return tot==ttl;
}
void work()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ta=a,tb=b,tc=c;
    while(ta){
        tot+=cnt[ta%10];
        ta/=10;
    }
    while(tb){
        tot+=cnt[tb%10];
        tb/=10;
    }
    while(tc){
        tot+=cnt[tc%10];
        tc/=10;
    }
    int ans=llinf;
    for(int i=1;i<=999;i++)
        for(int j=1;j+i<=999;j++){
            if(!ck(i,j))
                continue;
            int tt=disdis(i,a)+disdis(j,b)+disdis(i+j,c);
            // if(ans>tt){
            //     cout<<tt<<' '<<endl;
            //     cout<<i<<' '<<j<<' '<<i+j<<endl;
            // }
            MIN(ans,tt);
        }   
    cout<<ans/2<<endl;
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