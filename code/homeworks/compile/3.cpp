#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
 
string s;
int string_size;
int px; 
void E();void Ep();void T();void Tp();void F();
void error2(){ 
    cout<<"【Error】The brackets don't match"<<endl;
}
void error3(){ 
    cout<<"【Error】The recognition failed and the statement ended ahead of time"<<endl;
}
void E(){ 
	if(px>s.size())
		return;
    cout<<"E->TE'"<<endl;
    T(),Ep();
}
void Ep(){
	if(px>s.size())
		return;
    if(s[px]=='+'){
        px++,cout<<"E'->+TE'"<<endl;
        T(),Ep(); 
    }
    else 
        cout<<"E'->ε"<<endl;
}
void T(){
	if(px>s.size())
		return; 
    cout<<"T->FT'"<<endl;
    F(),Tp();
}
void Tp(){
	if(px>s.size())
		return;
    if(s[px]=='*'){
        px++,cout<<"T'->*FT'"<<endl;
        F(),Tp();
    }
    else 
        cout<<"T'->ε"<<endl;
}
void F(){ 
	if(px>s.size())
		return;
    if(s[px]=='i') 
        px++,cout<<"F->i"<<endl;
    else if(s[px]=='('){ 
        px++,cout<<"F->(E)"<<endl;
        E();
        if(s[px]==')') px++;
        else error2();
    }
}

int main(){
    system("chcp 65001");
	freopen("Test2.sy","r",stdin);
    cout<<"请输入需要递归下降分析的语句"<<endl;
    while(cin>>s){
    int string_size = s.size();
    px = 0; 
    E(); 
    if(px!=string_size) error3();
    cout<<"----done!"<<endl;
		cout<<endl<<endl;
	}
}
