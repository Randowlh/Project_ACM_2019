import numpy as np
dp = np.arange(3300000).reshape(3000,1100);
cct = np.arange(3300000).reshape(3000,1100);
date = np.arange(1100);
ans=0
n=0
cnt=0
def dfs(pr,flag,pos):
    global n
    global cnt
    global dp
    global cct
    global date
    global ans
    if(flag==0):
        for i in range(pos+1,n+1):
            dfs(date[pos],1,i)
        return 1
    if(dp[pr][pos]!=-1):
        return
    to=pr*date[pos]%2021;
    aa=1
    cc=1
    for i in range(pos+1,n+1):
        if date[i]==to:
            dfs(date[pos],1,i);
            if dp[date[pos]][i]+1==aa:
                cc=cc+cct[date[pos]][i]+1
            else:
                aa=dp[date[pos]][i]+1
                cc=cct[date[pos]][i]
    dp[pr][pos]=aa
    cct[pr][pos]=cc
    if ans==aa:
        cnt+=cc
    elif ans<aa:
        ans=aa
        cnt=cc
    return 1
n=int(input())
now=1
tt= input()
for i in range(0,2300):
    for j in range(0,n+1):
        dp[i][j]=-1
for i in tt.split():
    date[now]=int(i);
    now=now+1;
for i in range(1,n+1):
    dfs(-1,0,i)
print(cnt)
print(ans+1)