#include<bits/stdc++.h>
using namespace std;
double dp[2100][2100][2];
int dis[2100][2100];
int c[2100];
int d[2100];
double k[2100];
int main(){
    // freopen("in.txt", "r", stdin);
    int n,m,v,e;
    cin>>n>>m>>v>>e;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=v;i++)
        for(int j=1;j<=v;j++)
            if(i==j)
                dis[i][j]=0;
            else dis[i][j]=1e9;
    int a,b,w;
    for(int i=1;i<=n;i++)
        cin>>k[i];
    for(int i=1;i<=e;i++){
        cin>>a>>b>>w;
        dis[a][b]=min(dis[a][b],w);
        dis[b][a]=dis[a][b];
    }
    for(int k=1;k<=v;k++)
        for(int i=1;i<=v;i++)
            for(int j=1;j<=v;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=n;i++)   
        for(int j=0;j<=m;j++)
            dp[i][j][0]=dp[i][j][1]=0x7FFFFFFF;
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=i;j++){
            dp[i][j][0]=min(dp[i-1][j][0]+dis[c[i-1]][c[i]],
                            dp[i-1][j][1]+dis[c[i-1]][c[i]]*(1-k[i-1])
                                        +dis[d[i-1]][c[i]]*k[i-1]);
            if(j>0)
            dp[i][j][1]=min(dp[i-1][j-1][0]+
            dis[c[i-1]][c[i]]*(1-k[i])+
            dis[c[i-1]][d[i]]*k[i],
            dp[i-1][j-1][1]+
            dis[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])+
            dis[c[i-1]][d[i]]*(1-k[i-1])*k[i]+
            dis[d[i-1]][c[i]]*k[i-1]*(1-k[i])+
            dis[d[i-1]][d[i]]*k[i-1]*k[i]);
        }
    double ans=0x7FFFFFFF;
    for(int i=0;i<=m;i++){
        ans=min(ans,dp[n][i][0]);
        ans=min(ans,dp[n][i][1]);
    }
    printf("%.2lf\n",ans);
}