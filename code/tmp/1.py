def hanoi(n,x,y,z):
    stk=[];
    stk.append([n,x,y,z,0]);
    pos=0
    is_return=0;
    while True:
        if pos==-1:
            break
        if stk[pos][0]==1:
            print(stk[pos][1]+"->"+stk[pos][3]);
            stk.pop();
            pos=pos-1
            continue;
        else:
            if stk[pos][4]==0:
                stk[pos][4]=stk[pos][4]+1
                stk.append([stk[pos][0]-1,stk[pos][1],stk[pos][3],stk[pos][2],0])
                pos=pos+1;
                continue;
            elif stk[pos][4]==1:
                print(stk[pos][1]+"->"+stk[pos][3]);
                stk[pos][4]=stk[pos][4]+1;
                stk.append([stk[pos][0]-1,stk[pos][2],stk[pos][1],stk[pos][3],0])
                pos=pos+1;
                continue;
            else:
                stk.pop();
                pos=pos-1;
n=int(input())
hanoi(n,'A','B','C');