#include<bits/stdc++.h>
using namespace std;
#pragma optimize(2)
#pragma optimize(3)
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
const int maxn = 2e5+5;
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
vector<int> ans;
struct Node
{
    int l,r;
    int val,key;
    int size;
    bool reverse;
}fhq[maxn];
int cnt,root;
#include <random>
std::mt19937 rnd(233);
inline int newnode(int val)
{
    fhq[++cnt].val=val;
    fhq[cnt].key=rnd();
    fhq[cnt].size=1;
    fhq[cnt].l=fhq[cnt].r=0;
    fhq[cnt].reverse=0;
    return cnt;
}
inline void update(int now)
{
    fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}
inline void pushdown(int now)
{
    std::swap(fhq[now].l,fhq[now].r);
    fhq[fhq[now].l].reverse^=1;
    fhq[fhq[now].r].reverse^=1;
    fhq[now].reverse=false;
}
void split(int now,int siz,int &x,int &y)
{
    if(!now) x=y=0;
    else 
    {
        if(fhq[now].reverse) pushdown(now);
        if(fhq[fhq[now].l].size<siz)
        {
            x=now;
            split(fhq[now].r,siz-fhq[fhq[now].l].size-1,fhq[now].r,y);
        }
        else 
        {
            y=now;
            split(fhq[now].l,siz,x,fhq[now].l);
        }
        update(now);
    }
}
int merge(int x,int y)
{
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key)
    {
        if(fhq[x].reverse) pushdown(x);
        fhq[x].r=merge(fhq[x].r,y);
        update(x);
        return x;
    }
    else 
    {
        if(fhq[y].reverse) pushdown(y);
        fhq[y].l=merge(x,fhq[y].l);
        update(y);
        return y;
    }
}
void ldr(int now)
{
    if(!now) return;
    if(fhq[now].reverse) pushdown(now);
    ldr(fhq[now].l);
    ans.push_back(fhq[now].val);
    ldr(fhq[now].r);
}
void rvs(int l,int r)
{
    int x,y,z;
    split(root,l-1,x,y);
    split(y,r-l+1,y,z);
    fhq[y].reverse^=1;
    root=merge(merge(x,y),z);
}
struct seg{
    int seg[maxn<<2];
    int lazy[maxn<<2];
    inline void pushdown(int pos){
        if(lazy[pos]){
            seg[lson(pos)]+=lazy[pos];
            seg[rson(pos)]+=lazy[pos];
            lazy[lson(pos)]+=lazy[pos];
            lazy[rson(pos)]+=lazy[pos];
            lazy[pos]=0;
        }
    }
    void build(int pos,int l,int r){
        if(l==r){
            seg[pos]=l;
            return;
        }
        lazy[pos]=0;
        int mid=l + r >> 1;
        build(lson(pos),l,mid);
        build(rson(pos),mid+1,r);
    }
    void update(int pos,int l,int r,int ql,int qr,int v){
        if(l>r)
            return;
        if(l>=ql&&r<=qr){
            lazy[pos]+=v;
            seg[pos]+=v;
            return;
        }
        pushdown(pos);
        int mid=l+r>>1;
        if(ql<=mid)
            update(lson(pos),l,mid,ql,qr,v);
        if(qr>=mid+1)
            update(rson(pos),mid+1,r,ql,qr,v);
    }
    int qr(int pos,int l,int r,int x){
        if(l==r)
            return seg[pos];
        int mid=l + r >> 1;
        pushdown(pos);
        if(x<=mid)
            return qr(lson(pos),l,mid,x);
        else return qr(rson(pos),mid+1,r,x);
    }
}l,r;
#define ll(i) l.qr(1,1,n,i)
#define rr(i) r.qr(1,1,n,i)
#define lll(i,a) l.update(1,1,n,i,i,a)
#define rrr(i,a) r.update(1,1,n,i,i,a)
int epy[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n,m;
    while(cin>>n>>m){
        cnt=root=0;
        for(register int i=1;i<=n;i++)
            root=merge(root,newnode(i));
        l.build(1,1,n);
        ans.clear();
        r.build(1,1,n);
        for(register int i=1;i<=n;i++)
            epy[i]=0;
        int a,b;
        while(m--)
        {
            rd(a),rd(b);
            swap(a,b);
            if(epy[b])
                continue;
            register int la=ll(a),ra=rr(a);
            register int lb=ll(b),rb=rr(b);
            register int lena=ra-la+1;
            register int lenb=rb-lb+1;
            if(epy[a]){
                if(a>b){
                    rvs(lb,la);
                    rvs(lb,la-lenb);
                    l.update(1,1,n,b+1,a-1,-lenb);
                    r.update(1,1,n,b+1,a-1,-lenb);
                    lll(a,-lenb);
                    rrr(a,la-ra);
                }else{
                    rvs(la,rb);
                    rvs(la+lenb,rb);
                    l.update(1,1,n,a+1,b-1,lenb);
                    r.update(1,1,n,a+1,b-1,lenb);
                    lll(b,lb-rb);
                    rrr(a,la+lenb-1-ra);
                }
            }else
            if(a>b){
                rvs(lb,ra);
                rvs(lb,ra-lenb-1);
                l.update(1,1,n,b+1,a-1,-lenb);
                r.update(1,1,n,b+1,a-1,-lenb);
                lll(a,ra-lenb-lena+1-la);
            }else{
                rvs(ra,rb);
                rvs(ra+1+lenb,rb);
                l.update(1,1,n,a+1,b-1,lenb);
                r.update(1,1,n,a+1,b-1,lenb);
                lll(b,lb-rb);
                rrr(a,lenb);
            }
            epy[a]=0;
            epy[b]=1;
        }
        for(register int i=1;i<=n;i++)
            if(!epy[i])
                rvs(ll(i),rr(i));
        ans.push_back(0);
        ldr(root);
        for(int i=1;i<=n;i++){
            if(epy[i])
                wt(0),putchar('\n');
            else{
                register int li=ll(i);
                register int ri=rr(i);
                wt(ri-li+1),putchar(' ');
                for(register int j=li;j<=ri;j++)
                    wt(ans[j]),putchar(' ');
                putchar('\n');
            }
        }
    }
    return 0;
}