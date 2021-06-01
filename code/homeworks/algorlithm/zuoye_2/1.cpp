#include<bits/stdc++.h>
using namespace std;
int dp[1100][1100];
string a,b;
int main(){
    cin>>a>>b;
    int k;
    cin>>k;
    a=" "+a;
    b=" "+b;
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=1000;j++)
            if(i&&j)
            dp[i][j]=0x3f3f3f3f;
            else dp[i][j]=k*(i+j);
    for(int i=1;i<a.size();i++)
        for(int j=1;j<b.size();j++)
            dp[i][j]=min(dp[i-1][j-1]+abs(a[i]-b[j]),min(dp[i-1][j],dp[i][j-1])+k);
    cout<<"dp array:"<<endl;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++)
            cout<<dp[i][j]<<' ';
        cout<<endl;
    }
    cout<<dp[a.size()-1][b.size()-1]<<endl;
}