#include<bits/stdc++.h>
using namespace std;
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
} zheng,fu;
int main(){
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp>0)
            zheng.insert(tmp);
        if(tmp<0)
            fu.insert(tmp);
    }
    cout<<"the linklist of the positive integer:"<<endl;
    while(!zheng.empty()){
        cout<<zheng.top()<<' ';
        zheng.pop();
    }
    cout<<endl;
    cout<<"the linklist of the negative integer:"<<endl;
    while(!fu.empty()){
        cout<<fu.top()<<' ';
        fu.pop();
    }   
    cout<<endl;
}
