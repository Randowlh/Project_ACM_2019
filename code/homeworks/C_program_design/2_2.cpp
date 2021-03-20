#include<bits/stdc++.h>
using namespace std;
struct node{
    node  *pre,*aft;
    int v;
}*head=NULL;
int cnt=0;
void insert(int v){
    if(head==NULL){
        head=new node;
        head->v=v;
        head->pre=head->aft=head;
        cnt++;
        return;
    }
    cnt++;
    node *tmp=new node;
    tmp->v=v;
    tmp->aft=head;
    head->pre->aft=tmp;
    tmp->pre=head->pre;
    head->pre=tmp;
    if(cnt==2)
        head->aft=tmp;
}
void pop(node *tmp){
    cnt--;
    if(tmp->aft==tmp){
        delete tmp;
        return;
    }
    tmp->pre->aft=tmp->aft;
    tmp->aft->pre=tmp->pre;
    delete tmp;
}
int stk[1000],tail;
int opt[1000];
int main(){
    int m,n;
    cin>>m;
    for(int i=1;i<=m;i++)
        stk[i]=i;
    tail=m;
    while(cin>>n){
        for(int i=1;i<=tail;i++)
            insert(stk[i]);
        tail=0;
        int now=1;
        node *pos=head;
        while(cnt){
            if(now%n==0){
                node * tt=pos;
                now++;
                pos=pos->aft;
                stk[++tail]=tt->v;
                pop(tt);
                continue;
            }
            now++;
            pos=pos->aft;
        } 
        head=NULL; 
    }
    for(int i=1;i<=tail;i++)
        cout<<stk[i]<<' ';
    cout<<endl;
}