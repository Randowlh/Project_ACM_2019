ACM模板 BY Rand0w

![111](C:\Users\13037\Desktop\111.png)

## 头文件

``` c++
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
```

## 科技相关

### 快读快写

``` c++
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
```

### 指令集优化

``` c++
#pragma optimize(2)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
```

### 模拟退火

``` c++
double ans=0;
double stemp=1997;
double delta=0.997;
mt19937 rnd(233);
double calc(double x){
}
void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-14){
        double tnow=now+((rnd()<<1)-RAND_MAX)*temp;
        if(tnow<l||tnow>r){
            temp*=delta;
            continue;
        }
        double new_ans=calc(tnow);
        double de=new_ans-mx;
        if(de>0){
            now=tnow;
            ans=tnow;
            mx=new_ans;
        }else if(exp(-de/temp)*RAND_MAX>rnd()){
            now=tnow;
        }
        temp*=delta;
    }
}
void repeat(double t){
    while((double)clock()/CLOCKS_PER_SEC<t){
        SA();
    }
}

```



## 动归相关

### 数位dp

``` c++
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[10][10];
int disg[10];
int dfs(int pos, int staus, int flag)
{
    if (pos == 0)
        return staus != 0;
    if (flag && dp[pos][staus] != -1)
        return dp[pos][staus];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (i == 0)
        {
            if (staus == 0)
                ans += dfs(pos - 1, i, flag || i < num);
        }
        else if (staus % i == 0)
            ans += dfs(pos - 1, i, flag || i < num);
    }
    if (flag)
        dp[pos][staus] = ans;
    return ans;
}
int calc(int x)
{
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        x /= 10;
        cnt++;
    }
    cnt--;
    return dfs(cnt, 0, 0);
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    int t;
    while (cin >> t)
    {
        int n, m;
        for (int i = 0; i < t; i++)
        {
            cin >> n >> m;
            cout << calc(m) - calc(n - 1) << endl;
        }
    }
}
```

### 状压dp

 ``` c++
int dp[1<<20];
int lf[1<<20];
int cost[20];
int vl[20];
vector<int> mp[20];
bool ck(int i,int j){
    for(int k=0;k<mp[j].size();k++){
        if((1<<(mp[j][k]-1))&i)
        continue;
        else
        return false;
    }
    return true;
}
void work()
{
    int n,e;
    rd(n), rd(e);
    for(int i=0;i<n;i++)
        rd(vl[i]),mp[i].clear();
    for(int i=0;i<n;i++)
        rd(cost[i]);
    for(int i=0;i<n;i++){
        int tt,tmp;
        rd(tt);
        for(int j=0;j<tt;j++)
            rd(tmp),mp[i].push_back(tmp);
    }
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    lf[0]=e;
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        if(dp[i]==-1)
        continue;
        ans=max(ans,dp[i]);
        for(int j=0;j<n;j++){
            if(i&(1<<j))
            continue;
            if(ck(i,j)&&lf[i]>=cost[j]){
                dp[i|(1<<j)]=dp[i]+vl[j];
                lf[i|(1<<j)]=lf[i]-cost[j];
            }
        }
    }
    printf("%lld\n",ans);
}
 ```

### 最长上升子序列(nlogn)

``` c++
int dp[100100];
int date[100100];
int tail = 1;
int main(){
    int tmp;
    while(scanf("%d", &date[tail])!=EOF)
        tail++;
    int ans1 = 1;
    dp[1] = date[1];
    for (int i = 2; i < tail;i++){
        if(date[i]<=dp[ans1])
            dp[++ans1] = date[i];
        else{
            int pos = upper_bound(dp + 1, dp + ans1, date[i], greater<int>()) - dp;
            dp[pos] = date[i];
        }
    }
    printf("%d\n", ans1);
    int ans2 = 1;
    for (int i = 2; i < tail;i++){
        if(date[i]>dp[ans2])
            dp[++ans2] = date[i];
        else{
            int pos = lower_bound(dp + 1, dp + ans2, date[i])-dp;
            dp[pos] = date[i];
        }
    }
    printf("%d", ans2);
}
```

## 数论相关

### exgcd

``` c++
int exgcd(int a,int b,int &x,int &y){
if(b==0){
x=1;y=0;
return a;
}
int r=exgcd(b,a%b,x,y);
int temp=y;
y=x-(a/b)*y;
x=temp;
return r;
}
```

### exgcd加速版非递归

``` c++
int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
```

### 逆元

``` c++
inline int niyuan(int a,int b){ int tmp,ans;exgcd(a,b,ans,tmp);return (ans%b+b)%b;}
```

### 快速幂

``` c++
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
```

### FFT

``` c++
const double Pi=acos(-1);
int n,m,l,limit=1;
struct cp{
    double r,i;
    cp(double a=0,double b=0): r(a),i(b){}
    cp operator+(cp const &a)const{return cp(r+a.r,i+a.i);}
    cp operator-(cp const &a)const{return cp(r-a.r,i-a.i);}
    cp operator*(cp const &a)const{return cp(r*a.r-i*a.i,r*a.i+i*a.r);}
}a[5100000],b[5100000];
int tr[5100000];
void fft(cp *f,bool flag)
{
  for (int i=0;i<n;i++)
    if (i<tr[i])swap(f[i],f[tr[i]]);
  for(int p=2;p<=n;p<<=1){
    int len=p>>1;
    cp tG(cos(2*Pi/p),sin(2*Pi/p));
    if(!flag)tG.i*=-1;
    for(int k=0;k<n;k+=p){
      cp buf(1,0);
      for(int l=k;l<k+len;l++){
        cp tt=buf*f[len+l];
        f[len+l]=f[l]-tt;
        f[l]=f[l]+tt;
        buf=buf*tG;
      }
    }
  }
}
```

