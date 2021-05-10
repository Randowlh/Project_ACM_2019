#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template <class T>
inline void MAX(T &x, T y)
{
   if (y > x)
      x = y;
}
template <class T>
inline void MIN(T &x, T y)
{
   if (y < x)
      x = y;
}
template <class T>
inline void rd(T &x)
{
   x = 0;
   char o, f = 1;
   while (o = getchar(), o < 48)
      if (o == 45)
         f = -f;
   do
      x = (x << 3) + (x << 1) + (o ^ 48);
   while (o = getchar(), o > 47);
   x *= f;
}
template <class T>
void wt(T x)
{
   if (x < 0)
      putchar('-'), x = -x;
   if (x >= 10)
      wt(x / 10);
   putchar('0' + x % 10);
}
#define lowbit(x) (x & -x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos << 1)
#define rson(pos) (pos << 1 | 1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rbset(T) tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
#define pii(a, b) pair<a, b>
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr = 233;
const double eps = 1e-7;
const int maxm = 1;
const int maxn = 51000;
rbset(pii(int, int)) seg[maxn << 2];
int date[maxn];
unsigned int cnt = 0;
void build(int pos, int l, int r)
{
   for (int i = l; i <= r; i++)
      seg[pos].insert(MP(date[i], ++cnt));
   if (l == r)
      return;
   int mid = (l + r) >> 1;
   build(lson(pos), l, mid);
   build(rson(pos), mid + 1, r);
}
void update(int pos, int l, int r, int x, int v)
{
   seg[pos].erase(seg[pos].lower_bound(MP(date[x], 0)));
   seg[pos].insert(MP(v, ++cnt));
   if (l == r)
      return;
   int mid = (l + r) >> 1;
   if (x <= mid)
      update(lson(pos), l, mid, x, v);
   else
      update(rson(pos), mid + 1, r, x, v);
}
int getrk(int pos, int l, int r, int ql, int qr, int k)
{
   if (ql <= l && qr >= r)
      return seg[pos].order_of_key(MP(k, 0));
   int ans = 0;
   int mid = (l + r) >> 1;
   if (ql <= mid)
      ans += getrk(lson(pos), l, mid, ql, qr, k);
   if (qr >= mid+1)
      ans += getrk(rson(pos), mid + 1, r, ql, qr, k);
   return ans;
}
int pre(int pos, int l, int r, int ql, int qr, int k)
{
   if (ql <= l && qr >= r)
   {
      auto tt = seg[pos].lower_bound(MP(k, 0));
      if (tt == seg[pos].begin())
         return -2147483647;
      return (--tt)->first;
   }
   int ans = -2147483647;
   int mid = l + r >> 1;
   if (ql <= mid)
      MAX(ans, pre(lson(pos), l, mid, ql, qr, k));
   if (qr > mid)
      MAX(ans, pre(rson(pos), mid + 1, r, ql, qr, k));
   return ans;
}
int aft(int pos, int l, int r, int ql, int qr, int k){
   if (ql <= l && qr >= r)
   {
      auto tt = seg[pos].lower_bound(MP(k + 1, 0));
      if (tt == seg[pos].end())
         return 2147483647;
      return tt->first;
   }
   int ans = 2147483647;
   int mid = (l + r) >> 1;
   if (ql <= mid)
      MIN(ans, aft(lson(pos), l, mid, ql, qr, k));
   if (qr > mid)
      MIN(ans, aft(rson(pos), mid + 1, r, ql, qr, k));
   return ans;
}
void work()
{
   int n, m;
   rd(n), rd(m);
   for (int i = 1; i <= n; i++)
      rd(date[i]);
   build(1, 1, n);
   int opt, l, r, k, pos;
   for (int i = 1; i <= m; i++)
   {
      rd(opt);
      switch (opt)
      {
      case 1:
      {
         rd(l), rd(r), rd(k);
         wt(getrk(1, 1, n, l, r, k)+1), pt('\n');
      }
      break;
      case 2:
      {
         rd(l), rd(r), rd(k);
         int bg = 0, ed = 1e8 + 1;
         while (bg ^ ed)
         {
            int mid = bg + ed >> 1;
            if (getrk(1, 1, n, l, r, mid)+1 <= k)
               bg = mid + 1;
            else
               ed = mid;
         }
         wt(bg-1), pt('\n');
      }
      break;
      case 3:{
            rd(pos), rd(k);
            update(1, 1, n, pos, k);
            date[pos] = k;
         }break;
      case 4:
         {rd(l), rd(r), rd(k);
         wt(pre(1, 1, n, l, r, k)), pt('\n');
         }break;
      case 5:
         {rd(l), rd(r), rd(k);
         wt(aft(1, 1, n, l, r, k)), pt('\n');
         }
      }
   }
}
signed main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
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
