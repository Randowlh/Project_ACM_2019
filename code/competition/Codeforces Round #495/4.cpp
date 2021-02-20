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
int b[][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct lo{
   int x,y,v;
   lo(){}
   lo(int a,int b,int c):x(a),y(b),v(c){}
};
bool ck(int x,int y,int n,int m){
   if(x<1||x>n)
      return false;
   if(y<1||y>m)
      return false;
   return true;
}
int date[2100000];
int ttt[2100000];
int mp[2100000];
void work()
{
   int n;
   cin>>n;
   int tmp;
   int ma=0;
   for(int i=1;i<=n;i++){
      cin>>tmp;
      MAX(ma,tmp);
      date[tmp]++;
   }
   int x=0;
   int now=4;
   for(int i=1;i<=n;i++){
      if(date[i]!=now){
         x=i;
         break;
      }
      now+=4;
   }
   // cout<<"x="<<x<<endl;
   for(int i=x;n/i>=x;i++){
      // cout<<"i="<<i<<endl;
      if(n%i==0){
         int nn=i,mm=n/i;
         // cout<<"ma="<<ma<<endl;
         int y=nn+mm-x-ma;
         // if(y<1||y>mm)
            // continue;
         // cout<<nn<<' '<<mm<<' '<<x<<' '<<y<<endl;
         if(!ck(x,y,nn,mm))
            continue;
         queue<lo> q;
         q.push(lo(x,y,0));
         mp[x*mm+y]=nn;
         for(int i=0;i<=ma;i++)
            ttt[i]=0;
         while(!q.empty()){
            lo tt=q.front();
            ttt[tt.v]++;
            // cout<<tt.x<<' '<<tt.y<<' '<<tt.v<<endl;
            q.pop();
            for(int i=0;i<4;i++){
               if(ck(tt.x+b[i][0],tt.y+b[i][1],nn,mm)&&mp[(tt.x+b[i][0])*mm+tt.y+b[i][1]]!=nn){
                  q.push(lo(tt.x+b[i][0],tt.y+b[i][1],tt.v+1));
                  mp[(tt.x+b[i][0])*mm+tt.y+b[i][1]]=nn;
               }
            }
         }
         int flag=0;
         for(int i=0;i<=ma;i++){
            // cout<<ttt[i]<<' '<<date[i]<<endl;
            if(ttt[i]!=date[i]){
               flag=1;
               break;
            }
         }
         // return;
         if(!flag){
            cout<<nn<<' '<<mm<<endl;
            cout<<x<<' '<<y<<endl;
            return;
         }
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