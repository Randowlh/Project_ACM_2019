#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[25][7][7][2][2];
int disg[25];
int l,r;
int dfs(int pos,int lk,int qz,int staus,int dao, int flag)
{
    // cout<<"pos"<<pos<<' '<<lk<<' '<<staus<<' '<<dao<<' '<<flag<<endl;
    if (pos == 0)
        return staus;
    if (flag && dp[pos][lk][qz][staus][dao] != -1)
        return dp[pos][lk][qz][staus][dao];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if(i==0){
            if(pos==1)
                ans+=dfs(pos-1,lk,qz,1,1,flag||i<num);
            else
                ans+=dfs(pos-1,lk,qz,(dao)>0,dao,flag||i<num);
        }else{
            int ti=i%3;
            swap(ti,i);
            if(i==0||((qz+i)%3)==0)
            ans+=dfs(pos-1,((qz+i)%3)|lk,(qz+i)%3,1,1,flag||ti<num);
            else if(((qz+i)%3)&lk)
            ans+=dfs(pos-1,((qz+i)%3)|lk,(qz+i)%3,1,1,flag||ti<num);
            else {
            ans += dfs(pos - 1, ((qz+i)%3)|lk,(qz+i)%3, staus,1, flag || ti < num);
            }
            swap(ti,i);
        }
    }
    if (flag)
        dp[pos][lk][qz][staus][dao] = ans;
    return ans;
}
int calc(int x)
{
    if(x==0)
        return 1;
    int cnt = 1;
    while (x)
    {
        disg[cnt] = x % 10;
        cnt++;
        x /= 10;
    }
    return dfs(cnt - 1,0,0,0,0, 0);
}
signed main()
{
    // freopen("in.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    // cout<<calc(11)<<endl;
    // return 0;
    // for(int i=0;i<=1;i++)  
    //     cout<<"calci"<<calc(i)<<' '<<i<<endl;
    // cout<<calc(11)-calc(10)<<endl;
    int t;
    scanf("%lld", &t);
    for (int q = 1; q <= t; q++)
    {
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", calc(r) - calc(l - 1));
    }
}