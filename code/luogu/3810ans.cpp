#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 222222
int n,tot,k,num[maxn];
struct node
{
    int x,y,z,cnt,ans;
}p[maxn];
int cmpx(node a,node b)
{
    if(a.x!=b.x)return a.x<b.x;
    if(a.y!=b.y)return a.y<b.y;
    return a.z<b.z;
}
int cmpy(node a,node b)
{
    if(a.y!=b.y)return a.y<b.y;
    return a.z<b.z;
}
struct BIT 
{
    #define lowbit(x) (x&(-x))
    int b[maxn];
    void init()
    {
        memset(b,0,sizeof(b));
    }
    void update(int x,int v)
    {
        while(x<=k)
        {
            b[x]+=v;
            x+=lowbit(x);
        }
    }
    int query(int x)
    {
        int ans=0;
        while(x)
        {
            ans+=b[x];
            x-=lowbit(x);
        }
        return ans;
    }
    void clear(int x)
    {
        while(x<=k)
        {
            b[x]=0;
            x+=lowbit(x);
        }
    }
}bit;
void CDQ(int l,int r)
{
    if(l==r)
    {
        p[l].ans+=p[l].cnt-1;
        return ;
    }
    int mid=(l+r)>>1; 
    CDQ(l,mid);
    CDQ(mid+1,r);
    sort(p+l,p+mid+1,cmpy);
    sort(p+mid+1,p+r+1,cmpy);
    int j=l;
    for(int i=mid+1;i<=r;i++)
    {
        for(;j<=mid&&p[j].y<=p[i].y;j++)
            bit.update(p[j].z,p[j].cnt);
        p[i].ans+=bit.query(p[i].z);
    }
    for(int i=l;i<j;i++)bit.update(p[i].z,-p[i].cnt);
    sort(p+l,p+r+1,cmpy);
}
int main()
{
    freopen("in.txt", "r", stdin);
    bit.init();tot=0;
    memset(num,0,sizeof(num));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),p[i].ans=1; 
    sort(p+1,p+n+1,cmpx);
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&p[i-1].x==p[i].x&&p[i-1].y==p[i].y&&p[i-1].z==p[i].z)
            p[tot].cnt++;
        else p[++tot]=p[i],p[tot].cnt=1;
    }
    CDQ(1,tot);
    sort(p+1,p+tot+1,cmpx);
    for(int i=1;i<=tot;i++)num[p[i].ans]+=p[i].cnt;
    for(int i=1;i<=n;i++)printf("%d\n",num[i]);
    return 0;
}