#include<bits/stdc++.h>
using namespace std;
const int dimension =14;
const double learing_rate=0.002;
const double eps=0.001;
const int testnum = 50;
const int trainnum = 10000;
struct node{
    double date[dimension+1];
};
vector<node> date_set;
double tmp[100],w[100],tmpans[1100];
double maa[100],mii[100];
void read(){
    string tmp;
    for(int i=1;i<=dimension;i++)
        cin>>tmp;
    date_set.clear();
    node tt;
    freopen("housing.txt","r",stdin);
    while(cin>>tt.date[1]){
        for(int i=2;i<=dimension;i++)
            cin>>tt.date[i];
        date_set.push_back(tt);
    }
    freopen("CON","r",stdin);
}
void normalizeWay(int y,int opt){
    for(int i=1;i<=dimension;i++){
        double c=maa[i]-mii[i];
        if(opt)
            date_set[y].date[i]=date_set[y].date[i]-mii[i]/c;
        else
            date_set[y].date[i]=date_set[i].date[i]*c+mii[i];
    }
}
void normalize(int bg,int ed,int opt){
    for(int i=bg;i<=ed;i++)
        normalizeWay(i,opt);
}
void print(){
    for(int i=0;i<date_set.size();i++){
        cout<<i<<":\n";
        for(int j=0;j<dimension;j++)
            cout<<date_set[i].date[j]<<' ';
        cout<<"real prize: "<<date_set[i].date[dimension]<<endl;
    }
}
void calGD(){
    for(int i=0;i<dimension;i++){
        double pd=0;
        for(int j=0;j<date_set.size()-testnum;j++){
            double sum=0;
            for(int k=0;k<date_set.size();k++)
                sum+=w[k]*date_set[j].date[k];
            pd+=(sum-(date_set[j].date[dimension]))*date_set[j].date[i];
        }
    }
    cout<<"---------------------------"<<endl;
    for(int i=0;i<dimension;i++){
        w[i]=w[i]-tmp[i];
        cout<<"w["<<i<<"]="<<w[i]<<endl;
    }
}
double f(int y){
    double ans=-0;
    for(int i=0;i<dimension;i++)
        ans+=w[i]*date_set[y].date[i];
    return ans;
}
void predict(int y){
    cout<<"please input date with 13 dimension:"<<endl;
    for(int i=1;i<=dimension;i++)

}
double calloss(int y){
    predict(y);
    double loss=0;
    
}
double getRmse(){
    double ans=0;
    predict(1);
    normalize(0,date_set.size()-testnum,0);
    for(int i=date_set.size()-testnum;i<date_set.size();i++){
        cout<<i<<endl;
        for(int j=0;j<dimension;j++)
            cout<<date_set[i].date[j]<<' ';
        cout<<"real prize:"<<date_set[i].date[dimension]<<' ';
        cout<<"predict prize:"<<tmpans[i]<<endl;
        ans+=(tmpans[i]-date_set[i].date[dimension])*(tmpans[i]-date_set[i].date[dimension])/testnum;
    }
    ans=sqrt(ans);
    normalize(0,date_set.size()-testnum,1);
}

void init(){
    read();
    normalize(0,date_set.size(),1);
    for(int i=0;i<dimension;i++)
        tmp[i]=w[i]=1;
}
int main(){
    init();
    train();
    predict();
    del();
}