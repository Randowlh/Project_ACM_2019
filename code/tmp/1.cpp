#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
mt19937 rnd(514114);
struct fhq_treap
{
   struct node
   {
      int l, r;
      int val, key;
      int size;
   } fhq[maxn];
   int cnt, root;
   inline int newnode(int val)
   {
      fhq[++cnt].val = val;
      fhq[cnt].key = rnd();
      fhq[cnt].size = 1;
      fhq[cnt].l = fhq[cnt].r = 0;
      return cnt;
   }
   inline void pushup(int now)
   {
   fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
   }
   void split(int now, int val, int &x, int &y)
   {
      if (!now)
      {
         x = y = 0;
         return;
      }
      else if (fhq[now].val <= val)
      {
      x = now;
      split(fhq[now].r, val, fhq[now].r, y);
      }
      else
      {
      y = now;
      split(fhq[now].l, val, x, fhq[now].l);
      }
   pushup(now);
   }
   int merge(int x, int y)
   {
      if (!x || !y)
         return x + y;
      if (fhq[x].key > fhq[y].key)
      {
         fhq[x].r = merge(fhq[x].r, y);
         pushup(x);
         return x;
      }
      else
      {
         fhq[y].l = merge(x, fhq[y].l);
         pushup(y);
         return y;
      }
   }
   inline void insert(int val)
   {
      int x, y;
      split(root, val, x, y);
      root = merge(merge(x, newnode(val)), y);
   }
   inline void del(int val)
   {
      int x, y, z;
      split(root, val - 1, x, y);
      split(y, val, y, z);
      y = merge(fhq[y].l, fhq[y].r);
      root = merge(merge(x, y), z);
   }
   inline int getrk(int num)
   {
      int x, y;
      split(root, num - 1, x, y);
      int ans = fhq[x].size + 1;
      root = merge(x, y);
      return ans;
   }
   inline int getnum(int rank)
   {
      int now=root;
      while(now)
      {
         if(fhq[fhq[now].l].size+1==rank)
            break;
         else if(fhq[fhq[now].l].size>=rank)
             now=fhq[now].l;
         else
          {
            rank-=fhq[fhq[now].l].size+1;
             now=fhq[now].r;
         }
      }
      return fhq[now].val;
   }
   inline int pre(int val)
   {
      int x, y, ans;
      split(root, val - 1, x, y);
      int t = x;
      while (fhq[t].r)
         t = fhq[t].r;
      ans = fhq[t].val;
      root = merge(x, y);
      return ans;
   }
   inline int aft(int val)
   {
      int x, y, ans;
      split(root, val, x, y);
      int t = y;
      while (fhq[t].l)
         t = fhq[t].l;
      ans = fhq[t].val;
      root = merge(x, y);
      return ans;
   }
} tree;
void work()
{
    
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