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
        node *tmp=new node;
        tmp->v=v;
        if(head==NULL||head->v>v){    
            tmp->next=head;
            head=tmp;
            return;
        }
        node **now=&head;
        while(((*now)->next)!=NULL&&(*now)->next->v<=v)    
            now=&((*now)->next);
        tmp->next=((*now)->next);
        (*now)->next=tmp;
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
} lst[2];
int main(){
    cout<<"input the number of integers of the first linklist:"<<endl;
    int n;
    cin>>n;
    cout<<"input the integers of the first linklist:"<<endl;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        lst[0].insert(tmp);
    }
    cout<<"input the number of integers of the second linklist:"<<endl;
    cin>>n;
    cout<<"input the integers of the second linklist:"<<endl;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        lst[1].insert(tmp);
    }
    cout<<"the first linklist:";
    node *now=lst[0].head;
    while(now!=NULL){
        cout<<now->v<<' ';
        now=now->next;
    }
    cout<<endl;
    cout<<"the second linklist:";
    now=lst[1].head;
    while(now!=NULL){
        cout<<now->v<<' ';
        now=now->next;
    }
    cout<<endl;
    cout<<"Merging"<<endl;
    while(!lst[1].empty()){
        lst[0].insert(lst[1].top());
        lst[1].pop();
    }
    cout<<endl;
    cout<<"the linklist after merging is:";
    while(!lst[0].empty()){
        cout<<lst[0].top()<<' ';
        lst[0].pop();
    }
    cout<<endl;
}