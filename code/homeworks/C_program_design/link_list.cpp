#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
mt19937 rnd(514114);
struct fhq_treap
{
    struct node
    {
        int l, r;
        int val, key;
        int size;
    } fhq[110000];
    int cnt, root;
    inline int newnode(int val)
    {
        fhq[++cnt].val = val;
        fhq[cnt].key = rnd();
        fhq[cnt].size = 1;
        fhq[cnt].l = fhq[cnt].r = 0;
        return cnt;
    }
    void clear(){
        cnt=0;
        root=0;
    }
    inline void pushup(int now)
    {
    fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
    }
    void split(int now, int val, int &x, int &y)
    {
        if (!now)
        {
            x = y = 0;
            return;
        }
        else if (fhq[now].val <= val)
        {
        x = now;
        split(fhq[now].r, val, fhq[now].r, y);
        }
        else
        {
        y = now;
        split(fhq[now].l, val, x, fhq[now].l);
        }
    pushup(now);
    }
    int merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (fhq[x].key > fhq[y].key)
        {
            fhq[x].r = merge(fhq[x].r, y);
            pushup(x);
            return x;
        }
        else
        {
            fhq[y].l = merge(x, fhq[y].l);
            pushup(y);
            return y;
        }
    }
    inline void insert(int val)
    {
        int x, y;
        split(root, val, x, y);
        root = merge(merge(x, newnode(val)), y);
    }
    inline void del(int val)
    {
        int x, y, z;
        split(root, val - 1, x, y);
        split(y, val, y, z);
        y = merge(fhq[y].l, fhq[y].r);
        root = merge(merge(x, y), z);
    }
    inline int getrk(int num)
    {
        int x, y;
        split(root, num - 1, x, y);
        int ans = fhq[x].size + 1;
        root = merge(x, y);
        return ans;
    }
    inline int getnum(int rank)
    {
        int now=root;
        while(now)
        {
            if(fhq[fhq[now].l].size+1==rank)
               break;
            else if(fhq[fhq[now].l].size>=rank)
                now=fhq[now].l;
            else
             {
                rank-=fhq[fhq[now].l].size+1;
                now=fhq[now].r;
            }
        }
        return fhq[now].val;
    }
    inline int pre(int val)
    {
        int x, y, ans;
        split(root, val - 1, x, y);
        int t = x;
        while (fhq[t].r)
            t = fhq[t].r;
        ans = fhq[t].val;
        root = merge(x, y);
        return ans;
    }
    inline int aft(int val)
    {
        int x, y, ans;
        split(root, val, x, y);
        int t = y;
        while (fhq[t].l)
            t = fhq[t].l;
        ans = fhq[t].val;
        root = merge(x, y);
        return ans;
    }
} tree;
struct node
    {
        int v;
        node *next = NULL;
        node(){}
        node(int a):v(a){}
    };
