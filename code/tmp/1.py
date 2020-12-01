dp = [[] for i in range(0,30)]
dd = [[] for i in range(0,30)]
yy = [[] for i in range(0,30)]
for i in range(0,27):
    for j in range(0,30):
        dp[i].append(999999999)
        dd[i].append([])
        yy[i].append([])
w=[3,3,3,3,4,3,3,4,3,5,5,3,5,5,3,3,2,5,3,6,5,5,5,5];
v=[20,25,34,36,40,45,46,48,50,51,52,54,55,56,58,70,73,80,89,100,120,125,136,140];
dp[0][0]=0;
for i in range(0,23,1):
    for j in range(24,1,-1):
        for k in range(25,w[i],-1):
            if(dp[j][k]>(dp[j-1][k-w[i]]+v[i])):
                dp[j][k]=dp[j-1][k-w[i]]+v[i];
                dd[j][k]=dd[j-1][k-w[i]].copy();
                dd[j][k].append(i+1)
                yy[j][k]=yy[j-1][k-w[i]].copy();
                yy[j][k].append(k);
aa = []
aay= []
ans =999999999;
for i in range(12,24,1):
    for j in range(1,25,1):
        if(ans>dp[i][j]):
            ans=dp[i][j]
            aa=dd[i][j].copy();
            aay=yy[i][j].copy();      
print("the least cost is="+str(ans));
for i in range(0,len(aa)):
    print("the "+str(i+1)+"th project is "+str(aa[i])+" start in "+str(aay[i])+"th year");    
