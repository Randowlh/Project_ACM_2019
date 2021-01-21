#include<stdio.h>
int tt1=1,tt2=1;
int a[100005],b[100005];
int va[100005],vb[100005];
int n,an,bn;
int main(){
  scanf("%d%d%d",&n,&an,&bn);
  int ans=0;
  for(int i=1;i<=an;i++)
    scanf("%d%d",&a[i],&va[i]);
  for(int i=1;i<=bn;i++)
    scanf("%d%d",&b[i],&vb[i]);
  while(tt1<=an&&tt2<=bn){
    if(a[tt1]==b[tt2]){
      ans+=va[tt1]*vb[tt2];
      tt1++;
      tt2++;
    }else if(a[tt1]<b[tt2]){
      tt1++;
    }else 
      tt2++;
  } 
  printf("%d\n",ans);
}