#include<bits/stdc++.h>
using namespace std;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
const int maxn=200005;
int n,ans,rt,TYPE,top,cur,rub[maxn];
struct point{int x[2],w;
    inline bool operator<(point a){
        return x[TYPE]<a.x[TYPE];
    }
}p[maxn];
struct node{
    int mi[2],mx[2],sum,ls,rs,sz;point tp;
}tr[maxn];
int newnode(){
    if(top) return rub[top--];
    else return ++cur;
}
void pushup(int k){
    int l=tr[k].ls,r=tr[k].rs;
    for(int i=0;i<2;i++){
        tr[k].mi[i]=tr[k].mx[i]=tr[k].tp.x[i];
        if(l)tr[k]
    }
}
int main(){
    
}