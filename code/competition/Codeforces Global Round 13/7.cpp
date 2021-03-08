#include<bits/stdc++.h>
using namespace std;
struct egs{
    int to,nxt;
}eg[210000];
int ecnt=-1;
int head[110000];
int f[1100];
int fl[210000];
inline void  add(int u,int v){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].to=v;
    head[u]=ecnt;
}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
int sz[30][110000];
int n;
int M[310000];
vector<int> brk;
bool ck(int pos,int tot,int step,int fa){
    if(tot==1)
        return true;
    // cout<<"pos"<<pos<<' '<<tot<<' '<<step<<' '<<fa<<endl;
    sz[step][pos]=1;
    int tog=f[M[tot]-1];
    for(int i=head[pos];i!=-1;i=eg[i].nxt){
        if(fl[i])
            continue;
        int to=eg[i].to;
        if(to==fa)
            continue;
        if(ck(to,tot,step,pos))
            return true;
        if(sz[step][to]==tog||tot-sz[step][to]==tog){
            fl[i]=1;
            fl[i^1]=1;
            int ans=ck(to,sz[step][to],step+1,pos);
            ans+=ck(to,tot-sz[step][to],step+1,to);
            fl[i]=0;
            fl[i^1]=0;
            if(ans==2)
                return true;
        }
        sz[step][pos]+=sz[step][to];
    }
    return false;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    memset(head,-1,sizeof(head));
    f[1]=1;
    f[2]=1;
    M[1]=1;
    for(int i=3;i<1000;i++){
        f[i]=f[i-1]+f[i-2];
        M[f[i]]=i;
        if(f[i]>110000)
            break;
    }
    rd(n);
    int u,v;
    for(int i=1;i<=n-1;i++){
        rd(u),rd(v);
        add(u,v);
        add(v,u);
    }   
    // cout<<"dasasd"<<endl;
    int ans=0;
    ans=ck(1,n,1,-1);
    if(ans){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}