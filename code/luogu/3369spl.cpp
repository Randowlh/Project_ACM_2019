#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node{
    int l,r;
    int val,size;
    int cnt;
}spl[maxn];
int tail,root;
inline void newnode(int &now,int &val){
    spl[++tail].val=val;
    spl[tail].cnt=1;
    spl[tail].size=1;
    now=tail;
}
inline void pushup(int pos){
    spl[pos].size=spl[spl[pos].l].size+spl[spl[pos].r].size+spl[pos].cnt;
}
inline void zig(int &now){
    int l=spl[now].l;
    spl[now].l=spl[l].r;
    spl[l].r=now;
    pushup(now),pushup(l);
    now=l;
}
inline void zag(int &now){
    int r=spl[now].r;
    spl[now].r=spl[r].l;
    spl[r].l=now;
    pushup(r),pushup(now);
    now=r;
}
void splay(int x,int &y){
    if(x==y)
        return;
    int &l=spl[y].l,&r=spl[y].r;
    if(x==l)
        zig(y);
    else if(x==r)
        zag(x);
    else if(spl[x].val<spl[y].val){
        if(spl[x].val<spl[l].val)
            splay(x,spl[l].l),zig(y),zig(y);
        else splay(x,spl[l].r),zag(l),zig(y);
    }else{
        if(spl[x].val>spl[r].val)
            splay(x,spl[r].r),zag(y),zag(y);
        else splay(x,spl[r].l),zig(r),zag(y);
    }
}
inline void delnode(int now){
    splay(now,root);
    if(spl[now].cnt>1){
        spl[now].size--;
        spl[now].cnt--;
    }else if(spl[root].r){
        int p=spl[root].r;
        while(spl[p].l) p=spl[p].l;
        
    }
}
int main(){


}