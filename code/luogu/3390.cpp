#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=110;
const int mod=1e9+7;
struct node{
    int n;
    int date[maxn][maxn];
    node operator*(node a){
        node ans;
        ans.n=n;
        for(int i=1;i<=n;i++)   
            for(int j=1;j<=n;j++){
                int tot=0;
                for(int k=1;k<=n;k++){
                    tot+=date[i][k]*a.date[k][j];
                    tot%=mod;
                }
                ans.date[i][j]=tot;
            }
        return ans;
    }
}aw;
node fpow(node a,int b){
    node ans=aw;
    node tmp=a;
    while(b){
        if(b&1)
            ans=ans*tmp;
        tmp=tmp*tmp;
        b>>=1;
    }
    return ans;
}
signed main(){
    int n,k;
    cin>>n>>k;
    aw.n=n;
    node tt;
    tt.n=n;
    for(int i=1;i<=n;i++)
        aw.date[i][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>tt.date[i][j];
    tt=fpow(tt,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<tt.date[i][j]<<' ';
        cout<<endl;
    }
}