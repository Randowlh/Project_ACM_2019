#include<bits/stdc++.h>
#include<fstream> 
#include<windows.h>
using namespace std;
const double huanjin = 0.618;
int n,m;
int now;
int tim;
int SLPT,TOT_TIME; 
struct ps{//人
   int weight,naixin,to,ti;
   ps(){//乘客生成
      to =  rand()%n+1;
      naixin=rand()%11+15+tim;
      weight=rand()%101+30; 
   }
};
struct node{//节点
      ps date;
      node* nxt;
      node(ps a):date(a),nxt(NULL){}
};
struct que{//链表实现队列
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
void quchu(int pos){//去除耐心已满 
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
   for(int i=1;i<m+18;i++)
      cout<<"■";
   cout<<endl;
   for(int i=n;i>=1;i--){
      tt=0;//记录总数 
      //quchu(i);
      node *no=q[i].head;
      qz[0] = 0;
      while(no!=NULL){
         too[++tt]=no->date.to;
         //维护前缀和
         if(no->date.to>=10)//大于10占用4  
            qz[tt]=qz[tt-1]+4;
         else qz[tt]=qz[tt-1]+3;//小于10占用3 
         no=no->nxt;
      }
      for(int j=3;j>=1;j--){
         int q;
         cout<<"�";
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
            q--;//debug
            for(int k=qz[q]+1;k<m*2-1;k++) 
               cout<<" ";
               cout<<"■";
         }else if(j==2){
            for(q=1;q<=tt&&qz[q]<m*2-1;q++){
               cout<<" # ";
               if(qz[q]-qz[q-1]==4)
                  cout<<" ";
            }
            q--;//debug
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
   for(int i=1;i<m+18;i++)
      	cout<<"■";
   	cout<<endl;
}
void run(){
	
}
int main(){
   system("chcp 65001");
   srand(time(NULL));
   cin>>n;
   cout<<"请输入每次的间隔时间,单位为毫秒";
   cin>>SLPT;//sleep time,刷新间隔时间
   cout<<"请输入希望电梯运行的时间:"<<endl;
   cin>>TOT_TIME;
   ofstream fop;//输出流，输出电梯运行日志 
   fop.open("check.txt");
   /* 
   for(int i=1;i<=n;i++){//一开始先生成几个人 
      int t=rand()%8;
      for(int j=1;j<=t;j++)
         q[i].push(ps());
   }
   */ 
   for(int i=1;i<=TOT_TIME;i++){//一会儿要改 
		run();
		sleep(SLPT);
		system("cls");
   }
   now=7;
   m=n*4/huanjin+4;
   system("cls");
   flsh();
   system("pause");
}