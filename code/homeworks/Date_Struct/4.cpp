#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int inf= 0x7FFFFFFF;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
int dp[310][310];
struct rcd{
    int num;
    string name;
};
struct node{
    int l,r;
    rcd v;
    node(){l=0,r=0;}
}tree[110000];
int stk[110000];
pair<int,string> stk2[110000];
int tail,tree_tail,tail2;
int flg[110000];
int lik[110000];
pair<int,int> srt[110000];
vector<int> v;
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
    if(!flg[now]){
        for(int i=0;i<dep-1;i++)
            if(v[i])
                cout<<'|';
            else cout<<' ';
        cout<<"↳"<<tree[now].v.name<<endl;
        if(tree[now].r){
            if(tree[now].l)
                v.push_back(1);
            else v.push_back(0);
            dfs(tree[now].r,dep+1);
            v.pop_back();
        }
    }
    if(tree[now].l)
        dfs(tree[now].l,dep);
}
void flsh(){
    dfs(1,1);
    return;
}
void insert(){
    cout<<"请输入你要插入的位置 和要插入的名称"<<endl;
    int pos;
    string name;
    cin>>pos>>name;
    pos=lik[pos];
    if(!tree[pos].l){
        tree[pos].l=++tree_tail;
        stk[++tail]=tree_tail;
        tree[tree_tail].v=(rcd){tree[pos].v.num*10+1,name};
        lik[tree[pos].v.num*10+1]=tree_tail;
        tree[tree_tail].l=tree[tree_tail].r=0;
        return;
    }
    pos=tree[pos].l;
    while(tree[pos].r)
        pos=tree[pos].r;
    tree[pos].r=++tree_tail;
    stk[++tail]=tree_tail;
    lik[tree[pos].v.num+1]=tree_tail;
    tree[tree_tail].v=(rcd){tree[pos].v.num+1,name};
    cout<<"插入成功"<<endl;
}
void change(){
    cout<<"请输入你要插入的位置 和要修改的名称"<<endl;
    int pos;
    string name;
    cin>>pos>>name;
    pos=lik[pos];
    stk[++tail]=0;
    stk2[++tail2]=make_pair(pos,tree[pos].v.name);
    tree[pos].v.name=name;
}
void search(){
    system("cls");
    cout<<"请输入你要查找的字符串"<<endl;
    string tmp;
    cin>>tmp;
    int cnt=0;
    for(int i=1;i<=tree_tail;i++){
        int flag=0;
        
    }
}
inline void del(){
    cout<<"请输入你要删除的字段编号"<<endl;
    int pos;
    cin>>pos;
    pos=lik[pos];
    stk[++tail]=pos;
    flg[pos]=1;
    return;
}
void rev(){
    if(stk[tail]){
        flg[stk[tail--]]^=1;
    }else{
        tree[stk2[tail2].first].v.name=stk2[tail2].second;
        tail2--;
    }
}
int main(){
    system("chcp 65001");
    system("cls");
    tree[0].v.name="根目录/";
    tree[0].v.num=0;
    while(1){
        cout<<"学生管理系统by Rand0w & REXWIND"<<endl;
        cout<<"1.插入"<<endl;
        cout<<"2.删除"<<endl;
        cout<<"3.修改"<<endl;
        cout<<"4.查询"<<endl;
        cout<<"5.回退"<<endl;
        cout<<"6.打印"<<endl;
        cout<<"请输入你的操作:";
        cout.flush();
        int chice;
        cin>>chice;
        if(chice==1)
            insert();
        else if(chice==2)
            del();
        else if(chice==3)
            change();
        else if(chice==4)
            search();
        else if(chice==5){
            if(!tail)
                cout<<"回退失败"<<endl;
            else{
                rev();
                cout<<"回退成功"<<endl;
            }
        }
        cout<<"按下任意键回到主菜单"<<endl;
        system("pause");
    }
}