### NTT

``` c++
const int mod= 998244353;
const int _G=3;
inline void NTT(LL *A, int type) {
	for(int i = 0; i < limit; i++) 
		if(i < r[i]) swap(A[i], A[r[i]]);
	for(int mid = 1; mid < limit; mid <<= 1) {	
		LL Wn = fastpow( type == 1 ? G : Gi , (P - 1) / (mid << 1));
		for(int j = 0; j < limit; j += (mid << 1)) {
			LL w = 1;
			for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
				 int x = A[j + k], y = w * A[j + k + mid] % P;
				 A[j + k] = (x + y) % P,
				 A[j + k + mid] = (x - y + P) % P;
			}
		}
	}
}
```

### MTT

```c++
#include<algorithm>
#include<cstdio>
#include<cmath>
#define Maxn 100500
#define lim 32000
const long double Pi=acos(-1);
using namespace std;
inline int read()
{
  register int X=0;
  register char ch=0;
  while(ch<48||ch>57)ch=getchar();
  while(ch>=48&&ch<=57)X=X*10+(ch^48),ch=getchar();
  return X;
}
int p,tr[Maxn<<2];
struct CP
{
  long double x,y;
  CP operator + (const CP& B) const
  {return (CP){x+B.x,y+B.y};}
  CP operator - (const CP& B) const
  {return (CP){x-B.x,y-B.y};}
  CP operator * (const CP& B) const
  {return (CP){x*B.x-y*B.y,x*B.y+y*B.x};}
}P1[Maxn<<2],P2[Maxn<<2],Q[Maxn<<2];
void FFT(CP *f,int op,int n)
{
  for (int i=0;i<n;i++)
   if (i<tr[i])swap(f[i],f[tr[i]]);
  for(int p=2;p<=n;p<<=1){
    int len=p>>1;
    CP tmp=(CP){std::cos(Pi/len),op*std::sin(Pi/len)};
    for(int k=0;k<n;k+=p){
      CP buf=(CP){1,0};
      for(int l=k;l<k+len;l++){
        CP tt=buf*f[len+l];
        f[len+l]=f[l]-tt;
        f[l]=f[l]+tt;
        buf=buf*tmp;
      }//F(x)=FL(x^2)+x*FR(x^2)
       //F(W^k)=FL(w^k)+W^k*FR(w^k)
       //F(W^{k+n/2})=FL(w^k)-W^k*FR(w^k)
    }
  }
}
void times(int *f,int *g,int len,int siz)
{
  for (int i=0,sav;i<len;i++){
    P1[i]=(CP){f[i]/lim,f[i]%lim};
    P2[i]=(CP){f[i]/lim,-f[i]%lim};
    Q[i]=(CP){g[i]/lim,g[i]%lim};
  }
  for (int i=1;i<len;i++)
    tr[i]=tr[i>>1]>>1|((i&1)?len>>1:0);
  FFT(P1,1,len);FFT(P2,1,len);FFT(Q,1,len);
  for (int i=0;i<len;i++){Q[i].x/=len;Q[i].y/=len;}
  for (int i=0;i<len;i++)P1[i]=P1[i]*Q[i];
  for (int i=0;i<len;i++)P2[i]=P2[i]*Q[i];
  FFT(P1,-1,len);FFT(P2,-1,len);
  for (int i=0;i<siz;i++){
    long long a1b1=0,a1b2=0,a2b1=0,a2b2;
    a1b1=(long long)floor((P1[i].x+P2[i].x)/2+0.49)%p;
    a1b2=(long long)floor((P1[i].y+P2[i].y)/2+0.49)%p;
    a2b1=((long long)floor(P1[i].y+0.49)-a1b2)%p;
    a2b2=((long long)floor(P2[i].x+0.49)-a1b1)%p;
    f[i]=((a1b1*lim+(a1b2+a2b1))*lim+a2b2)%p;
    f[i]=(f[i]+p)%p;
  }
}
int n,m,f[Maxn<<2],g[Maxn<<2];
int main()
{
  scanf("%d%d%d",&n,&m,&p);n++;m++;
  for (int i=0;i<n;i++)f[i]=read()%p;
  for (int i=0;i<m;i++)g[i]=read()%p;
  int len=1;
  for (m=m+n-1;len<m;len<<=1);
  times(f,g,len,m);
  for (int i=0;i<m;i++)printf("%d ",f[i]);
  return 0;
}
```



### 组合数

``` c++
int pre[maxn+100];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int niyuan(int x, int mod) { return powmod(x, mod - 2); }
void init(){
    pre[0]=1;
    for(int i=1;i<=maxn;i++)
        pre[i]=pre[i-1]*i%mod;
}
int C(int n,int m){
    if(n<m)
        return 0;
    return pre[n]*powmod(pre[n-m],mod-2)%mod*powmod(pre[m],mod-2)%mod;
}
```

### 欧拉线性筛

