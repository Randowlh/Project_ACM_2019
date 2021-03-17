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