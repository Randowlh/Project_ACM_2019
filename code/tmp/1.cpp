const double PI=acos(-1);
struct CP{
   double x,y;
   CP(double x=0,double y=0):x(x),y(y){}
   CP operator +(const CP &A)const{return CP(x+A.x,y+A.y);}
   CP operator -(const CP &A)const{return CP(x-A.x,y-A.y);}
   CP operator *(const CP &A)const{return CP(x*A.x-y*A.y,x*A.y+y*A.x);}
};
int limit,rev[SIZE];
void DFT(CP *F,int op){
   for(int i=0;i<limit;i++)if(i<rev[i])swap(F[i],F[rev[i]]);
   for(int mid=1;mid<limit;mid<<=1){
      CP wn(cos(PI/mid),op*sin(PI/mid));
      for(int len=mid<<1,k=0;k<limit;k+=len){
         CP w(1,0);
         for(int i=k;i<k+mid;i++){
            CP tmp=w*F[i+mid];
            F[i+mid]=F[i]-tmp;
            F[i]=F[i]+tmp;
            w=w*wn;
         }
      }
   }
   if(op==-1)for(int i=0;i<limit;i++)F[i].x/=limit;
}
void FFT(int n,int m,CP *F,CP *G){
   for(limit=1;limit<=n+m;limit<<=1);
   for(int i=0;i<limit;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?limit>>1:0);
   DFT(F,1),DFT(G,1);
   for(int i=0;i<limit;i++)F[i]=F[i]*G[i];
   DFT(F,-1);
}