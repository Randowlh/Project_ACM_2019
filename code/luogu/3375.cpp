#include<bits/stdc++.h>
using namespace std;
#define maxn 1100000
string str1,str2;
int nxt[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>str1;
    str1=" "+str1;
    cin>>str2;
    str2=" "+str2;
    int len1=str1.size();
    int len2=str2.size();
    // cout<<len1<<' '<<len2<<endl;
    // return 0;
    int lft=0;
    for(int i=2;i<len2;i++){
        while(lft&&str2[lft+1]!=str2[i])
            lft=nxt[lft];
        if(str2[lft+1]==str2[i])
            lft++;
            nxt[i]=lft;
    }
    lft=0;
    for(int i=1;i<len1;i++){
        while(lft&&str2[lft+1]!=str1[i])
            lft=nxt[lft];
        if(str2[lft+1]==str1[i])
            lft++;
        if(lft==len2-1){
            lft=nxt[lft];
            cout<<i-len2+2<<'\n';
        }
    }
    for(int i=1;i<len2;i++)
        cout<<nxt[i]<<' ';
    cout<<endl;
}