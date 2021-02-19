#include<bits/stdc++.h>
using namespace std;
#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
int seg[2100][2100<<4];
// int lazy[2100][2100<<4];
void pushdown(int num,int pos){
    if(seg[num][pos]){
        seg[num][lson(pos)]=seg[num][pos];
        seg[num][rson(pos)]=seg[num][pos];
        seg[num][pos]=0;
    }
}
void update(int num,int pos,int l,int r,int ql,int qr,int x){
    if(ql<=l&&qr>=r){
        seg[num][pos]=x;
        return;
    }
    pushdown(num,pos);
    int mid=(l+r)>>1;
    if(ql<=mid)
        update(num,lson(pos),l,mid,ql,qr,x);
    if(qr>=mid+1)
        update(num,rson(pos),mid+1,r,ql,qr,x);
}
int query(int num,int pos,int l,int r,int x){
    if(seg[num][pos])
        return seg[num][pos];
    if(l==r)
        return 0;
    int mid=(l+r)>>1;
    if(x<=mid)
        return query(num,lson(pos),l,mid,x);
    else return query(num,rson(pos),mid+1,r,x);
}
struct node{
    int x,y,k;
}qrs[3100];
inline int calc(int x,int y,int num){
    if(num==0)
        return 0;
    int tt=x-qrs[num].x;
    int dis=y-qrs[num].y;
    if(tt%2==0){
        return tt*qrs[num].k+dis+1;
    }else return (tt+1)*qrs[num].k-dis;

}
int main(){
    // freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&qrs[i].x,&qrs[i].y,&qrs[i].k);
    for(int i=1;i<=m;i++){
        int l=qrs[i].y;
        int r=qrs[i].y+qrs[i].k-1;
        for(int j=qrs[i].x;j<qrs[i].x+qrs[i].k;j++){
            update(j,1,1,n,l,r,i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",calc(i,j,query(i,1,1,n,j)));
        printf("\n");
    }
}