``` c++
vector<int> primes;
bool is_prime[100000100];
void euler()
{
   is_prime[1] = 1;
   for (int i = 2; i < maxn; i++)
   {
      if (!is_prime[i])
      primes.push_back(i);
      for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
      {
         is_prime[i * primes[j]] = 1;
         if ((i % primes[j]) == 0)
            break;
      }
   }
}
```

### 矩阵快速幂

``` c++
int n;
int mod;
struct node
{
    // int n;
    int date[100][100];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                for (int k = 0; k < n; k++)
                {
                    ans = ans + date[i][k] * a.date[k][j];
                    ans %= mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                date[i][j] = a.date[i][j];
        return *this;
    }
} cst, e;
inline node pow(node x, int a, int mod)
{
    node ans = e;
    node now = x;
    while (a != 0)
    {
        if (a & 1)
        {
            ans = ans * now;
        }
        now = now * now;
        a >>= 1;
    }
    return ans;
}
```

### 高斯消元法

``` c++
double date[110][110];
bool guass(int n){
    for(int i=1;i<=n;i++){
        int mix=-1;
        for(int j=i;j<=n;j++)
            if(date[j][i]!=0){
                mix=j;break;
            }
        if(mix==-1)
            return false;
        if(mix!=i)
            for(int j=1;j<=n+1;j++)
                swap(date[mix][j],date[i][j]);
        double t=date[i][i];
        for(int j=i;j<=n+1;j++){
            date[i][j]=date[i][j]/t;
        }
        for(int j=1;j<=n;j++){
            if(date[j][i]==0||j==i)
                continue;
            double g=date[j][i]/date[i][i];
            for(int k=1;k<=n+1;k++)
                date[j][k]-=date[i][k]*g;
        }
    }                                                                         
    return true;
}
void work()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
        cin>>date[i][j];
    if(guass(n))
        for(int i=1;i<=n;i++){
            printf("%.2f\n",date[i][n+1]/date[i][i]);
        }  
    else printf("No Solution\n");
}
```

 ### 扩展中国剩余定理excrt

``` c++
int exgcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int gcd(int a, int b){ return b ? gcd(b, a % b): a;}
inline int lcm(int a, int b){ return a/gcd(a, b)*b;}
int a[110000],b[110000];
int n;
int excrt(int a[],int b[],int n)
{
    int lc=1;
    for(int i=1;i<=n;i++)
        lc=lcm(lc,a[i]);
    for(int i=1;i<n;i++){   
         int p,q,g;
        g=exgcd(a[i],a[i+1],p,q);
        int k=(b[i+1]-b[i])/g;
        q=-q;p*=k;q*=k;
        b[i+1]=a[i]*p%lc+b[i];
        b[i+1]%=lc;
        a[i+1]=lcm(a[i],a[i+1]);
    }
    return (b[n]%lc+lc)%lc;
}
```

### 拉格朗日差值

``` c++
ll n, k, x[maxn], y[maxn], ans, s1, s2;
ll powmod(ll a, ll x) {
  ll ret = 1ll, nww = a;
  while (x) {
    if (x & 1) ret = ret * nww % mod;
    nww = nww * nww % mod;
    x >>= 1;
  }
  return ret;
}
ll inv(ll x) { return powmod(x, mod - 2); }
int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", x + i, y + i);
  for (int i = 1; i <= n; i++) {
    s1 = y[i] % mod;
    s2 = 1ll;
    for (int j = 1; j <= n; j++)
      if (i != j)
        s1 = s1 * (k - x[j]) % mod, s2 = s2 * ((x[i] - x[j] % mod) % mod) % mod;
    ans += s1 * inv(s2) % mod;
    ans = (ans + mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
```

## 数据结构相关

### 左偏树（可并堆）

```c++
struct node{
    int l,r,fa,val,dis;
}lt[110000];
int find(int x){
    if(lt[x].fa==x)
        return x;
    else return lt[x].fa=find(lt[x].fa);
}
int merge(int x,int y){
    if(!x||!y)  return x+y;
    if(lt[x].val>lt[y].val||(lt[x].val==lt[y].val&&x>y))
        swap(x,y);
    lt[x].r=merge(lt[x].r,y);
    lt[lt[x].r].fa=x;
    if(lt[lt[x].l].dis<lt[lt[x].r].dis)
        swap(lt[x].l,lt[x].r);
    lt[x].dis=lt[lt[x].r].dis+1;
    return x;
}
void pop(int x){
    lt[x].val=-1;
    lt[lt[x].l].fa=lt[x].l;
    lt[lt[x].r].fa=lt[x].r;
    lt[x].fa=merge(lt[x].l,lt[x].r);
}
```

### ST表

```c++
struct st_table
{
    int date[200100];
    int mx[200100][30];
    inline void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
```

### LCT带注释现场学

