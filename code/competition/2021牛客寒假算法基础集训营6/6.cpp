#include<bits/stdc++.h>
using namespace std;
#define int __int128
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
int a[30],b[30];
int dp[1<<22];
signed main(){
    int n,x;
    rd(n),rd(x);
    for(int i=0;i<n;i++)
        rd(a[i]),rd(b[i]);
    dp[0]=x;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                continue;
            dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]*a[j]+b[j]);
        }
    }
    wt(dp[(1<<n)-1]),putchar('\n');
}