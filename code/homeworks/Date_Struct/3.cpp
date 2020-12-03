#include<bits/stdc++.h>
#include<fstream> 
#include<windows.h>
#include<time.h>
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
      while(to==from) to = rand()%n+1;
      naixin=rand()%11+15+tim;//耐心值要加上当前时间,方便计算
      weight=rand()%101+30;
   }
};
template<class T>
class que{//链表实现队列
   public:
   struct node{
	   T date;
	   node *nxt;
	   node(T a):date(a){nxt = NULL;}
   };
   node* head,*tail;
   bool empty(){
      return head==NULL;
   }
   void push(T a){
      node* t= new node(a);
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
      T *t=head;
      head=head->nxt;   
      delete t;
      if(head==NULL)
         tail=NULL;
   	}
	vector<T> quchu(int pos){//去除耐心已满 
   		while(head!=NULL&&head->date.naixin<tim){ 
      		pop();
   		}
		vector<T> ans;
   		if(empty())
      		return;
   		node* pr=head->nxt,* nn=head;
   		while(nn!=NULL){
			if(nn->date.naixin<tim){
				pr->nxt=nn->nxt;
				node *d=nn;
				nn=nn->nxt;
				ans.push_back(d->date);
				delete d;
			}
   		}
   		return;
	}
	vector<T> get(){
		vector<T> ans;
		node* now=head;
		while(now!=NULL){
			ans.push_back(now->date);
			now = now->nxt;
		}
		return  ans;
	}
};
que<ps> q[MAXN];//楼层队列
int qz[MAXN];
int tt=0;
struct Dianti{
	int mi;//当前楼层
	que<ps> ren;
	int zhuangtai;//-1下行,0停止,1上行 
	Dianti(int floor=0,int zhuangtai=0):mi(mi),zhuangtai(zhuangtai){}//电梯默认停止 
}dianti;

bool up_botton[MAXN];
bool down_botton[MAXN];

vector<ps> vec;
void flsh(){	
	rep(i,1,62) cout<<"■";
	cout<<endl;
	int buquan;//用于补全空格 
	int siz;
	repb(i,n,1){
		// check_botton();//遍历每一层的队列来检查上下按钮 
		repb(j,4,1){//每层包含地板高4 
			cout<<"■";
			int tmp_mi = (i-1)*4+j;//当前处理行数代表的米数
			if(tmp_mi==dianti.mi+3){
				buquan = 40;
				if(dianti.zhuangtai==-1){cout<<"电梯下行",buquan=40-8;}
				else if(dianti.zhuangtai==0){cout<<"电梯停止",buquan=40-8;}
				else if(dianti.zhuangtai==1){cout<<"电梯上行",buquan=40-8;}
				rep(i,1,buquan) cout<<" ";
			}
			else if(tmp_mi==dianti.mi+2){
				buquan = 40;
				rep(i,1,buquan) cout<<' ';
			}
			else if(tmp_mi==dianti.mi+1){
				vec = dianti.ren.get();
				siz = vec.size(); 
				rep(k,0,siz-1){
					int to = vec[k].to;
					cout<<'F';
					if(to/10) cout<<to<<' ';
					else cout<<to<<' '<<' ';
				}
				buquan = 40-siz*4;//补全空格 
				rep(i,1,buquan) cout<<" ";
			}
			else if(tmp_mi==dianti.mi||tmp_mi==dianti.mi+4){
				//印电梯的地板
				rep(i,1,20) cout<<"==";
			} 
			else rep(i,1,20) cout<<"  ";
			//楼层队列部分
			vec = (q[i]).get();
			siz = vec.size();
			up_botton[i] = down_botton[i] = 0;
			rep(k,0,siz-1){
				if(vec[k].to>i) up_botton[i] = 1;
				if(vec[k].to<i) down_botton[i] = 1;
				if(up_botton[i]&&down_botton[i]) break;
			} 
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
				rep(i,0,siz-1){
					int to = vec[i].to;
					cout<<"F";
					if(to/10) cout<<to<<' ';
					else cout<<to<<' '<<' ';
				}
				buquan = 80-siz*4;//补全空格  
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
void test(){//测试函数 
	n = 10;
	int tmp;
	rep(i,1,20){
		tmp=rand()%n+1;
		q[tmp].push(ps(tmp));
	}
	dianti.mi = rand()%(n*4-4)+1;
	cout<<"diantimi"<<dianti.mi<<endl;
	rep(i,1,7){
		tmp=rand()%n+1;
		(dianti.ren).push(ps(tmp));
	}
}
int main(){
	srand((unsigned)time(NULL));
	test();
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