```c++
const int maxn = 1e5+5;
struct Node
{
    int fa,ch[2],val,res;   //res是异或结果
    bool tag;               //翻转懒标记
}spl[maxn];
//因为被毒瘤数据卡得TLE一个点，所以全部换成了#define。都是字面意思
#define ls(x) (spl[x].ch[0])
#define rs(x) (spl[x].ch[1])
#define fa(x) (spl[x].fa)
#define ident(x,f) (rs(f)==x)       //和下面的connect都是Splay的辅助函数
#define connect(x,f,s) spl[fa(x)=f].ch[s]=x
#define update(x) spl[x].res=spl[ls(x)].res^spl[rs(x)].res^spl[x].val//here
#define ntroot(x) (ls(fa(x))==x||rs(fa(x))==x)  //判断结点是否为Splay的根
#define reverse(x) std::swap(ls(x),rs(x)),spl[x].tag^=1
inline void pushdw(int x)           //懒标记下传
{
    if(spl[x].tag)
    {
        if(ls(x)) reverse(ls(x));
        if(rs(x)) reverse(rs(x));
    }
    spl[x].tag=0;
}
void pushall(int x)                 //头递归，从上到下下传所有懒标记
{
    if(ntroot(x)) pushall(fa(x));
    pushdw(x);
}
inline void rotate(int x)           //Splay基操
{
    int f=fa(x),ff=fa(f),k=ident(x,f);
    connect(spl[x].ch[k^1],f,k);
    fa(x)=ff;
    if(ntroot(f)) spl[ff].ch[ident(f,ff)]=x;//※重要，不能忘记判断，关系到虚实边
    connect(f,x,k^1);
    update(f),update(x);
}
inline void splaying(int x)         //Splay基操，都是伸展到根结点
{
    pushall(x);                     //要先把上面的懒标记全都下传
    while(ntroot(x))
    {
        int f=fa(x),ff=fa(f);
        if(ntroot(f)) ident(f,ff)^ident(x,f)?rotate(x):rotate(f);
        rotate(x);
    }
}
inline void access(int x)           //从x到原树根结点拉一条实链
{
    for(int y=0;x;x=fa(y=x))        //y为上一个Splay的根
    {
        splaying(x);                //伸展到当前Splay的根
        rs(x)=y;                    //右儿子连上上一个Splay的根
        update(x);                  //别忘更新＞﹏＜
    }
}
inline void mkroot(int x)           //给原树换根
{
    access(x);                      //先拉实链，拉好后x一定在Splay的最右（深度最大）
    splaying(x);                    //再伸展，伸展后x必定没有右儿子
    reverse(x);                     //翻转拉出来这条实链，使深度顺序翻转
}
inline int findroot(int x)          //寻找结点在原树的根
{
    access(x);                      //先拉实链
    splaying(x);                    //再伸展
    while(ls(x))                    //因为根结点必定深度最小，所以不停往左找就OK了
    {
        pushdw(x);                  //别忘了下传，第一个儿子是没问题的但是第二个往后……
        x=ls(x);
    }
    splaying(x);                    //用来保证时间复杂度，防止卡链
    return x;
}
inline void link(int x,int y)       //连边，不保证数据合法
{
    mkroot(x);                      //换根
    if(findroot(y)==x) return;      //如果y所在的树的根结点是x，那说明两者在一棵树上
    fa(x)=y;
}
inline void cut(int x,int y)        //断边，不保证数据合法
{
    mkroot(x);                      //换根
    //? 如果y跟x不在一棵树上 or x和y之间不是紧紧挨着的，return
    //! 注意这里findroot后由于保证复杂度的一句伸展，导致刚才被换成根的x成为了Splay的根结点
    //* 又因为x在原树中是根结点，深度最小，所以在Splay中一定是x为根结点y为其右儿子
    if(findroot(y)!=x||fa(y)!=x||ls(y)) return;
    fa(y)=rs(x)=0;                  //双向断边
    update(x);                      //别忘更新＞﹏＜
}
inline void split(int x,int y)      //把x--y的路径拆出来
{
    mkroot(x);                      //换根
    access(y);                      //拉实链
    splaying(y);                    //伸展
    //? 此时y必定没有右儿子且左儿子是一条到x的实链，所以访问y就可以作任何关于这条链的操作了
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    clock_t c1 = clock();
    //======================================
    int n,m;
    read(n,m);
    //? 刚开始的时候所有点之间都没连着
    for(int i=1;i<=n;i++) read(spl[i].val);
    while(m--)
    {
        int opt,x,y;
        read(opt,x,y);
        switch(opt)
        {
        case 0:
            split(x,y);
            print(spl[y].res);      //访问y就相当于访问这条链了
            break;
        case 1:
            link(x,y);
            break;
        case 2:
            cut(x,y);
            break;
        case 3:
            splaying(x);            //注意要先伸展到根，否则会很麻烦
            spl[x].val=y;
            update(x);              //不更新也没啥问题，加不加都行
            break;
        }
    }
```

### fhq_treap

```c++
mt19937 rnd(233);
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
```

### 主席树

```c++
int n,m;
int date[200010];
int lsh[200010];
int root[200010];
int lk[200010];
map<int,int> rvs;
struct chair_man_tree{
    struct node{
        int v;
        int lson,rson;
    }tree[200010<<5];
    int tail=0;
    inline int addnode(int pos){
        tree[++tail]=tree[pos];
        return tail;
    }
    int build(int l,int r){
        int now=++tail;
        tree[now].v=0;
        if(l==r){
            return now;
        }
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int update(int pos,int l,int r,int x){
        int now=addnode(pos);
        tree[now].v++;
        if(l<r){
            int  mid=(l+r)>>1;
            if(x<=mid)tree[now].lson=update(tree[pos].lson,l,mid,x);
            else tree[now].rson=update(tree[pos].rson,mid+1,r,x);
        }
        return now;
    }
    int query(int u,int v,int l,int r,int k){
        if(l==r)
        return l;
        int x=tree[tree[v].lson].v-tree[tree[u].lson].v;
        int mid=(l+r)>>1;
        if(x>=k)
            return query(tree[u].lson,tree[v].lson,l,mid,k);
        else return query(tree[u].rson,tree[v].rson,mid+1,r,k-x);
    }
}a;
void work()
{ 
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
    rd(date[i]),lsh[i]=date[i];
    sort(lsh+1,lsh+ n + 1);
    int cnt=0;
    cnt=unique(lsh+1,lsh+n+1)- lsh-1;
    for(int i=1;i<=cnt;i++)
        rvs[lsh[i]]=i;
    a.build(1,cnt);
    for(int i=1;i<=n;i++){
        root[i]=a.update(root[i-1],1,cnt,rvs[date[i]]);
    }
    int ll,rr,kk;
    for(int i=0;i<m;i++){
        rd(ll), rd(rr), rd(kk);
        printf("%d\n",lsh[a.query(root[ll-1],root[rr],1,cnt,kk)]);
    }
}
```

