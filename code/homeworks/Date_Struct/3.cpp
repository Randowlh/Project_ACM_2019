#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define bug cout<<"here"<<endl;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
typedef long long ll;
const double huanjin = 0.618;
const int MAXN = 210000;//最高设置21层楼
const int maxn = 510000;
mt19937 rnd(514114);
int tot=0;
template<typename T>
class vect{
	public:
		T* date;
	int lim;
	int sz;
	vect(){date=new T[1],lim=1,sz=0;}
	~vect(){delete[] date;}
	T operator[](int i){return date[i];}
	int size(){return sz;}
	void push(T a){
		if(sz+1>lim){
			T *tmp=date;
			lim<<=1;
			date=new T[lim];
			for(int i=0;i<sz;i++)
				date[i]=tmp[i];
			delete [] tmp;
		}
		date[sz]=a;
		sz++;
	}
	void pop(){
		if(sz>0)
			sz--;
	}
};
struct fhq_treap
{
	struct node
	{
		int l, r;
		int val, key;
		int size;
	} fhq[maxn];
	int cnt, root;
	inline int newnode(int val)
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
	void split(int now, int val, int &x, int &y)
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
	inline void insert(int val)
	{
		int x, y;
		split(root, val, x, y);
		root = merge(merge(x, newnode(val)), y);
	}
	inline void del(int val)
	{
		int x, y, z;
		split(root, val - 1, x, y);
		split(y, val, y, z);
		y = merge(fhq[y].l, fhq[y].r);
		root = merge(merge(x, y), z);
	}
	inline int getrk(int num)
	{
		int x, y;
		split(root, num - 1, x, y);
		int ans = fhq[x].size + 1;
		root = merge(x, y);
		return ans;
	}
	inline int getnum(int rank)
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
	inline int pre(int val)
	{
		int x, y, ans;
		split(root, val - 1, x, y);
		int t = x;
		while (fhq[t].r)
			t = fhq[t].r;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
	inline int aft(int val)
	{
		int x, y, ans;
		split(root, val, x, y);
		int t = y;
		while (fhq[t].l)
			t = fhq[t].l;
		ans = fhq[t].val;
		root = merge(x, y);
		return ans;
	}
	inline bool count(int val){
		int x,y;
		split(root,val,x,y);
		int t=x;
		while(fhq[t].r)
			t=fhq[t].r;
		return fhq[t].val==val;
	}
} tree;
int n,m;
int now;
int tim;
int SLPT=10,TOT_TIME;
struct ps{//人
   int weight,naixin;
   int from,to;//从哪里到哪里
   ll  num;
	bool operator==(ps a){
		return num==a.num;
	}
	bool operator<=(ps a)const{
		return num<=a.num;
	}
	friend ostream& operator<<(ostream &out,ps a){
		out<<a.num<<": "<<a.from<<"->"<<a.to<<endl;
		return out;
	}
};

fhq_treap s,ins;
template<class T>
class que{//链表实现队列
   public:
   struct node{
	   T date;
	   node *nxt;
	   node(T a):date(a){}
   };
   node* head,*tail;
   void init(){
	   head=tail=NULL;
   }
   T front(){
		return  head->date;
   }
   bool empty(){
      return head==NULL;
   }
   void push(T a){
      node* t=new node(a);
	  t->nxt=NULL;
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
      if(head==NULL)
         tail=NULL;
   	}
	vector<T> quchu(){//去除耐心已满 
		vector<T> ans,tmp;
		node* now=head;
		while(now!=NULL){
			if(now->date.naixin<tim||!s.count(now->date.num))
				ans.push_back(now->date);
			else tmp.push_back(now->date);
			now=now->nxt;
		}
		while(!empty())
			pop();
		for(int i=0;i<tmp.size();i++)
			push(tmp[i]);
		return ans;
	}
	vector<T> get(){
		vector<T> ans;
		node* now=head;
		while(now!=NULL){
			ans.push_back(now->date);
			now=now->nxt;
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
	int zl;
	int hezai;
	int zhuangtai;//-1下行,0停止,1上行 
	void tichu(int t){
		vector<ps> v;
		while(!ren.empty()){
			if(ren.front().to!=t)
				v.push_back(ren.front());
			else zl-=ren.front().weight;
			ren.pop();
		}
		for(int i=0;i<v.size();i++){
			ren.push(v[i]);
		}
	}
	inline int lc(){
		return (mi-1)/4+1;
	}
	Dianti(int floor=0,int zhuangtai=0):mi(floor*3-3),zhuangtai(zhuangtai){}//电梯默认停止 
}dianti;
que<pair<int,int>> zt,inzt;
bool up_botton[MAXN];
bool down_botton[MAXN];
vector<ps> vec;
void flsh(){
	// for(int i=1;i<=n;i++)
	// 	q[i].quchu();	
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
				siz = min(10,siz);
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
			siz = min(siz,20);
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
				if(down_botton[i]){cout<<"▼";buquan = 80-2;}
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
}
void test(){//测试函数 
	n = 10;
	int tmp;
	rep(i,1,20){
		tmp=rand()%n+1;
		q[tmp].push(ps());
	}
	dianti.mi = rand()%(n*4-4)+1;
	cout<<"diantimi"<<dianti.mi<<endl;
	rep(i,1,7){
		tmp=rand()%n+1;
		(dianti.ren).push(ps());
	}
	flsh();
	system("pause");
}
ps gen(){
	ps a;
	a.num=++tot;
    a.from = rand()%n+1;;
    a.to =  rand()%n+1;
    while(a.to==a.from) a.to = rand()%n+1;
    a.naixin=rand()%11+15+tim;//耐心值要加上当前时间,方便计算
    a.weight=rand()%101+30; 
	return a;
}
void work(){
	//(double)clock()/CLOCKS_PER_SEC<TOT_TIME
	dianti.mi=1;
	while(1){
		tim++;
		ps a;
		a=gen();
		q[a.from].push(a);
		s.insert(a.num);
		zt.push(make_pair((ll)a.to,a.num));
		// system("cls");
		 flsh();
			cout<<"dianti.mi="<<dianti.mi<<' '<<dianti.to<<endl;;
		if(dianti.zhuangtai==0){
			dianti.tichu(dianti.lc());
			vec=q[dianti.lc()].get();
			for(int i=0;i<vec.size();i++){
				if(vec[i].from<vec[i].to&&dianti.zl+vec[i].weight<=dianti.hezai){
						s.del(vec[i].num);
						dianti.ren.push(vec[i]);
						bug;
						dianti.zl+=vec[i].weight;
						MAX(dianti.to,vec[i].to);
				}
			}
			if(!dianti.ren.empty()){
				dianti.zhuangtai=1;
				break;
			}
			for(int i=0;i<vec.size();i++){
				if(vec[i].from>vec[i].to&&dianti.zl+vec[i].weight<=dianti.hezai){
						s.del(vec[i].num);
						dianti.ren.push(vec[i]);
						bug;
						dianti.zl+=vec[i].weight;
						MAX(dianti.to,vec[i].to);
				}
			}
			if(!dianti.ren.empty()){
				dianti.zhuangtai=-1;
				break;
			}
			while(!zt.empty()){
				pair<int,int> t=zt.front();
				zt.pop();
				if(s.count(t.second)){
					dianti.to=t.first;
					dianti.zhuangtai=(dianti.lc()<t.first);
					if(!dianti.zhuangtai)
						dianti.zhuangtai=-1;
					break;
				}
			}
		}else if(dianti.zhuangtai==1){
			if(!((dianti.mi-1)%4)){
				bug;
				if(dianti.lc()==dianti.to){
					dianti.zhuangtai=0;
					continue;
				}
				dianti.tichu(dianti.lc());
				vec=q[dianti.lc()].get();
				for(int i=0;i<vec.size();i++){
					if(vec[i].from<vec[i].to&&dianti.zl+vec[i].weight<=dianti.hezai){
						s.del(vec[i].num);
						dianti.ren.push(vec[i]);
						bug;
						dianti.zl+=vec[i].weight;
						MAX(dianti.to,vec[i].to);
					}
				}
	  			}
			dianti.mi++;
		}else{
			if(!((dianti.mi-1)%4)){
				bug;
				if(dianti.lc()==dianti.to){
					dianti.zhuangtai=0;
					continue;
				}
				dianti.tichu(dianti.lc());
				vec=q[dianti.lc()].get();
				for(int i=0;i<vec.size();i++){
					if(vec[i].from>vec[i].to&&dianti.zl+vec[i].weight<=dianti.hezai){
						s.del(vec[i].num);
						dianti.ren.push(vec[i]);
						bug;
						dianti.zl+=vec[i].weight;
						MIN(dianti.to,vec[i].to);
					}
				}
			}
			dianti.mi--;
		}
	
	}
}
int main(){
	freopen("out.txt","w",stdout);
	n = 4;
	system("chcp 65001");
	// flsh();
	for(int i=1;i<=n;i++)
		q[i].init();
	srand(time(NULL));
	SLPT=100;
	TOT_TIME=1;
	tot=0;
	// cin>>n;
	// cout<<"请输入每次的间隔时间,单位为毫秒";
	// cin>>SLPT;//sleep time,刷新间隔时间
	// cout<<"请输入希望电梯运行的时间(模拟多少个时间点):"<<endl;
	// cin>>TOT_TIME;
	// ofstream fop;//输出流，输出电梯运行日志 
	// fop.open("check.txt");
	// cout<<"dadasdsa"<<endl;
	work();

	system("cls");
	flsh();
	system("pause");
}