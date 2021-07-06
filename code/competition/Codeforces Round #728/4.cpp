#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
int fa[maxn][20];
int dp[maxn][maxn];
vector<int> mp[maxn];
int inv(int a, int p)
{
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
int main(){
    int n;
    cin>>n;
    rep(i,1,n)
        dp[0][i]=1;
    rep(i,1,n)
        rep(j,1,n){
            dp[i][j]=(dp)
        }
}