### 可持久化并查集

```c++
const int maxn=110000;
const int maxm= 210000;
vector<int> root;
int n,m;
struct chair_man_tree{
    struct node{
        int lson,rson;
    }tree[maxn<<5];
    int tail=0;
    int tail2=0;
    int fa[maxn<<2];
    int depth[maxn<<2];
    inline int getnew(int pos){
        tree[++tail]=tree[pos];
        return tail;
    }
    int build(int l,int r){
        
        if(l==r){
            fa[++tail2]=l;
            depth[tail2]=1;
            return tail2;
        }
        int now=tail++;
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int query(int pos,int l,int r,int qr){
        if(l==r)
            return pos;
        int mid=(l+r)>>1;
        if(qr<=mid)
            return query(tree[pos].lson,l,mid,qr);
        else return query(tree[pos].rson,mid+1,r,qr);
    }
    int update(int pos,int l,int r,int qr,int val){
        if(l==r){
            depth[++tail2]=depth[pos];
            fa[tail2]=val;
            return tail2;
        }
        int now=getnew(pos);
        int mid=(l+r)>>1;
        if(mid>=qr)
            tree[now].lson=update(tree[now].lson,l,mid,qr,val);
        else tree[now].rson=update(tree[now].rson,mid+1,r,qr,val);
        return now;
    }
    int add(int pos,int l,int r,int qr){
        if(l==r){
            depth[++tail2]=depth[pos]+1;
            fa[tail2]=fa[pos];
            return tail2;
        }
        int now=getnew(pos);
        int mid=(l+r)>>1;
        if(mid>=qr)
            tree[now].lson=add(tree[now].lson,l,mid,qr);
        else tree[now].rson=add(tree[now].rson,mid+1,r,qr);
        return now;
    }
    int getfa(int root,int qr){
        int t=fa[query(root,1,n,qr)];
        if(qr==t)
        return qr;
        else return getfa(root,t);
    }
}t;
void merge(int a,int b){
    int f1=t.getfa(root[root.size()-1],a);
            int f2=t.getfa(root[root.size()-1],b);
            if(f1==f2){
                root.push_back(root[root.size()-1]);
                return;
            }
            int d1=t.depth[t.query(root[root.size()-1],1,n,f1)];
            int d2=t.depth[t.query(root[root.size()-1],1,n,f2)];
            int tmp;
            if(d1>d2)
                swap(f1,f2);
            tmp=t.update(root[root.size()-1],1,n,f1,f2);
            if(d1==d2)
                tmp=t.add(tmp,1,n,f2);
            root.push_back(tmp);
}
```

### 可持久化数组

```c++
int date[1100000];
vector<int> root;
struct chair_man_tree{
    struct node{
        int v;
        int lson,rson;
    }tree[20100000];
    int tail=0;
    int addnew(int now){
        tail++;
        tree[tail]=tree[now];
        return  tail;
    }
    int build(int l,int r){
        int now=tail++;
        if(l==r){
            tree[now].v=date[l];
            tree[now].lson=tree[now].rson=-1;
            return now;
        }
        int mid=(l+r)>>1;
        tree[now].lson=build(l,mid);
        tree[now].rson=build(mid+1,r);
        return now;
    }
    int update(int pos,int l,int r,int x,int val){
        int now=addnew(pos);
        if(l==r){
            tree[now].v=val;
            return now;
        }
        int mid=(l+r)>>1;
        if(x<=mid)
            tree[now].lson=update(tree[now].lson,l,mid,x,val);
        if(x>mid)
            tree[now].rson=update(tree[now].rson,mid+1,r,x,val);
        return now;
    }
    int query(int pos,int l,int r,int x){
        if(l==r)
            return tree[pos].v;
        int  mid=(l+r)>>1;
        if(x<=mid)
            return query(tree[pos].lson,l,mid,x);
        else return query(tree[pos].rson,mid+1,r,x);
    }
} a;
```

## 图论相关

### 最大流

