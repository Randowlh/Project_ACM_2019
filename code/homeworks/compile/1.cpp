#include<bits/stdc++.h>
using namespace std;
string program;
string tp[]={"Reserved_word","Operator","Identifier","constant","Delimiter"};
set<string> Reserved={"begin","if","then","procedure","odd","call","else","while","do","const","var","end","do"};
string token;
int now=0;
int line=1;
#define is_char(x) ((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
#define is_num(x) (x>='0'&&x<='9')
string remove_prefix_zero(string &a){
    string ans;
    int flag=0;
    for(int i=0;i<a.length();i++){
        if(a[i]!='0')
            flag=1;
        if(flag)
            ans.push_back(a[i]);
    }
    return ans;
}
void single_lexical_analysis(){
    int n=program.size();
    int ans;
    token.clear();
    while(program[now]==' '||program[now]=='\t'||program[now]=='\n'){
        if(program[now]=='\n')
            line++;
        now++;
        if(now==n)
            return;
    }
    if(is_char(program[now])){
        while(is_char(program[now])||is_num(program[now]))
            token.push_back(program[now++]);
        ans=2;
        if(Reserved.count(token))
            ans=0;
        return ;
    }
    if(is_num(program[now])){
        while(is_num(program[now]))
            token.push_back(program[now++]);
        ans=3;
        if(is_char(program[now]))
            cout<<"[Error] The identifier cannot start with a number! "<<endl;
        ans=-1;
        return;
    }else{
        token.push_back(program[now]);
        if(program[now]=='<'||program[now]=='>'){
            ans = 1;
            now++;
            if(program[now]=='>'||program[now]=='=')//>> >=
                token.push_back(program[now]);
            else now--;
        }
        else if(program[now]=='='){
            ans = 1;
            now++;
            if(program[now]=='=') token.push_back('=');
            else now--;
        }
        else if(program[now]=='+'||program[now]=='-'||program[now]=='*'||program[now]=='/') type=1;
        //界符
        else if(ch==';'||ch=='('||ch==')'||ch==','||ch=='{'||ch=='}') type=4;
        else{
            cout<<"【错误】无法识别！"<<endl;
            type=-1;
        }
    }
}
int main(){
    char tmp;
    while((tmp=getchar())!=EOF)
        program.push_back(tmp);
    lexical_analysis(); 
}