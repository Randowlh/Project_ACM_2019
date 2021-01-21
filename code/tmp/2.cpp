#include<stdio.h>
struct node{
    int x,y;
    char name[5];
}date[100005];
int calc(int a,int b,int c,int i){
    double aa=0;
    aa+=a/(double)-c;
    aa+=date[i].x*b/(double)-c;
    if(date[i].name[0]=='A'){
        return date[i].y<aa;
    }else return date[i].y>aa;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%s",&date[i].x,&date[i].y,date[i].name);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int flag=0;
        for(int j=1;j<=n;j++)
            flag+=calc(a,b,c,j);
        if(flag&&flag!=n)
            printf("No\n");
        else printf("Yes\n");
    }
}