```c++
class DC
{
public:
    struct Edge
    {
        int from,to,flow,cap;
        Edge(int fr, int t, int f, int c) : from(fr), to(t), flow(f), cap(c) {}
    };
    bool book[maxn];
    int cur[maxn],depth[maxn],n, t, s;
    vector<Edge> edge;
    vector<int> mp[maxn];
    int bfs(int s, int t)
    {
        for(int i=0;i<=n;i++)
            book[i]=0;
        queue<int> q;
        q.push(s);
        book[s] = 1;
        depth[s] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < mp[now].size(); i++)
            {
                Edge &e = edge[mp[now][i]];
                if (!book[e.to] && e.cap > e.flow)
                {
                    depth[e.to] = depth[e.from] + 1;
                    book[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
        return book[t];
    }
    int dfs(int now, int a)
    {
        if (now == t || a == 0)
            return a;
        int flow = 0;
        int f;
        for (int &i = cur[now]; i < mp[now].size(); i++)
        {
            Edge &e = edge[mp[now][i]];
            if (depth[now] + 1 == depth[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                flow += f;
                edge[mp[now][i] ^ 1].flow -= f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    int Dinic()
    {
        int ans = 0;
        while (bfs(s, t))
        {
            for(int i=0;i<=n;i++)
                cur[i]=0;
            ans += dfs(s, 0x7FFFFFFF);
        }
        return ans;
    }
    void add_edge(int from, int to, int cap)
    {
        edge.push_back(Edge(from, to, 0, cap));
        edge.push_back(Edge(to, from, 0, 0));
        mp[from].push_back(edge.size() - 2);
        mp[to].push_back(edge.size() - 1);
    }
    void init(int ss,int tt,int nn){
        s=ss,t=tt,n=nn;
        for(int i=0;i<=n;i++)
            mp[i].clear();
        edge.clear();
    }
}
```

### 费用流

``` c++
struct LCF
{
    struct Edge
    {
        int from;
        int to;
        int flow;
        int cost;
        Edge(int fr = 0, int t = 0, int f = 0, int cc = 0) : from(fr), to(t), flow(f), cost(cc) {}
    };
#define inf 0x3f3f3f3f
#define maxn 201110
    int book[maxn];
    int dis[maxn];
    int n, m, s, t, ans;
    vector<Edge> edge;
    vector<int> mp[maxn];
    void add_edge(int x, int y, int flow, int cost)
    {
        edge.push_back(Edge(x, y, flow, cost));
        edge.push_back(Edge(y, x, 0, -cost));
        mp[x].push_back(edge.size() - 2);
        mp[y].push_back(edge.size() - 1);
    }
    bool spfa()
    {
        for (int i = 0; i <= n * m + 100; i++)
        {
            dis[i] = inf;
            book[i] = 0;
        }
        dis[t] = 0;
        book[t] = 1;
        deque<int> q;
        q.push_back(t);
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            for (int i = 0; i < mp[now].size(); i++)
            {
                int to = edge[mp[now][i]].to;
                if (edge[mp[now][i] ^ 1].flow && dis[to] > dis[now] - edge[mp[now][i]].cost)
                {
                    dis[to] = dis[now] - edge[mp[now][i]].cost;
                    if (!book[to])
                    {
                        book[to] = 1;
                        if (!q.empty() && dis[to] < dis[q.front()])
                            q.push_front(to);
                        else
                            q.push_back(to);
                    }
                }
            }
            book[now] = 0;
        }
        return dis[s] < inf;
    }
    int dfs(int x, int flow)
    {
        book[x] = 1;
        if (x == t)
            return flow;
        int used = 0, a;
        for (int i = 0; i < mp[x].size(); i++)
        {
            int to = edge[mp[x][i]].to;
            if (!book[to] && edge[mp[x][i]].flow > 0 && dis[x] - edge[mp[x][i]].cost == dis[to])
            {
                a = dfs(to, min(flow - used, edge[mp[x][i]].flow));
                if (a)
                    ans += a * edge[mp[x][i]].cost, edge[mp[x][i]].flow -= a, edge[mp[x][i] ^ 1].flow += a, used += a;
                if (used == flow)
                    break;
            }
        }
        return used;
    }
    void init(int tn, int tm, int ts, int tt)
    {
        for (int i = 0; i <= tn * tm + 100; i++)
            mp[i].clear();
        edge.clear();
        n = tn;
        m = tm;
        s = ts;
        t = tt;
        ans = 0;
    }
    int cost_flow()
    {
        int flow = 0;
        while (spfa())
        {
            for (int i = 0; i <= n * m + 200; i++)
                book[i] = 0;
            flow += dfs(s, inf);
        }
        return flow;
    }
} tmp;
```

### 倍增lca

```c++
struct lca
{
#define maxn 11000
#define logmaxn ((int)log(maxn) / (int)log(2));
    vector<pair<int, int>> mp[maxn];
    int root = 1;
    int fa[maxn];
    int p[maxn][43];
    int l[maxn];
    int dis[maxn];
    void init(int n)
    {
        for (int i = 0; i <= n; i++)
            mp[i].clear();
    }
    void add_edge(int w, int u, int v = 1)
    {
        pair<int, int> x(w, v);
        mp[u].push_back(x);
        x.first = u;
        mp[w].push_back(x);
    }
    void preprocess(int n, int b = 1)
    {
        set<int> s;
        for (int i = 0; i <= n; i++)
            l[i] = -1;
        for (int i = 1; i <= n; i++)
        {
            if (s.count(find(i)) == 0)
            {
                s.insert(find(i));
                root = find(i);
                queue<int> q;
                fa[root] = -1;
                l[root] = 0;
                dis[root] = 0;
                q.push(root);
                while (!q.empty())
                {
                    int now = q.front();
                    q.pop();
                    for (int i = 0; i < mp[now].size(); i++)
                    {
                        pair<int, int> &t = mp[now][i];
                        if (l[t.first] == -1)
                        {
                            l[t.first] = l[now] + 1;
                            dis[t.first] = dis[now] + t.second;
                            fa[t.first] = now;
                            q.push(t.first);
                        }
                    }
                }
            }
        }
        for (int i = b; i < n + b; i++)
            for (int j = 0; 1 << j < n + b; j++)
                p[i][j] = -1;
        for (int i = b; i < n + b; i++)
            p[i][0] = fa[i];
        for (int j = 1; 1 << j < n + b; j++)
            for (int i = b; i < n + b; i++)
                if (p[i][j - 1] != -1)
                    p[i][j] = p[p[i][j - 1]][j - 1];
    }
    int getlca(int u, int v)
    {
        int log;
        if (l[u] < l[v])
            swap(u, v);
        for (log = 1; 1 << log <= l[u]; log++)
            ;
        log--;
        for (int i = log; i >= 0; i--)
            if (l[u] - (1 << i) >= l[v])
                u = p[u][i];
        if (u == v)
            return u;
        for (int i = log; i >= 0; i--)
            if (p[u][i] != -1 && p[u][i] != p[v][i])
                u = p[u][i], v = p[v][i];
        return fa[u];
    }
} lc;
```

