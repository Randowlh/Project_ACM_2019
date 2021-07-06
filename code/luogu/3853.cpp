#include<bits/stdc++.h>
using namespace std;
const int maxn=1100;
double ans[maxn][maxn],p[maxn][maxn][4];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j][1]>>p[i][j][2]>>p[i][j][3];
    ans[n][m]=0;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--){
            if(i==n&&j==m)
                continue;
            if(dp[i][j][1]==1)
                continue;
        }
}