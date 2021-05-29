#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define VERSION "2.2"
#define M 55
int n,m,wall[M][M],hole[M][M],box[M][M];
int step,dct,query,cross,rx[233],ry[233];
char str[M][M],title[M],o;
char atlas[M][M][M]={
	{"...#@.","@..*..","#*##..","..##*#","..X.&.",".@#..."},
	{"########...####","########..*####","########*....##","######.*..*..##"
	,"@@..##.###.#...","@@.X......*..*.","@@..#.####.####","#####......####"},
	{"####..#...##","##.*..*.#.##","...#.**#....","X*.....#*##.","#.*###**....","##..##.#*..."
	,"###@@@.#.*#.","###@@@@@#.*.","####@@@@@...","#######.#*.#","#######....#","#######...##"},
	{"..@*.##",".@*@*..","&*@*@X.",".@*@*.#","..@*..#"}
};int A[M]={6,8,12,5},B[M]={6,15,12,7};
struct pos{int x,y;}player;
struct node{
    pos man;int dct;
    vector<pos>box;
    node(){box.clear();}
}rec[M*M*M];
void color(int x){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);}
void clean(){system("cls");color(154);printf("欢迎来到jiedai的推箱子%s\n\n",VERSION);color(7);}
bool check(int x,int y,int cross){
    if(!cross)return x<1||x>n||y<1||y>m||wall[x][y];
    return x<0||x>n+1||y<0||y>m+1;
}
bool forward(int rx,int ry){
	int x=player.x+rx,y=player.y+ry,X=x+rx,Y=y+ry;
	if(check(x,y,cross))return 0;
	if(box[x][y])if(check(X,Y,0)||box[X][Y])return 0;
	return 1;
}
bool win(){
	for(int i=0;i<rec[step].box.size();i++)
		if(!hole[rec[step].box[i].x][rec[step].box[i].y])return 0;
	return 1;
}
void pt(){
    memset(box,0,sizeof(box));
    for(int i=0;i<rec[step].box.size();i++)box[rec[step].box[i].x][rec[step].box[i].y]=1;
    player.x=rec[step].man.x;player.y=rec[step].man.y;
    dct=rec[step].dct;
    clean();color(154);
    puts("按方向键进行移动,按删除键进行撤销");
    puts("按空格键查询步数,按#键将有神奇的事情发生...");
    puts("按0返回,按Esc键退出游戏");color(7);
    for(int i=0;i<=n+1;i++){
		printf("  ");
        for(int j=0;j<=m+1;j++){
			if(i==player.x&&j==player.y){
                color(15);if(check(i,j,0))color(63);
                if(dct==72)printf("↑");
                else if(dct==77)printf("→");
                else if(dct==80)printf("↓");
                else if(dct==75)printf("←");color(7);
            }else if(i==0||i==n+1||j==0||j==m+1||wall[i][j]){color(3);printf("■");}
			else if(box[i][j]){
				color(14);
                if(hole[i][j])color(12);
                printf("▓");
            }else if(hole[i][j]){color(3);printf("※");}
			else printf("  ");
        }puts("");
    }color(7);
}
void update(){
	node tmp;int i,j;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(box[i][j]){
		pos po;po.x=i,po.y=j;
		tmp.box.push_back(po);
	}tmp.man.x=player.x;tmp.man.y=player.y;
	tmp.dct=dct;rec[step]=tmp;
}
void playing(){
	dct=72;step=0;
	update();pt();
	int winstep=-1;
	while(o=getch()){
		int tp=0;
		if(o==72||o==77||o==80||o==75){
			if(forward(rx[o],ry[o])){
				int x=player.x+rx[o],y=player.y+ry[o];
				if(box[x][y]){box[x][y]=0;box[x+rx[o]][y+ry[o]]=1;}
				player.x=x;player.y=y;step++;
			}else tp=1;
			dct=o;update();
		}else if(o==8){tp=3,step=max(0,step-1);if(step<=winstep)winstep=-1;}
		else if(o==35)cross^=1;
		else if(o==48)break;
		else if(o==27)exit(0);
		else if(o==32)query^=1;
		else if(o!=-32)tp=2;
		pt();color(154);
		if(query)printf("当前步数为%d\n",step);
		if(win()||winstep!=-1){
			if(winstep==-1)winstep=step;
			printf("恭喜你,你赢了!您用了%d步。\n",winstep);
		}else if(tp==1){color(207);puts("对不起,你无法推动这个方块!");}
		else if(tp==2){color(207);puts("请使用↑↓←→来移动!");}
		else if(tp==3)puts("回滚成功");
		color(7);
	}
}
void in(){
	memset(wall,0,sizeof(wall));memset(hole,0,sizeof(hole));memset(box,0,sizeof(box));clean();
	puts("第一行输入两个整数n和m，表示地图的大小");puts("接下来n行，每行m个元素。");
	puts("'.'表示空地");puts("'#'表示墙");puts("'*'表示箱子");
	puts("'@'表示洞");puts("'X'表示人" );puts("'&'表示箱子已在洞上");
	scanf("%d%d",&n,&m);int i,j;
	for(i=1;i<=n;i++)scanf("%s",str[i]+1);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		o=str[i][j];
		if(o=='X')player.x=i,player.y=j;
		if(o=='#')wall[i][j]=1;
		if(o=='@'||o=='&')hole[i][j]=1;
		if(o=='*'||o=='&')box[i][j]=1;
	}playing();
}
void pass(){
	memset(wall,0,sizeof(wall));memset(hole,0,sizeof(hole));memset(box,0,sizeof(box));
	clean();puts("1.第一关");puts("2.第二关");puts("3.第三关");puts("4.第四关");
	puts("\n0.返回");puts("Esc.退出游戏");
	while(o=getch()){
		if(o>='1'&&o<='4'){
			int id=o-48-1;n=A[id];m=B[id];
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
				char o=atlas[id][i-1][j-1];
		    	if(o=='X')player.x=i,player.y=j;
		    	if(o=='#')wall[i][j]=1;
				if(o=='@'||o=='&')hole[i][j]=1;
				if(o=='*'||o=='&')box[i][j]=1;
	   		}playing();break;
		}else if(o==48)break;
	}
}
void Init(){
	sprintf(title,"推箱子%s by jiedai",VERSION);SetConsoleTitle(title);
	rx[72]=-1;rx[80]=1;ry[77]=1;ry[75]=-1;
}
void remain(){
	clean();puts("1.闯关模式");puts("2.输入模式");puts("Esc.退出游戏");
	while(o=getch()){
		if(o=='1'){pass();break;}
		else if(o=='2'){in();break;}
		else if(o==27)exit(0);
	}
}
int main(){Init();while(1)remain();}