#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double dp[1100][1100];
int main(){
    int n,m;
    cin>>n>>m;
    dp[1][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)
                continue;
            
        }
}