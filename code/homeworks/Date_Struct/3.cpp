#include<bits/stdc++.h>
#include<fstream> 
#include<windows.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
const double huanjin = 0.618;
const int MAXN = 21;//最高设置21层楼
int n,m;
int now;
int tim;
int SLPT=300,TOT_TIME;
struct ps{//人
   int weight,naixin;
   int from,to;//从哪里到哪里
   ps(int frm){//乘客生成
      from = frm;
      to =  rand()%n+1;
      while(to!=from) to = rand()%n+1;
      naixin=rand()%11+15+tim;//耐心值要加上当前时间,方便计算
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
}q[MAXN];

int cnt[MAXN];
int qz[MAXN];
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

struct Dianti{
	int floor;//当前楼层
	que ren;
	int zhuangtai;//-1下行,0停止,1上行 
	Dianti(int floor=0,int zhuangtai=0):floor(floor),zhuangtai(zhuangtai){}//电梯默认停止 
}dianti;

bool up_botton[MAXN];
bool down_botton[MAXN];

void check_botton(){//检查每个楼层的上下按钮 
	rep(i,1,n){
		up_botton[i]=down_botton[i] = 0;
		node*px = q[i].head; 
		while(px!=NULL){
			if((px->date).to<i) down_botton[i]=1;//有人要下楼 
			if((px->date).to>i) up_botton[i] = 1;//有人要上楼
			if(up_botton[i]&&down_botton[i]) break; 
			px = px->nxt;
		}
	}
}

void flsh(){	
	rep(i,1,62) cout<<"■";
	cout<<endl;
	int buquan;//用于补全空格 
	repb(i,n,1){
		check_botton();//遍历每一层的队列来检查上下按钮 
		repb(j,4,1){//每层包含地板高4 
			cout<<"■";
			if(j==4){
				buquan = 40;
				if(dianti.floor==i){
					if(dianti.zhuangtai==-1){cout<<"电梯下行",buquan=40-8;}
					else if(dianti.zhuangtai==0){cout<<"电梯停止",buquan=40-8;}
					else if(dianti.zhuangtai==1){cout<<"电梯上行",buquan=40-8;}
				}
				rep(i,1,buquan) cout<<" ";
			}
			if(j==3){
				buquan = 40;
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==2){
				buquan = 40;
				if(dianti.floor==i){
					int cnt = 0;
					node *px = (dianti.ren).head;
					while(px!=NULL&&cnt<10){//一个人占用4列,//电梯20*2列最多显示10个人 
						int to = (px->date).to;
						cout<<"F";
						if(to/10) cout<<to<<' ';
						else cout<<' '<<to<<' ';
						cnt++;
						px = px->nxt; 
					}
					buquan = 40-cnt*4;//补全空格  
				}
				rep(i,1,buquan) cout<<" ";
			}
			else if(j==1){
				//印电梯 
				if(dianti.floor==i||dianti.floor+1==i){
					rep(i,1,20) cout<<"==";
				}
				else{
					rep(i,1,20) cout<<"  ";
				}
			} 
			//楼层队列部分
			if(j==4){
				if(up_botton[i]){cout<<"▲";buquan = 80-2;}
				else {cout<<"△";buquan = 80-2;}
				rep(i,1,buquan) cout<<' ';
			} 
			else if(j==3){
				if(up_botton[i]){cout<<"▼";buquan = 80-2;}
				else {cout<<"▽";buquan = 80-2;}
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==2){
				int cnt = 0;
				node *px = q[i].head;
				while(px!=NULL&&cnt<20){//一个人占用4列,//电梯40*2列最多显示20个人 
					int to = (px->date).to;
					cout<<"F";
					if(to/10) cout<<to<<' ';
					else cout<<' '<<to<<' ';
					cnt++;
					px = px->nxt; 
				}
				buquan = 80-cnt*4;//补全空格  
				rep(i,1,buquan) cout<<' ';
			}
			else if(j==1){
				rep(i,1,40) cout<<"■";
			} 
			cout<<"■";
			cout<<endl;
		}
	}
}//已经基本完成了这部分 
void move(int from,int to){//电梯从from到to层
	 
}
void run(){
	
}
int main(){
   n = 5;
   flsh();
   system("pause");
   system("chcp 65001");
   srand(time(NULL));
   cin>>n;
   cout<<"请输入每次的间隔时间,单位为毫秒";
   cin>>SLPT;//sleep time,刷新间隔时间
   cout<<"请输入希望电梯运行的时间(模拟多少个时间点):"<<endl;
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
		Sleep(SLPT);
		system("cls");
   }
   now=7;
   m=n*4/huanjin+4;
   system("cls");
   flsh();
   system("pause");
}