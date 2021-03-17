l=int(input())
n=input()
aa=n
aa=int(aa);
st=int(l/2)
cnt=0
for i in range(st,l):
    # print("i="+str(i));
    if n[i] != '0' or i==l-1:
        cnt+=1
        a='0'
        b='0'
        for j in range(i,l,1):
            a+=n[j]
        for j in range(0,i,1):
            b+=n[j]
        a=int(a)
        b=int(b)          
        aa=min(aa,a+b);
        if cnt >3:
            break;
cnt=0;
for i in range(st,-1,-1):
    # print("i="+str(i));
    if n[i] != '0':
        cnt+=1
        a='0'
        b='0'
        for j in range(i,l,1):
            a+=n[j]
        for j in range(0,i,1):
            b+=n[j]
        a=int(a)
        b=int(b)                 
        aa=min(aa,a+b);
        if cnt >3:
            break;
print(aa);
