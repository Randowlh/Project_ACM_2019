#include<bits/stdc++.h>
using namespace std;
int dp[2200][1100];
int cct[2200][1100];
int date[1100];
int ans,n;
int cnt;
void dfs(int pr,int flag,int pos){
    if(!flag){
        for(int i=pos+1;i<=n;i++){
            dfs(date[pos],1,i);
        }
        return;
    }
    if(dp[pr][pos]!=-1)
        return;
    int to=pr*date[pos]%2021;
    int aa=1,cc=1;
    for(int i=pos+1;i<=n;i++){
        if(date[i]==to){
            dfs(date[pos],1,i);
            if(dp[date[pos]][i]+1==aa)
                cc+=cct[date[pos]][i]+1;
            else aa=dp[date[pos]][i]+1,cc=cct[date[pos]][i];
        }
    }
    dp[pr][pos]=aa;
    cct[pr][pos]=cc;
    if(ans==aa){
        cnt+=cc;
    }else if(ans<aa){
        ans=aa;
        cnt=cc;
    }
    return;
}
int main(){
    // freopen("in.txt","r",stdin);
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=n;i++){
        cin>>date[i];
        cout<<date[i]<<endl;
    }
    for(int i=1;i<=n;i++)
        dfs(-1,0,i);
    cout<<cnt<<endl;
    cout<<ans+1<<endl;
}