n=int(input())
date=[]
tot=0
tt= input()
for i in tt.split():
    tmp=int(i);
    date.append(tmp)
    tot=tot+tmp
tot=tot//n;
pre=[]
aft=[]
now=0
for i in range(n):
    pre.append(now+date[i])
    now=now+date[i]
now=0
for i in range (n-1,-1,-1):
    # print("i="+str(i))
    aft.append(now+date[i])
    now+=date[i];
aft.reverse();
# print(aft);
ans=0
for i in range(n):
    if pre[i]< tot*(i+1):
        ans=ans+1
    if aft[i]<tot*(n-i):
        ans=ans+1;
print(ans)
