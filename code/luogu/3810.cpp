#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x & -x)
struct node{
    int a,b,c,cnt,ans;
    inline bool operator<(node aa)const { 
        if(a==aa.a)
            if(b==aa.b)
                return c<aa.c;
            else return b<aa.b;
        return a<aa.a;
    }
    inline bool operator>(node aa)const{
        if(b==aa.b)
            return c<aa.c;
        return b<aa.b;
    }
    inline bool operator!=(node aa){
        if(aa.a!=a||aa.b!=b||aa.c!=c)  
            return true;
        return false;
    }
}date[210000];
int sum[210000];
int aa[210000];
int n,k;
void update(int x,int v){
    while(x<=k){
        sum[x]+=v;
        x+=lowbit(x);
    }
}
int qr(int x){
    int tot=0;
    while(x){
        tot+=sum[x];
        x-=lowbit(x);
    }
    return tot;
}
void cdq(int l,int r){
    if(l==r){
        date[l].ans+=date[l].cnt-1;
        return;
    }
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(date+l,date+mid+1,greater<node>());
    sort(date+mid+1,date+r+1,greater<node>());
    int i,j=l;
    for(i=mid+1;i<=r;i++){
        for(;j<=mid&&date[j].b<=date[i].b;j++)
            update(date[j].c,date[j].cnt);
        date[i].ans+=qr(date[i].c);
    }
    for(int i=l;i<j;i++)
        update(date[i].c,-date[i].cnt);
    sort(date+l,date+r+1,greater<node>());
}
signed main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>date[i].a>>date[i].b>>date[i].c;
    sort(date+1,date+n+1);
    int tail=1;
    date[1].cnt=1;
    for(int i=2;i<=n;i++){
        if(date[i]!=date[i-1])
            date[++tail]=date[i];
        date[tail].cnt++;
    }
    cdq(1,tail);
    sort(date+1,date+tail+1);
    for(int i=1;i<=tail;i++)
        aa[date[i].ans]+=date[i].cnt;
    for(int i=0;i<n;i++)
        cout<<aa[i]<<'\n';
}