#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
struct L{
    int x,yl,yu,z;
    inline bool operator<(L a){
        return x<a.x;
    }
}line[maxn<<1];
int v[maxn<<1];
struct node{
    int l,r,len,lazy;
}seg[maxn<<3];
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
inline void pushup(int pos){
    if(seg[pos].lazy) seg[pos].len=seg[pos].r-seg[pos].l;
    else seg[pos].len=seg[lson(pos)].len+seg[rson(pos)].len;
}
void build(int pos,int l,int r){
    seg[pos].len=0;
    seg[pos].l=v[l];
    seg[pos].r=v[r];
    if(r-l<=1) return;
    int mid=l+r>>1;
    build(lson(pos),l,mid);
    build(rson(pos),mid,r);
}
void update(int pos,int l,int r,int opt){
    if(l<=seg[pos].l&&r>=seg[pos].r){
        seg[pos].lazy+=opt;
        pushup(pos);
        return;
    }
    int mid=seg[lson(pos)].r;
    if(l<mid)
        update(lson(pos),l,r,opt);
    if(r>mid)
        update(rson(pos),l,r,opt);
    pushup(pos);
}
signed main(){
    int n;
    rd(n);
    int a,b,c,d;
    for(int i=1;i<=n;i++){
        rd(a),rd(b),rd(c),rd(d);
        line[i]=(L){a,b,d,1};
        line[n+i]=(L){c,b,d,-1};
        v[i]=b;
        v[n+i]=d;
    }
    sort(line+1,line+2*n+1);
    sort(v+1,v+2*n+1);
    build(1,1,n*2);
    unsigned int ans=0;
    for(int i=1;i<=n*2;i++){
        ans+=seg[1].len*(unsigned int)(line[i].x-line[i-1].x);
        update(1,line[i].yl,line[i].yu,line[i].z);
    }
    cout<<ans<<endl;
}