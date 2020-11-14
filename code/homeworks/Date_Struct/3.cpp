#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const double huanjin = 0.618;
int n,m;
int now;
int tim;
struct ps{
   int weight,naixin,to,ti;
   ps(){
      to =  rand()%n+1;
      naixin=rand()%11+15+tim;
      weight=rand()%101+30; 
   }
};
struct node{
      ps date;
      node* nxt;
      node(ps a):date(a),nxt(NULL){}
};
struct que{
   
   node* head,*tail;
   bool empty(){
      return head==NULL;
   }
   void push(ps a){
      node* t=new node(a);
      if(empty()){
         head=t;
         tail=t;
         return;
      }
      tail->nxt=t;
      tail=t;
      return ;
   }
   void pop(){
      if(empty())
         return;
      node *t=head;
      head=head->nxt;   
      delete t;
      if(head=NULL)
         tail=NULL;
   }
}q[100],lt;
int cnt[100];
int too[1000];
int qz[1000];
int tt=0;
void quchu(int pos){
   while(q[pos].head!=NULL&&q[pos].head->date.naixin<tim){ 
      cnt[pos]++;
      q[pos].pop();
   }
   if(q[pos].empty())
      return;
   node* pr=q[now].head->nxt,* nn=q[now].head;
   while(nn!=NULL){
      if(nn->date.naixin<tim){
         pr->nxt=nn->nxt;
         node *d=nn;
         nn=nn->nxt;
         delete d;
         cnt[pos]++;
      }
   }
   return;
}
void flsh(){
   for(int i=1;i<=m+18;i++)
      cout<<"■";
   cout<<endl;
   for(int i=n;i>=1;i--){
      tt=0;
      //quchu(i);
      node *no=q[i].head;
      while(no!=NULL){
         too[++tt]=no->date.to;
         if(no->date.to>=10)
            qz[i]=qz[i-1]+4;
         else qz[i]=qz[i-1]+3;
         no=no->nxt;
      }
      for(int j=3;j>=1;j--){
         int q;
         cout<<"■";
         for(int k=1;k<=32;k++)
            if(now==((i-1)*3+j))
               cout<<"=";
            else
               cout<<" ";
         if(j%3!=1)
            cout<<"| ";
         else cout<<"■";
         if(j==3){
            for(q=1;q<=tt&&qz[q]<m*2-1;q++){
               cout<<"F"<<too[tt]<<" "; 
            } 
            for(int k=qz[q]+1;k<m*2-1;k++) 
               cout<<" ";
               cout<<"■";
         }else if(j==2){
            for(q=1;q<=tt&&qz[q]<m*2-1;q++){
               cout<<" # ";
               if(qz[q]-qz[q-1]==4)
                  cout<<" ";
            }
            for(int k=qz[q]+1;k<m*2-1;k++)
               cout<<" ";
               cout<<"■";
         }else{
            for(int i=1;i<=m;i++)
               cout<<"■";
         }
         cout<<endl;
      }
   }
   for(int i=1;i<=m+18;i++)
      cout<<"■";
   cout<<endl;
}
int main(){
   system("chcp 65001");
   srand(time(NULL));
   cin>>n;
   for(int i=1;i<=n;i++){
      int t=rand()%8;
      for(int j=1;j<=t;j++)
         q[i].push(ps());
   }
   now=7;
   m=n*4/huanjin+4;
   system("cls");
   flsh();
   system("pause");
}