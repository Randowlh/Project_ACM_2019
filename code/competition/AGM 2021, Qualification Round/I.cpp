#include<bits/stdc++.h>
using namespace std;
#define int long long
const int llinf = 4223372036854775807;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
int mp[510][510];
struct node{
    int x1,y1,x2,y2,sz;
    int cst[110];
}ors[510];
int rs[510];
int flag=0;
int n,m,k;
void dfs(int pos,int fa,int flag){
    rs[pos]=flag+1;
    for(int i=1;i<=k;i++){
        if(i==fa)
            continue;
        if(mp[pos][i]){
            if(rs[i]){
                if(rs[i]!=(flag^1)+1){
                    flag=1;
                    return;
                }
            }else
            dfs(i,pos,flag^1);
            if(flag)
                return;
        }
    }
}
int main(){
    rd(n),rd(m),rd(k);
    int  x1,x2,y1,y2;
    for(int i=1;i<=k;i++){
        rd(x1),rd(y1),rd(x2),rd(y2);
        ors[i]=(node){x1,y1,x2,y2};
    }
    for(int i=1;i<=k;i++){
        mp[i][i]=1;
        ors[i].sz=(ors[i].x2-ors[i].x1+1)*(ors[i].y2-ors[i].y1+1);
        for(int j=1;j<=100;j++){
            int tot=0;
            for(int x=ors[i].x1;x<=ors[i].x2;x++)
                for(int y=ors[i].y1;y<=ors[i].y2;y++)
                    tot+=abs(mp[x][y]-j);
            ors[i].cst[j]=tot;
        }
    }
    for(int i=1;i<k;i++)
        for(int j=i+1;j<=k;j++){
            int ff=0;
            if(ors[i].y1<=ors[j].y2||ors[i].y2>=ors[j].y1)
                if(ors[i].x1+1==ors[j].x2||ors[j].x1+1==ors[i].x2)
                    ff=1;
            if(ors[i].x1<=ors[j].x2||ors[i].x2>=ors[j].x1)
                if(ors[i].y1+1==ors[j].y2||ors[i].y1+1==ors[j].y2)
                    ff=1;
            mp[i][j]=mp[j][i]=ff;
        }
    for(int i=1;i<=k;i++){
        if(rs[i])
            dfs(i,-1,1);
    }
    if(flag){
        cout<<-1<<endl;
        return ;
    }
}