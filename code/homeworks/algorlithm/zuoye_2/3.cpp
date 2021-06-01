#include <bits/stdc++.h>
using namespace std;
int dp[100100];
int date[100100];
int tail = 1;
int main(){
    int tmp;
    while(scanf("%d", &date[tail])!=EOF)
        tail++;
    int ans1 = 1;
    dp[1] = date[1];
    for (int i = 2; i < tail;i++){
        if(date[i]<=dp[ans1])
            dp[++ans1] = date[i];
        else{
            int pos = upper_bound(dp + 1, dp + ans1, date[i], greater<int>()) - dp;
            dp[pos] = date[i];
        }
    }
    printf("%d\n", ans1);
}//算法设计最后一题