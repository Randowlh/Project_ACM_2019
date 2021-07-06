#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
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
}aw,cst;
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
};
signed main(){
    int _;
    cin>>_;
    for(int i=1;i<=3;i++)
        aw.date[i][i]=1;
    aw.n=cst.n=3;
    cst.date[1][1]=1;
    cst.date[1][3]=1;
    cst.date[2][1]=1;
    cst.date[3][2]=1;
    while(_--){
        int n;
        cin>>n;
        if(n<=3){
            cout<<1<<endl;
            continue;
        }
        node tt=fpow(cst,n);
        cout<<(tt.date[2][1])%mod<<endl;   
    }
}