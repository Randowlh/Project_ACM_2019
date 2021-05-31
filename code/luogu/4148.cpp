#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
const int maxn=210000;
const int wd=2;
int tail,type;
struct node{
    int dim[wd],val;
    bool operator<(const node &a)const{
        return dim[type]<a.dim[type];
    }
}tree[maxn],tmp[maxn];
int root,dfsid,trid,rub,bin[maxn];
int tp[maxn],ls[maxn],rs[maxn],ma[maxn][wd],mi[maxn][wd],sz[maxn];
ll sum[maxn];
void pushup(int pos){
    for(int i=0;i<wd;i++){
        ma[pos][i]=mi[pos][i]=tree[pos].dim[i];
        if(ls[pos])MAX(ma[pos][i],ma[ls[pos]][i]),MIN(mi[pos][i],mi[ls[pos]][i]);
        if(rs[pos])MAX(ma[pos][i],ma[rs[pos]][i]),MIN(mi[pos][i],mi[rs[pos]][i]);
    }
    sum[pos]=sum[ls[pos]]+sum[rs[pos]]+tree[pos].val;
    sz[pos]=sz[ls[pos]]+sz[rs[pos]]+1;
}
void newnode(int& ans ,int ty,const node &rhs){
    if(rub)ans=bin[rub--];
    else ans=++trid;
    tp[ans]=ty;
    tree[ans]=rhs;
    ls[ans]=rs[ans]=0;
    pushup(ans);
}
void clean_node(int x){
    bin[++rub]=x;
    ls[x]=rs[x]=sz[x]=sum[x]=0;
}
void rebuild(int &x,int l,int r){
    int mid=l+r>>1;
    type=(++tail)&1;
    nth_element(tmp+l,tmp+mid,tmp+r+1);
    newnode(x,type,tmp[mid]);
    if(l<mid)rebuild(ls[x],l,mid-1);
    if(mid<r)rebuild(rs[x],mid+1,r);
    pushup(x);
}
void to_array(int x){
    if(ls[x])to_array(ls[x]);
    if(rs[x])to_array(rs[x]);
    tmp[++dfsid]=tree[x];
    clean_node(x);
}
void insert(int&x,const node&rhs){
    if(x==0){
        newnode(x,(++tail)&1,rhs);
        return;
    }
    if(rhs.dim[tp[x]]<=tree[x].dim[tp[x]])insert(ls[x],rhs);
    else insert(rs[x],rhs);
    pushup(x);
    if(sz[ls[x]]>sz[x]*0.75||sz[rs[x]]>sz[x]*0.75){
        dfsid=0;
        to_array(x);
        rebuild(x,1,dfsid);
    }
}
inline bool inside(int xl,int xr,int yl,int yr,int x1,int x2,int y1,int y2){
    return xl<=x1&&x2<=xr&&yl<=y1&&yr>=y2;
}
inline bool outside(int xl,int xr,int yl,int yr,int x1,int x2,int y1,int y2){
    return xl>x2||xr<x1||yl>y2||yr<y1;
}
ll query(int x,int xl,int xr,int yl,int yr){
    if(x==0)
        return 0;
    if(outside(xl,xr,yl,yr,mi[x][0],ma[x][0],mi[x][1],ma[x][1]))return 0;
    if(inside(xl,xr,yl,yr,mi[x][0],ma[x][0],mi[x][1],ma[x][1]))return sum[x];
    ll ans=query(ls[x],xl,xr,yl,yr)+query(rs[x],xl,xr,yl,yr);
    if(inside(xl,xr,yl,yr,tree[x].dim[0],tree[x].dim[0],tree[x].dim[1],tree[x].dim[1]))
        ans+=tree[x].val;
    return ans;
}
int main(){
    // freopen("in.txt", "r", stdin);
    int n;
    int ans=0;
    rd(n);
    while(1){
        int opt;
        rd(opt);
        // cout<<"opt="<<opt<<endl;
        if(opt==1){
            int x,y,v;
            rd(x),rd(y),rd(v);
            x^=ans,y^=ans,v^=ans;
            insert(root,(node){x,y,v});
        }else if(opt==2){
            int xl,xr,yl,yr;
            rd(xl),rd(yl),rd(xr),rd(yr);
            xl^=ans,xr^=ans,yl^=ans,yr^=ans;
            ans=query(root,xl,xr,yl,yr);
            wt(ans),putchar('\n');
        }else if(opt==3)
            break;
    }
}