class link_list
{
public:
    int sz;
    node *head = NULL;

public:
    bool empty()
    {
        return head == NULL;
    }
    void rgins(int v){
        sz++;
        if(empty()){
            head=new node(v);
            return;
        }
        node *now=head;
        while(now->next!=NULL)
            now=now->next;
        now->next= new node(v);
        return;
    }
    void insert(int v)
    {
        sz++;
        if (empty())
        {
            node *t = new node;
            t->v = v;
            t->next = NULL;
            head = t;
            return;
        }
        node *pr = NULL;
        node *now = head;
        while (now != NULL && now->v < v)
        {
            pr = now;
            now = now->next;
        }
        if (pr == NULL)
        {
            now = new node;
            now->v = v;
            now->next = head;
            head = now;
            return;
        }
        else if (now == NULL)
        {
            now = new node;
            now->v = v;
            now->next = NULL;
            pr->next = now;
            return;
        }
        else
        {
            node *t = new node;
            t->v = v;
            t->next = now;
            pr->next = t;
            return;
        }
    }
    int top()
    {
        return head->v;
    }
    void pop()
    {
        sz--;
        node *t;
        t = head;
        head = head->next;
        delete t;
        return;
    }
    void clear()
    {
        sz=0;
        while (!empty())
            pop();
    }
    vector<int> bianli()
    {
        vector<int> ans;
        node *now = head;
        while (now != NULL)
        {
            ans.push_back(now->v);
            now = now->next;
        }
        return ans;
    }
} T;
void mn(){
    cout<<"***************链表基本操作演示系统*****************"<<endl;
    cout<<"$     1.创建链表            2.显示链表            $"<<endl;
    cout<<"$     3.清空链表            4.链表排序            $"<<endl;
    cout<<"$     5.通过位置查找元素     6.通过值查找元素      $"<<endl;
    cout<<"$     7.指定位置插入元素     8.删除指定位置元素    $"<<endl;
    cout<<"$     9.删除指定值的元素     10.去除重复的元素     $"<<endl;
    cout<<"$     11.置逆链表           12.划分链表           $"<<endl;
    cout<<"$     13.从文件导入          14.导出到文件        $"<<endl;
    cout<<"$     15.求最大平台          16.退出             $"<<endl;
    cout<<"$$$$$$$$$$$$$$--Powered by Rand0w--$$$$$$$$$$$$$$$$"<<endl;
}
int main(){    
    system("chcp 65001");
    while(1){
        system("cls");
        mn();
        int opt;
        cin>>opt;
        if(opt==1){
            T.clear();
            cout<<"是否随机生成链表内元素？（y/n）"<<endl;
            char opp;
            cin>>opp;
            if(opp=='y'||opp=='Y'){
                cout<<"请输入元素个数"<<endl;
                int aa;
                cin>>aa;
                while(aa--){
                    T.rgins(rand()%100);
                }
            }
            cout<<"创建链表成功！"<<endl;
        }else if(opt==2){
            vector<int> tt=T.bianli();
            for(int i=0;i<tt.size();i++)
                cout<<tt[i]<<' ';
            cout<<endl;
        }else if(opt==3){
            T.clear();
            cout<<"清空链表成功"<<endl;
        }else if(opt==4){
            vector<int> tt;
            while(!T.empty()){
                tt.push_back(T.top());
                T.pop();
            }
            for(int i=0;i<tt.size();i++)
                T.insert(tt[i]);
            cout<<"链表排序成功"<<endl;
        }else if(opt==5){
            cout<<"请输入位置:";
            int pos=0;
            cin>>pos;
            if(pos<=0||pos>T.sz){
                cout<<"输入位置有误"<<endl;
            }else{
                pos--;
                node* now=T.head;
                while(pos){
                    pos--;
                    now=now->next;
                }
                cout<<"所求值为："<<now->v<<endl;
            }
        }else if(opt==6){
            cout<<"请输入要查找的值:";
            int qr;
            cin>>qr;
            int ff=0;
            int cnt=1;
            node * now=T.head;
            while(now!=NULL){
                if(now->v==qr){
                    ff=1;
                    break;
                }
                cnt++;
            }
            if(ff){
                cout<<"对应值的位置是:"<<cnt<<endl;
            }else{
                cout<<"找不到对应数"<<endl;
            }
        }else if(opt==7){
            cout<<"请输入要插入的位置";
            int pos=0;
            cin>>pos;
            if(pos<=0||pos>T.sz){
                cout<<"输入位置有误"<<endl;
            }else{
                int val;
                cout<<"请输入要插入的值:";
                cin>>val;
                node **now;
                now=&T.head;
                while(--pos)
                    now=&((*now)->next);
                node* a=new node(val);
                a->next=(*now)->next;
                (*now)->next=a;
            }
            cout<<"插入成功"<<endl;
        }else if(opt==8){
            cout<<"请输入要删除的位置";
            int pos=0;
            cin>>pos;
            if(pos<=0||pos>T.sz){
                cout<<"输入位置有误"<<endl;
            }else{
                node **now;
                now=&T.head;
                if(pos==1){
                    node *tt=T.head;
                    T.head=T.head->next;
                    delete tt;
                }else{
                    pos--;
                    while(--pos)
                        now=&((*now)->next);
                    node *tmp=(*now)->next;
                    (*now)->next=(*now)->next->next;
                    delete tmp;
                }
            }
            cout<<"删除成功"<<endl;
        }else if(opt==9){
            cout<<"请输入要删除的值：";
            int vv;
            cin>>vv;
            vector<int> v;
            while(!T.empty()){
                if(T.top()!=vv)
                    v.push_back(T.top());
                T.pop();
            }
            for(int i=0;i<v.size();i++)
                T.rgins(v[i]);
        }else if(opt==10){
            tree.clear();
            vector<int> v;
            while(!T.empty()){
                int tt=T.top();
                if(tree.pre(tree.aft(tt))!=tt){
                    T.insert(tt);
                    v.push_back(tt);
                }
                T.pop();
            }
            for(int i=0;i<v.size();i++)
                T.rgins(v[i]);
        }else if(opt==11){
            stack<int> s;
            while(!T.empty()){
                s.push(T.top());
                T.pop();
            }
            while(!s.empty()){
                T.rgins(s.top());
                s.pop();
            }
        }else if(opt==12){
            
        }else if(opt==13){
            
        }else if(opt==14){
            
        }else if(opt==15){
            
        }else if(opt==16){
            break;   
        }
        system("pause");
    }
}