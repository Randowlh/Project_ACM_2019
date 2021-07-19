#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
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
#define pow powmod
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
const double pi= acos(-1);
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
struct node{
    double x,y,z;
    node(double a,double b,double c):x(a),y(b),z(c){}
    node(){}
};
double getr(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double qiuq(double r,double h){
    return pi*h*h*(r-h/3);
}
void work()
{
    node a,b,c,d;
    cin>>a.x>>a.y>>a.z;
    cin>>b.x>>b.y>>b.z;
    cin>>c.x>>c.y>>c.z;
    cin>>d.x>>d.y>>d.z;
    swap(a,b);
    swap(c,d);
    double k1,k2;
    cin>>k1>>k2;
    node pnt1=node((a.x*k1+b.x)/(k1+1),(a.y*k1+b.y)/(k1+1),(a.z*k1+b.z)/(k1+1));
    node pnt2=node((a.x-b.x)/(k1-1)+a.x,(a.y-b.y)/(k1-1)+a.y,(a.z-b.z)/(k1-1)+a.z);
    double r1=getr(pnt1,pnt2);
    r1/=2;
    node xin1=node((pnt1.x+pnt2.x)/2,(pnt1.y+pnt2.y)/2,(pnt1.z+pnt2.z)/2);
    node pnt3=node((c.x*k2+d.x)/(k2+1),(c.y*k2+d.y)/(k2+1),(c.z*k2+d.z)/(k2+1));
    node pnt4=node((c.x-d.x)/(k2-1)+c.x,(c.y-d.y)/(k2-1)+c.y,(c.z-d.z)/(k2-1)+c.z);
    double r2=getr(pnt3,pnt4);
    r2/=2;
    node xin2=node((pnt3.x+pnt4.x)/2,(pnt3.y+pnt4.y)/2,(pnt3.z+pnt4.z)/2);
    double dis=getr(xin1,xin2);
    if(r1>r2){
        swap(r1,r2);
        swap(xin1,xin2);
    }
    if(dis>r1+r2){
        cout<<0<<endl;
        return;
    }
    if(dis+r1<=r2){
        printf("%.7lf\n",r1*r1*r1*pi*4.0/3.0);
        return;
    }
    double p=(dis+r1+r2)/2;
    double s=sqrt(p*(p-r1)*(p-r2)*(p-dis));
    double gao=s*2/dis;
    double h2=sqrt(r2*r2-gao*gao);
    double h1=sqrt(r1*r1-gao*gao);
    if(h2>dis){
        printf("%.7lf\n",qiuq(r1,h1+r1)+qiuq(r2,r2-h2));
        return;
    }
    h1=r1-h1;
    h2=r2-h2;
    printf("%.7lf\n",qiuq(r2,h2)+qiuq(r1,h1));
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
cin>>t;
while (t--)
{
work();
}
return 0;
}