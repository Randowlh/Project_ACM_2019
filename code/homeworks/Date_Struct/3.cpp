#include<bits/stdc++.h>
#include<fstream> 
#include<windows.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
const double huanjin = 0.618;
const int MAXN = 21;//最高设置21层楼
const int maxn = 510000;
mt19937 rnd(514114);
int tot=0;
template<class T>
class fhq_treap
{
	public:
	struct node
	{
		int l, r;
		T val;
		int key;
		int size;
	} fhq[maxn];
	int cnt, root;
	inline int newnode(T val)
	{
		fhq[++cnt].val = val;
		fhq[cnt].key = rnd();
		fhq[cnt].size = 1;
		fhq[cnt].l = fhq[cnt].r = 0;
		return cnt;
	}
	inline void pushup(int now)
	{
		fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
	}
	void split(int now, T val, int &x, int &y)
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
	inline void insert(T val)
	{
		int x, y;
		split(root, val, x, y);
		root = merge(merge(x, newnode(val)), y);
	}
	inline void del(T val)
	{
		int x, y, z;
		split(root, val - 1, x, y);
		split(y, val, y, z);
		y = merge(fhq[y].l, fhq[y].r);
		root = merge(merge(x, y), z);
	}
	inline int getrk(T num)
	{
		int x, y;
		split(root, num - 1, x, y);
		int ans = fhq[x].size + 1;
		root = merge(x, y);
		return ans;
	}
	inline T getnum(int rank)
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
	inline T pre(T val)
	{
		int x, y;
		T	ans;
		split(root, val - 1, x, y);
		int t = x;
		while (fhq[t].r)
			t = fhq[t].r;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
	inline T aft(T val)
	{
		int x, y;
		T  ans;
		split(root, val, x, y);
		int t = y;
		while (fhq[t].l)
			t = fhq[t].l;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
	inline bool count(T val){
		int x,y;
		split(root,val,x,y);
		int t=x;
		while(fhq[t].r)
			t=fhq[t].r;
		return val==fhq[t].val
	}
};
int n,m;
int now;
int tim;
int SLPT=300,TOT_TIME;
struct ps{//人
   int weight,naixin;
   int from,to;//从哪里到哪里
   ll  num;
   ps(int frm){//乘客生成
	  num=++tot;
      from = frm;
      to =  rand()%n+1;
      while(to==from) to = rand()%n+1;
      naixin=rand()%11+15+tim;//耐心值要加上当前时间,方便计算
      weight=rand()%101+30; 
   	}
	bool operator==(ps a){
		return num==a.num;
	}
};
fhq_treap<ps> s;
template<class T>
class que{//链表实现队列
   public:
   struct node{
	   T date;
	   node *nxt;
	   node(T a):date(a){}
   };
   node* head,*tail;
   T front(){
	   if(head!=NULL)
			return  head->date;
   }
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
	vector<T> quchu(){//去除耐心已满 
   		while(head!=NULL&&q[pos].head->date.naixin<tim){ 
      		cnt[pos]++;
      		pop();
   		}
		vector<T> ans;
   		if(q[pos].empty())
      		return;
   		node* pr=q[now].head->nxt,* nn=q[now].head;
   		while(nn!=NULL){
			if(nn->date.naixin<tim){
				pr->nxt=nn->nxt;
				node *d=nn;
				nn=nn->nxt;
				ans.push_back(d->date);
				delete d;
				cnt[pos]++;
			}
   		}
   		return;
	}
	vector<T> get(){
		vector<T> ans;
		node* now=head;
		while(now!=NULL){
			ans.push_back(now->date);
		}
		return  ans;
	}
};
que<ps> q[MAXN];//楼层队列
int cnt[MAXN];
int qz[MAXN];
int tt=0;
struct Dianti{
	int mi;//当前离地高度
	que<ps> ren;
	int to;
	int zhuangtai;//-1下行,0停止,1上行 
	Dianti(int floor=0,int zhuangtai=0):mi(floor*3-3),zhuangtai(zhuangtai){}//电梯默认停止 
}dianti;
que<pair<int,int>> zt;
bool up_botton[MAXN];
bool down_botton[MAXN];
// void check_botton(){//检查每个楼层的上下按钮 
// 	rep(i,1,n){
// 		up_botton[i]=down_botton[i] = 0;
// 		node *px = q[i].head; 
// 		while(px!=NULL){
// 			if((px->date).to<i) down_botton[i]=1;//有人要下楼 
// 			if((px->date).to>i) up_botton[i] = 1;//有人要上楼
// 			if(up_botton[i]&&down_botton[i]) break; 
// 			px = px->nxt;
// 		}
// 	}
// }

void flsh(){	
// 	rep(i,1,62) cout<<"■";
// 	cout<<endl;
// 	int buquan;//用于补全空格 
// 	repb(i,n,1){
// 		// check_botton();//遍历每一层的队列来检查上下按钮 
// 		repb(j,4,1){//每层包含地板高4 
// 			cout<<"■";
// 			if(j==4){
// 				buquan = 40;
// 				if(dianti.floor==i){
// 					if(dianti.zhuangtai==-1){cout<<"电梯下行",buquan=40-8;}
// 					else if(dianti.zhuangtai==0){cout<<"电梯停止",buquan=40-8;}
// 					else if(dianti.zhuangtai==1){cout<<"电梯上行",buquan=40-8;}
// 				}
// 				rep(i,1,buquan) cout<<" ";
// 			}
// 			if(j==3){
// 				buquan = 40;
// 				rep(i,1,buquan) cout<<' ';
// 			}
// 			else if(j==2){
// 				buquan = 40;
// 				if(dianti.floor==i){
// 					int cnt = 0;
// 					node *px = (dianti.ren).head;
// 					while(px!=NULL&&cnt<10){//一个人占用4列,//电梯20*2列最多显示10个人 
// 						int to = (px->date).to;
// 						cout<<"F";
// 						if(to/10) cout<<to<<' ';
// 						else cout<<' '<<to<<' ';
// 						cnt++;
// 						px = px->nxt; 
// 					}
// 					buquan = 40-cnt*4;//补全空格  
// 				}
// 				rep(i,1,buquan) cout<<" ";
// 			}
// 			else if(j==1){
// 				//印电梯 
// 				if(dianti.floor==i||dianti.floor+1==i){
// 					rep(i,1,20) cout<<"==";
// 				}
// 				else{
// 					rep(i,1,20) cout<<"  ";
// 				}
// 			} 
// 			//楼层队列部分
// 			if(j==4){
// 				if(up_botton[i]){cout<<"▲";buquan = 80-2;}
// 				else {cout<<"△";buquan = 80-2;}
// 				rep(i,1,buquan) cout<<' ';
// 			} 
// 			else if(j==3){
// 				if(up_botton[i]){cout<<"▼";buquan = 80-2;}
// 				else {cout<<"▽";buquan = 80-2;}
// 				rep(i,1,buquan) cout<<' ';
// 			}
// 			else if(j==2){
// 				int cnt = 0;
// 				node *px = q[i].head;
// 				while(px!=NULL&&cnt<20){//一个人占用4列,//电梯40*2列最多显示20个人 
// 					int to = (px->date).to;
// 					cout<<"F";
// 					if(to/10) cout<<to<<' ';
// 					else cout<<' '<<to<<' ';
// 					cnt++;
// 					px = px->nxt; 
// 				}
// 				buquan = 80-cnt*4;//补全空格  
// 				rep(i,1,buquan) cout<<' ';
// 			}
// 			else if(j==1){
// 				rep(i,1,40) cout<<"■";
// 			} 
// 			cout<<"■";
// 			cout<<endl;
// 		}
// 	}
}//已经基本完成了这部分 
void work(){
	while((double)clock()/CLOCKS_PER_SEC<TOT_TIME){
		ps a(rand()%n+1);
		q[a.from].push(a);
		zt.push(make_pair(a.to,a.num));
		flsh();
		if(dianti.zhuangtai==0){
			while(!zt.empty()){
				pair<int,int> t=zt.front();
				if(s.count(t.second)){
					dianti.to=t.first;
					dianti.zhuangtai=((dianti.mi/3)<t.first);
					if(!dianti.zhuangtai)
						dianti.zhuangtai=-1;
				}
			}
		}else if(dianti.zhuangtai==1){
			
		}else{

		}
	}
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
		

	system("cls");
	flsh();
	system("pause");
}