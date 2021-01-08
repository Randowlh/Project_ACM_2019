#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
string depth[]={"数据表","地区","学校","学院","班级","学生"};//维护层次信息
struct rcd{
    int depth;//节点的深度（对应的记录类型）
    string name;//节点的名称
};
struct node{
    int l,r;//左右儿子的坐标
    rcd v;//该节点上储存的值
}tree[110000];//二叉树储存数组
int cnt;//搜索计数
int stk[110000];//记录对树上的点进行的删除插入操作的栈,如果为0则认为为修改操作
pair<int,string> stk2[110000];//记录对字段值进行的修改
int tail,tree_tail,tail2;
int flg[110000];//懒标记，如果flg[i]=1则认为这个节点为根子树被删除
int srt[110000];//排序用临时数组
vector<int> v;
string tmp;//搜索用
void dfs(int now,int dep){//递推打印树形结构
    if(!flg[now]){//
        for(int i=0;i<v.size();i++){//v数组用来保存上层结构如果v[i]为1则证明上层存在跨越现象
            if(v[i])
                cout<< "│ ";
            else cout<<"  ";
        }
        int flag=0;//flag用来判定这一节点是不是这一层的最后一个
        int tt=now;
        while(tree[tt].l){
            if(!flg[tree[tt].l]){
                flag=1;//如果找到则认为不是最后一个
                break;
            }
            tt=tree[tt].l;//一直向右找
        }
        if(flag) cout<<"├─ ";//打印相关图形
        else cout<<"└─ ";
        cout<<now<<' '<<depth[dep]<<':'<<tree[now].v.name<<endl;//输出层次
        if(tree[now].r){
            v.push_back(flag);
            dfs(tree[now].r,dep+1);//向下递归
            v.pop_back();
        }
    }
    if(tree[now].l) dfs(tree[now].l,dep);//向右递归
}
void flsh(){
    dfs(0,0);//从0号节点（树根）开始递归求解即可
    return;
}
void insert(int pos,string name){//插入函数
    int dd=tree[pos].v.depth;//由插入点的深度推得即将插入的点的深度
   if(!tree[pos].r){//如果插入点为叶子直接进行插入
        tree[pos].r=++tree_tail;
        stk[++tail]=tree_tail;
        tree[tree_tail].v=(rcd){dd+1,name};//对节点值进行初始化
        tree[tree_tail].r=tree[tree_tail].l=0;
        return;
    }
    pos=tree[pos].r;//切换到儿子层
    while(tree[pos].l)//一直向右找直到最后一个节点
        pos=tree[pos].l;
    tree[pos].l=++tree_tail;
    stk[++tail]=tree_tail;
    tree[tree_tail].v=(rcd){dd+1,name};//对插入节点进行初始化
    tree[tree_tail].r=tree[tree_tail].l=0;
    cout<<"插入成功"<<endl;
}
void change(){
    cout<<"请输入你要修改的位置 和要修改的名称"<<endl;
    int pos;
    string name;
    cin>>pos>>name;
    stk[++tail]=0;//将修改入栈
    stk2[++tail2]=make_pair(pos,tree[pos].v.name);//将具体的修改操作加入修改栈
    tree[pos].v.name=name;//更新节点名
}
void dfs2(int now){//用于搜索功能
    if(now==0) return;
    if(flg[now]==0){//没被删除的情况
        dfs2(tree[now].r);//访问儿子
        if(tree[now].v.name.find(tmp)!=tree[now].v.name.npos){srt[++cnt]=now;}//如果能够模糊1查找到，则将其加入答案数组
    }
    dfs2(tree[now].l);//都访问兄弟
}
void search(){
    system("cls");
    cout<<"请输入你要查找的字符串"<<endl;
   	cin>>tmp; 
    cnt=0;
    dfs2(tree[0].r);//搜索所有可能字串
    cout<<"为您找到以下字段:"<<endl;
    for(int i=1;i<=min(10,cnt);i++){
        cout<<srt[i]<<' '<<depth[tree[srt[i]].v.depth]<<":"<<tree[srt[i]].v.name<<endl;//输出字串
    }		
}
inline void del(){
    cout<<"请输入你要删除的字段编号"<<endl;
    int pos;
    cin>>pos;
    stk[++tail]=pos;//将删除操作加入操作栈
    flg[pos]=1;
    return;
}
void rev(){//回退操作
    if(stk[tail]){//如果上次操作是删除或增加操作
        flg[stk[tail--]]^=1;//修改对应的操作节点懒标记
    }else{
        tree[stk2[tail2].first].v.name=stk2[tail2].second;//对修改操作进行回退
        tail--;
        tail2--;
    }
}
void init(){
    insert(0,"杭州");//1⊥⊤—|◤◥◢◣◺◿
    insert(0,"北京");//2
    insert(1,"杭电");//3
    insert(2,"北大");//4
    insert(2,"清华");//5
    insert(3,"计算机学院");//6
    insert(3,"卓越学院");//7
    insert(3,"电子学院");
    insert(7,"和尚班");//9
}
int main(){
    system("chcp 65001");
    system("cls");
    tree[0].v.name="根目录/";//将树根赋值
    cout<<"是否放入作者预置的树信息?(1/0)"<<endl;
    int sbrsb; cin>>sbrsb; if(sbrsb) init();
    while(1){
        system("cls");
        flsh();
        cout<<"学生管理系统by Rand0w & REXWIND"<<endl;//打印欢迎和操作界面
        cout<<"◤—————————————————◥"<<endl;
        cout<<"│  1.插入 │     2.删除    │  3.修改  │"<<endl;
        cout<<"│  4.查询 │     5.回退    │  6.登出  │"<<endl;
        cout<<"◣—————————————————◢"<<endl;
        cout<<"请输入你的操作:";
        cout.flush();
        int chice;
        cin>>chice;
        if(chice==1){
            cout<<"请输入你要插入的位置 和要插入的名称"<<endl;
            int pos;string name;
            cin>>pos>>name;
            insert(pos,name);
        }
        else if(chice==2)
            del();
        else if(chice==3)
            change();
        else if(chice==4)
            search();
        else if(chice==5){
            if(!tail) cout<<"回退失败"<<endl;
            else{
                rev();
                cout<<"回退成功"<<endl;
            }
        }else if(chice==6)
            return 0;
        cout<<"按下任意键回到主菜单"<<endl;
        system("pause");
    }
}
