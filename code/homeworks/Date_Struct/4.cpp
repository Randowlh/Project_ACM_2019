#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int inf= 0x7FFFFFFF;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
int dp[310][310];
struct rcd{
    int type;//0学校1年级2班级3学生
    string name;
};
struct opt{
    int jd;
    int opt;//0插入1删除.
    rcd date;
}stk[11000];
int tail,tree_tail;
struct node{
    int l,r;
    rcd v;
    node(){l=0,r=0;}
}tree[11000];
int calc(string a,string b){
    for(int i=0;i<=a.size();i++)
        dp[i][0]=0;
    for(int j=0;j<=b.size();j++)
        dp[0][j]=0;
    for(int i=1;i<=a.size();i++)
        for(int j=1;j<=b.size();j++){
            dp[i][j]=inf;
            MIN(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
            MIN(dp[i][j],dp[i-1][j]+1);
            MIN(dp[i][j],dp[i][j-1]+1);
        }
    return dp[a.size()][b.size()];
}
void dfs(int now,int dep){
    for(int i=1;i<dep;i++)
        cout<<"|";
    cout<<"↳"<<tree[now].v.name<<endl;
    if(tree[now].r)
        dfs(tree[now].r,dep+1);
    if(tree[now].l)
        dfs(tree[now].l,dep);
}
void flsh(){
    system("cls");
    dfs(1,1);
    return;
}
int main(){
    system("chcp 65001");
    system("cls");
    while(1){
        cout<<"学生管理系统by Rand0w & REXWIND"<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"请输入你的操作:";
        cout.flush();
    }
}