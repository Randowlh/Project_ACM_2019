#include<bits/stdc++.h>
using namespace std;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
typedef long long ll;
const int maxn=210000;
const int wd=2;
int tail,type;
struct node{
    int val,dim[wd];
    bool operator<(const node &a)const{
        return dim[type]<a.dim[type];
    }
}tree[maxn],tmp[maxn];
int root,dfsid,trid,rub,bin[maxn];
int tp[maxn],ls[maxn],rs[maxn],ma[maxn][wd],mi[maxn][wd];
ll sum[maxn];
void pushup(int pos){
    for(int i=0;i<wd;i++){
        ma[pos][i]=mi[pos][i]=tree[pos].dim[i];
        if(ls[pos])
            
    }
}
int main(){
    
}