### 链式前向星

```c++
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
    for(int i=0;i<=n;i++)
        head[i]=0;
    ecnt=0;
}
```

### dij

```c++
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn]
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
int n;
int dis[maxn];
void dij(int a){
   for(int i=1;i<=n;i++)
      dis[i]=llinf;
   dis[a]=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
   q.push(pair<int,int>(0,a));
   while(!q.empty()){
      pair<int,int> t=q.top();
      q.pop();
      if(dis[t.second]<t.first)
         continue;
        for(int i=head[t.second];i;i = eg[i].nxt){
            int& to=eg[i].to;
            if(eg[i].w+dis[t.second]<dis[to]){
                dis[to]=eg[i].w+dis[t.second];
                q.push(make_pair(dis[to],to));
            }
        }
    }
}
```

### SPFA

```c++
struct edge{
    int w,to,nxt;
 }eg[maxm];
 int head[maxn];
 int ecnt=0;
 inline void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].w=w;
    eg[ecnt].to=v;
    head[u]=ecnt;
 }
 inline void cl(int n){
     for(int i=0;i<=n;i++)
         head[i]=0;
     ecnt=0;
}
int n,m;
int dis[maxn];
bool vis[maxn];
int cnt[maxn];
bool spfa(int s){
     for(int i=1;i<=n;i++)
         vis[i]=cnt[i]=0,dis[i]=llinf;
     cnt[s]=vis[s]=1;
     dis[s]=0;
     queue<int> q;
     q.push(s);
     while(!q.empty()){
         int t=q.front();
         q.pop();
         vis[t]=0;
         for(int i=head[t];i;i=eg[i].nxt){
             int to=eg[i].to,w=eg[i].w;
             if(dis[to]>dis[t]+w){
                 dis[to]=dis[t]+w;
                 if(!vis[to]){
                     vis[to]=1;
                     q.push(to);
                     cnt[to]++;
                     if(cnt[to]>=n){
                         return false;
                     }
                 }
             }
         }
     }
     return true;
}
```

### 树链剖分

