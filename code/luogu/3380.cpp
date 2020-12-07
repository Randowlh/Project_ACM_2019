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
const int maxn = 41000;
mt19937 rnd(514114);
struct fhq_treap
{
    struct node
    {
        node* l,* r;
        int val, key;
        int size;
    };
    node* root=NULL;
    inline node* newnode(int val)
    {
        node* now=new node();
        now->val=val;
        now->key = rnd();
        now->size = 1;
        now->l = now->r = NULL;
        return now;
    }
    inline void pushup(node * now)
    {
        int l=(now->l?now->l->size:0);
        int r=(now->r?now->r->size:0);
        now->size = l + r + 1;
    }
    void split(node* now, int val, node* &x,node* &y)
    {
        if (now==NULL)
        {
            x = y = NULL;
            return;
        }
        else if (now->val <= val)
        {
            x = now;
            split(now->r, val, now->r, y);
        }
        else
        {
            y = now;
            split(now->l, val, x, now->l);
        }
        pushup(now);
    }
    node* merge(node* x,node* y)
    {
        if (x==NULL || y==NULL)
            return (!x)?y:x;
        if (x->key > y->key)
        {
            x->r = merge(x->r, y);
            pushup(x);
            return x;
        }
        else
        {
            y->l = merge(x, y->l);
            pushup(y);
            return y;
        }
    }
    inline void insert(int val)
    {
        node* x,* y;
        split(root, val, x, y);
        root = merge(merge(x, newnode(val)), y);
    }
    inline void del(int val)
    {
        node* x,* y, *z,*t;
        split(root, val - 1, x, y);
        split(y, val, y, z);
        t=y;
        y = merge(y->l, y->r);
        delete t;
        root = merge(merge(x, y), z);
    }
    inline int getrk(int num)
    {
        node* x, *y;
        split(root, num - 1, x, y);
        int ans =(x?x->size:0) + 1;
        root = merge(x, y);
        return ans;
    }
    inline int getnum(int rank)
    {
        node* now=root;
        while(now)
        {
            int t=(now->l==NULL?0:now->l->size);
            if(t+1==rank)
               break;
            else if(t>=rank)
                now=now->l;
            else
             {
                rank-=t+1;
                now=now->r;
            }
        }
        return now->val;
    }
    inline int pre(int val)
    {
        node * x,* y;
        int ans;
        split(root, val - 1, x, y);
        node* t = x;
        while (t->r)
            t = t->r;
        ans = t->val;
        root = merge(x, y);
        return ans;
    }
    inline int aft(int val)
    {
        node* x,* y;
        int ans;
        split(root, val, x, y);
        node* t = y;
        while (t->l){
            t = t->l;
        }
        ans = t->val;
        root = merge(x, y);
        return ans;
    }
} T[maxn<<2];
int n;
int get(int pos,int l,int r,int x){
    if(l==r)
        return T[pos].root->val;
    int mid=(l+r)>>1;
    if(x<=mid)
        return get(lson(pos),l,mid,x);
    else return get(rson(pos),mid+1,r,x);
}
void update(int pos,int l,int r,int x,int fr,int to){
    if(fr!=-llinf)
        T[pos].del(fr);
    T[pos].insert(to);
    if(l==r)
        return;
    int mid=l+r>>1;
    if(x<=mid)
        update(lson(pos),l,mid,x,fr,to);
    else update(lson(pos),mid+1,r,x,fr,to);
}
int getpr(int pos,int l,int r,int ql,int qr,int x){
    if(l>=ql&&r<=qr)
        return T[pos].pre(x);
    int ans=-llinf;
    int mid=(l+r)>>1;
    if(ql<=mid)
        MAX(ans,getpr(lson(pos),l,mid,ql,qr,x));
    if(qr>=mid+1)
        MAX(ans,getpr(rson(pos),mid+1,r,ql,qr,x));
    return ans;
}
int getaf(int pos,int l,int r,int ql,int qr,int x){
    if(l>=ql&&r<=qr)
        return T[pos].aft(x);
    int ans=llinf;
    int mid=(l+r)>>1;
    if(ql<=mid)
        MIN(ans,getpr(lson(pos),l,mid,ql,qr,x));
    if(qr>=mid+1)
        MIN(ans,getpr(rson(pos),mid+1,r,ql,qr,x));
    return ans;
}
int getrk(int pos,int l,int r,int ql,int qr,int x){
    if(l>=ql&&r<=qr)
        return T[pos].getrk(x);
    int mid=(l+r)>>1;
    int ans=1;
    if(ql<=mid)
        ans+=getrk(lson(pos),l,mid,ql,qr,x)-1;
    if(ql<=mid)
        ans+=getrk(rson(pos),mid+1,r,ql,qr,x)-1;
    return ans;
}
int getnum(int l,int r,int x){
    int bg=1,ed=1e9;
    while(bg<ed){
        int mid=(bg+ed)>>1;
        if(getrk(1,1,n,l,r,mid)<x)
            l=mid+1;
        else r=mid;
    }
    return bg;
}
void work()
{
    int n,q;
    rd(n),rd(q);
    int tmp;
    for(int i=1;i<=n;i++){
        rd(tmp);
        update(1,1,n,i,-llinf,tmp);
    }
    for(int i=1;i<=n;i++){
        cout<<get(1,1,n,i)<<' ';
    }
    cout<<endl;
    int opt,a,b,c;
    for(int i=1;i<=q;i++){
        rd(opt),rd(a),rd(b);
        if(opt==1){
            rd(c);
            wt(getrk(1,1,n,a,b,c)),pt('\n');
        }else if(opt==2){
            rd(c);
            wt(getnum(a,b,c)),pt('\n');
        }else if(opt==3){
            int t=get(1,1,n,a);
            update(1,1,n,a,t,b);
        }else if(opt==4){2
            rd(c);
            wt(getpr(1,1,n,a,b,c)),pt('\n');
        }else if(opt==5){
            rd(c);
            wt(getaf(1,1,b,a,b,c)),pt('\n');
        }
    }
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