#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long 
#define ls (x<<1)
#define rs (x<<1|1)//这种方法感觉还挺好的

const int MAXN = 5e5+5;//这里要开n的两倍
//线结构体
struct Line{
    ll l,r,h;
    int qz;//记录位置和权值
    bool operator < (Line &rhs){
        return h < rhs.h;
    }
};
int n;
//ll X[MAXN];
vector<Line> line[MAXN];
//线段树
struct Segt{
    int l,r;//是X的下标,即离散化后的
    int sum;//sum是被完全覆盖的次数
    ll len;//len是区间内被盖住的长度
    //因为每次查询都是查询根节点,所以这边不需要懒惰标记
}t[MAXN<<3];//一个边有两个点,所以这里要开8倍
void build(int x,int l,int r){
    t[x].l = l;t[x].r = r;
    t[x].len = t[x].sum = 0;
    if(l==r) return;//到了叶子节点
    int mid = (l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
}
void push_up(int x){
    int l = t[x].l,r = t[x].r;
    if(t[x].sum) t[x].len = r-l+1;////完全覆盖
    else t[x].len = t[ls].len + t[rs].len;//合并儿子的信息
}
void update(int x,int L,int R,int v){//这里的LR存的是实际值
    //这里如果是线段L,R,线段树上是L到R-1的部分维护
    int l = t[x].l,r = t[x].r;
    if(r<L||R<l) return;//加等于,不然会搞到无辜的线
    if(L<=l&&r<=R){
        t[x].sum += v;//修改覆盖次数
        push_up(x);
        return;
    }
    update(ls,L,R,v);
    update(rs,L,R,v);
    push_up(x);
}
ll ans;
void query(int x,int pos){
    int l = t[x].l,r = t[x].r;
    if(r<pos||pos<l) return;
    if(l==pos&&r==pos){
        ans += t[x].len;
        return;
    }
    query(ls,pos);
    query(rs,pos);
}
inline int tquery(int pos){
    ans = 0;
    query(1,pos);
    return ans;
}
//上面全是板子

ll d;
ll tx1,ty1,tx2,ty2;
ll lenx,leny;
inline void add(ll x1,ll y1){
    ll x2,y2;
    x2 = x1+lenx;y2 = y1+leny;
    
    x1 = max(0ll,x1);
    y1 = max(0ll,y1);
    x2 = min(2*d,x2);
    y2 = min(2*d,y2);
    
    cout<<"add"<<x1<<' '<<y1<<':'<<x2<<' '<<y2<<endl;
    
    line[y1].push_back(Line{x1,x2,y1,1});//in
    line[y2].push_back(Line{x1,x2,y2,-1});//out
}

inline void solve(){
    cin>>n>>d;
    rep(i,0,d) line[i].clear();//清空vector
    ll x1,y1,x2,y2;
    rep(i,1,n){
        cin>>x1>>y1>>x2>>y2;
        lenx = x2-x1;leny = y2-y1;
        tx1 = x1%d;ty1 = y1%d;
        //左下角
        add(tx1-d,ty1-d);
        //左上角
        add(tx1-d,ty1);
        //右下角
        add(tx1,ty1-d);
        //右上角
        add(tx1,ty1);
    }
    cout<<"add"<<endl;
    build(1,0,d-1);
    cout<<"build"<<endl;
    int now = 0;
    rep(i,0,d-1){
        int siz = line[i].size();
        rep(j,0,siz-1) update(1,line[i][j].l,line[i][j].r-1,line[i][j].qz);
        if(t[1].len<d){//有空隙,开始检查
            rep(k,0,d-1) if(tquery(k)==0){
                cout<<"YES"<<endl;
                cout<<k<<' '<<i<<endl;//出坐标
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    solve();
}