```c++
int n, m;
vector<int> mp[maxn];
int cnt = 0;
int rk[maxn];
int dfn[maxn], chu[maxn];
int root;
#define lson(x) (x << 1)
#define rson(x) (x << 1 | 1)
struct seg
{
    int v;
    int l;
    int r;
    int lazy;
    inline void set(int a = 0, int b = 0, int c = 0, int d = 0) { v = a, l = b, r = c, lazy = d; }
} date[4 * maxn + 100];
inline void pushup(int pos)
{
    date[pos].v = date[lson(pos)].v;
    date[pos].v += date[rson(pos)].v;
}
inline void pushdown(int pos)
{
    if (!date[pos].lazy)
        return;
    date[lson(pos)].lazy += date[pos].lazy;
    date[lson(pos)].lazy %= mod;
    date[rson(pos)].lazy += date[pos].lazy;
    date[rson(pos)].lazy %= mod;
    date[rson(pos)].v += date[pos].lazy * (date[rson(pos)].r - date[rson(pos)].l + 1) % mod;
    date[rson(pos)].v %= mod;
    date[lson(pos)].v += date[pos].lazy * (date[lson(pos)].r - date[lson(pos)].l + 1) % mod;
    date[rson(pos)].v %= mod;
    date[pos].lazy = 0;
}
void build(int pos, int l, int r)
{
    if (l == r)
    {
        date[pos].set(0, l, r);
        return;
    }
    date[pos].set(0, l, r);
    int mid = (l + r) >> 1;
    build(lson(pos), l, mid);
    build(rson(pos), mid + 1, r);
    pushup(pos);
}
void update(int pos, int l, int r, int v)
{
    if (date[pos].l >= l && date[pos].r <= r)
    {
        date[pos].lazy += v;
        date[pos].lazy %= mod;
        date[pos].v += (date[pos].r - date[pos].l + 1) * v % mod;
        date[pos].v %= mod;
        return;
    }
    int mid = (date[pos].l + date[pos].r) >> 1;
    pushdown(pos);
    if (l <= mid)
        update(lson(pos), l, r, v);
    if (r >= mid + 1)
        update(rson(pos), l, r, v);
    pushup(pos);
}
int query(int pos, int l, int r)
{
    if (date[pos].l >= l && date[pos].r <= r)
        return date[pos].v;
    pushdown(pos);
    int ans = 0;
    int mid = (date[pos].l + date[pos].r) >> 1;
    if (l <= mid)
        ans += query(lson(pos), l, r);
    if (r >= mid + 1)
        ans += query(rson(pos), l, r);
    ans %= mod;
    return ans;
}
struct node
{
    int depth, top, sz, fa, hson;
    node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) : depth(a), top(b), sz(c), fa(d), hson(e) {}
    inline void init() { depth = 0, top = 0, sz = 0, fa = 0, hson = 0; }
} tree[maxn];
int tree_build(int x, int dep)
{
    tree[x].hson = 0;
    tree[x].depth = dep;
    tree[x].sz = 1;
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] == tree[x].fa)
            continue;
        tree[mp[x][i]].fa = x;
        tree[x].sz += tree_build(mp[x][i], dep + 1);
        if (tree[mp[x][i]].sz > tree[tree[x].hson].sz)
            tree[x].hson = mp[x][i];
    }
    return tree[x].sz;
}
void tree_decomposition(int x, int top)
{
    tree[x].top = top;
    cnt++;
    dfn[x] = cnt;
    rk[cnt] = x;
    if (tree[x].hson == 0)
    {
        chu[x] = cnt;
        return;
    }
    tree_decomposition(tree[x].hson, top);
    for (int i = 0; i < mp[x].size(); i++)
    {
        if (mp[x][i] != tree[x].hson && mp[x][i] != tree[x].fa)
        {
            tree_decomposition(mp[x][i], mp[x][i]);
        }
    }
    chu[x] = cnt;
}
inline void tree_path_update(int u, int v, int w)
{
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        update(1, dfn[tree[u].top], dfn[u], w);
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    update(1, dfn[v], dfn[u], w);
}
inline int tree_path_sum(int u, int v)
{
    int tol = 0;
    while (tree[u].top != tree[v].top)
    {
        if (tree[tree[u].top].depth < tree[tree[v].top].depth)
            swap(u, v);
        tol += query(1, dfn[tree[u].top], dfn[u]);
        tol %= mod;
        u = tree[tree[u].top].fa;
    }
    if (tree[u].depth < tree[v].depth)
        swap(u, v);
    tol += query(1, dfn[v], dfn[u]);
    tol %= mod;
    return tol;
}
inline void sub_tree_add(int x, int v) { update(1, dfn[x], chu[x], v); }
inline int sub_tree_sum(int x) { return query(1, dfn[x], chu[x]); }
void work()
{
    cin >> n >> m >> root >> mod;
    int tmp;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    int u, v;
    for (int i = 0; i <= n; i++)
    {
        tree[i].init();
        mp[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    tree[1].fa = -1;
    tree_build(root, 1);
    tree_decomposition(root, root);
    build(1, 1, n);
    for (int i = 0; i < arr.size(); i++)
        update(1, dfn[i + 1], dfn[i + 1], arr[i]);
    int opr, x, y, z;
    for (int i = 0; i < m; i++)
    {
        cin >> opr;
        if (opr == 1)
        {
            cin >> x >> y >> z;
            tree_path_update(x, y, z);
        }
        else if (opr == 2)
        {
            cin >> x >> y;
            cout << tree_path_sum(x, y) << endl;
        }
        else if (opr == 3)
        {
            cin >> x >> z;
            sub_tree_add(x, z);
        }
        else if (opr == 4)
        {
            cin >> x;
            cout << sub_tree_sum(x) << endl;
        }
    }
    return;
}
```

二分图最大匹配

```c++
int n;
int mp[510][510];
int ans = 0;
int pr[510];
int book[510];
bool dfs(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (mp[x][i] && !book[i])
        {
            book[i] = 1;
            if (pr[i] == -1 || dfs(pr[i]))
            {
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
    ans = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 0; i < n; i++)
    {
        memset(book, 0, sizeof(book));
        if (dfs(i))
        {
            ans++;
        }
    }
    return;
}
```

## 字符串相关

### trie

```c++
struct trie
{
    int next[100000][2], cnt;
    bool fl[100000];
    void clear()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
        memset(fl, false, sizeof(fl));
        return;
    }
    void insert(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
        fl[p] = true;
    }
    bool find(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return fl[p];
    }
    bool check(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return (next[p][0] == 0 && next[p][1] == 0);
    }
} node;
```

### 字符串哈希

```c++
const int N = 100010;
const int P = 131;
ULL h[N], p[N];

ULL get(int l, int r)
{
    return h[r] - h[l-1] * p[r - l + 1];
}

p[0] = 1;
for(int i = 1; i <= n; i++)
{
    p[i] = p[i - 1] * P;
    h[i] = h[i - 1] * P + str[i-1];
}
```

### KMP

```c++
int nxt[210000];
inline void cal_next(string &str)
{
    nxt[0] = -1;
    int k = -1;
    for (int q = 1; q < str.size(); q++)
    {
        while (k > -1 && str[k + 1] != str[q])
            k = nxt[k];
        if (str[k + 1] == str[q])
        k = k + 1;
    nxt[q] = k;
    }
}
int KMP(string &a, string &b)
{
    cal_next(b);
    int k = -1;
    for (int i = 0; i < a.size(); i++)
    {
        while (k > -1 && b[k + 1] != a[i])
            k = nxt[k];
        if (b[k + 1] == a[i])
            k = k + 1;
        if (k == b.size() - 1)
            return i;
    }
    return -1;
}
```

