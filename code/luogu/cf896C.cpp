#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    mutable int v;
    node(){}
    node(int a,int b,int c):l(a),r(b),v(c){}
    bool operator<(const node a)const{
        if(l==a.l)
            return r<a.r;
        else return l<a.r;
    }
};
auto split(int l,int r,int v){
           
}
set<node> kdl_tree;
int main(){

}