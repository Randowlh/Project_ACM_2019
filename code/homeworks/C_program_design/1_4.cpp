#include<bits/stdc++.h>
using namespace std;
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
    void rgins(node * tt){
        sz++;
        if(empty()){
            head=tt;
            return;
        }
        node *now=head;
        while(now->next!=NULL)
            now=now->next;
        now->next= tt;
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
void split(){
    node **now=&lst[0].head;
    while((*now)!=NULL&&(*now)->next!=NULL){
        if((*now)->next->v%2==0){
            node *tt=(*now)->next;
            (*now)->next=tt->next;
            tt->next=NULL;
            lst[1].rgins(tt);
            continue;
        }
        now=&(*now)->next;
    }
    if(*(now)!=NULL){
        if((*now)->v%2==0){
            lst[1].rgins(*now);
            (*now)=NULL;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        lst[0].insert(tmp);
    }
    node *now=lst[0].head;
    cout<<"the link_list before split()"<<endl;
    while(now!=NULL){
        cout<<now->v<<' ';
        now=now->next;
    }
    cout<<endl;
    split();
    cout<<"the link_list after split()"<<endl;
    now=lst[0].head;
    while(now!=NULL){
        cout<<now->v<<' ';
        now=now->next;
    }
    cout<<endl;
    now=lst[1].head;
    while(now!=NULL){
        cout<<now->v<<' ';
        now=now->next;
    }
    cout<<endl;

}