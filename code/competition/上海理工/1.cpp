#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
const double  pi= acos(-1);
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
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
#define pii(a,b) pair<a,b>
#define X first
#define Y second
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
const double eps = 1e-9;
const int maxm= 1;
const int maxn = 510000;
double a,b,c,d;
pair<db,db> s,t; 
double calc(double len,double jiao,int flag){
    double tx=len*cos(jiao);
    double ty=len*sin(jiao);
    double ans=0;
    ans+=sqrt(abs(s.X-tx)*abs(s.X-tx)+abs(s.Y-ty)*abs(s.Y-ty));
    if(flag)
        ty=-ty;
    ans+=sqrt(abs(t.X-tx)*abs(t.X-tx)+abs(t.Y-ty)*abs(t.Y-ty));
    if(flag)
        tx=-ty;
    return ans;
}
pair<db,db> trans(pair<db,db> a,double jiao){
    double ji;
    if(fabs(a.first)<eps)
        ji=pi/2;
    else
        ji=atan(a.second/a.first);
    double len=a.first*a.first+a.second*a.second;
    len=sqrt(len);
    ji-=jiao;
    pair<db,db> ans;
    ans.first=len*cos(ji);
    ans.second=len*sin(ji);
    return ans;
}
void work()
{
    double jiao,jiao2;
    cin>>a>>b>>c>>d>>s.X>>s.Y>>t.X>>t.Y;
    if(fabs(a)<eps)
        jiao=pi/2;
    else 
        jiao=atan(b/a);
    if(fabs(c)<eps)
        jiao2=pi/2;
    else
        jiao2=atan(d/c);
    // cout<<jiao<<endl;
    // cout<<jiao2<<endl;
    if(jiao<jiao2)
        swap(jiao,jiao2);
    jiao-=jiao2;
    // cout<<"pre"<<s.X<<' '<<s.Y<<' '<<t.X<<' '<<t.Y<<endl;
    s=trans(s,jiao2);
    t=trans(t,jiao2);
    // cout<<"aft"<<s.X<<' '<<s.Y<<' '<<t.X<<' '<<t.Y<<endl;
    if(s.Y<t.Y)
        swap(s,t);
    double aa=0;
    pii(db,db) ts,tt;
    ts=trans(s,jiao);
    tt=trans(t,jiao);
    if(ts.Y>0&&t.Y<0){
        aa=sqrt(abs(s.X-t.X)*abs(s.X-t.X)+abs(s.Y-t.Y)*abs(s.Y-t.Y));
    }else
    if(ts.Y>0&&tt.Y>0){
        t.Y=-t.Y;
        aa=sqrt(abs(s.X-t.X)*abs(s.X-t.X)+abs(s.Y-t.Y)*abs(s.Y-t.Y));
    }else
    if(s.Y>0&&t.Y>0){
        // cout<<"sadasdas"<<endl;
        double l=0,r=1000;
        for(int _=0;_<10000;_++){
            double lmid=(l+r)/2.0;
            double rmid=(lmid+r)/2.0;
            double aa=calc(lmid,jiao,1);
            double bb=calc(rmid,jiao,1);
            if(aa<bb){
                r=rmid;
            }else l=lmid;
        }
        MAX(aa,calc(l,jiao,1));
        swap(s,t);
        l=0,r=1000;
        for(int _=0;_<10000;_++){
            double lmid=(l+r)/2.0;
            double rmid=(lmid+r)/2.0;
            double aa=calc(lmid,jiao,1);
            double bb=calc(rmid,jiao,1);
            if(aa<bb){
                r=rmid;
            }else l=lmid;
        }
        MAX(aa,calc(l,jiao,1));
        swap(s,t);
    }else if(s.Y>0&&t.Y<0){
        // cout<<"sssss"<<endl;
        double l=0,r=1000;
        for(int _=0;_<10000;_++){
            double lmid=(l+r)/2.0;
            double rmid=(lmid+r)/2.0;
            double aa=calc(lmid,jiao,0);
            double bb=calc(rmid,jiao,0);
            // cout<<"aa="<<aa<<' '<<bb<<endl;
            if(aa<bb){
                r=rmid;
            }else l=lmid;
        }
        // cout<<"l="<<l<<endl;
        MAX(aa,calc(l,jiao,0));
    }else{
        // cout<<"asdasdasdsa"<<endl;
        s=trans(s,jiao);
        t=trans(t,jiao);
        t.Y=-t.Y;
        aa=sqrt(abs(s.X-t.X)*abs(s.X-t.X)+abs(s.Y-t.Y)*abs(s.Y-t.Y));
    }
    printf("%.3lf\n",aa);
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
// std::ios::sync_with_stdio(false);
// cin.tie(NULL);
int t = 1;
// cin>>t;
while (t--)
{
work();
}
return 0;
}