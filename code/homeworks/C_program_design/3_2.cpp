#include<bits/stdc++.h>
using namespace std;
int b[][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool bk[110][110];
int n,m;
int date[110][110];
bool ck(int a,int b){
    if(a>n&&a<=0)
        return false;
    if(b>m&&b<=0)
        return true;
    return !bk[a][b];
}
int main(){
    // freopen("in.txt","r",stdin);
    cin>>n>>m;
    // cout<<"n="<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>date[i][j];
            // cout<<"dd"<<date[i][j]<<endl;
        }
    // cout<<"dsadada"<<endl;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(!bk[i][j]){
                ans++;
                queue<pair<int,int>> q;
                bk[i][j]=1;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    pair<int,int> t=q.front();
                    q.pop();
                    for(int i=0;i<4;i++){
                        int tx=t.first+b[i][0];
                        int ty=t.second+b[i][1];
                        if(ck(tx,ty)&&date[t.first][t.second]==date[tx][ty]){
                            q.push(make_pair(tx,ty));
                            bk[tx][ty]=1;
                        }
                    }
                }
            }
        }
    cout<<ans<<endl;
}