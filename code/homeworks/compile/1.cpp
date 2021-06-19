#include<bits/stdc++.h>
using namespace std;
bool skipflag = false;
#define hexa(x) ((x>='a'&&x<='f')||(x>='A'&&x<='F'))
const set<char> boundary={',','l','{','}','(',')','[',']'};
const set<string> keyword={ "if", "while", "break", "continue", "return", "int", "const", "void", "else"};
const set<char> optword={'!','+','-','*','/','%','=','<','>','&','|'};
const set<string> opr={"", "!", "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||"};
const string typelist[]={"Keywords", "Identifier", "Const", "Delimiter", "Operator"};
const string Errors[]={"Invalid number","Invalid singal","Invalid character"};
struct node{
    int line,tp,id;
};
map<string,node> M;
bool check(string s){
    if(skipflag)
        return -1;
    int ans=0;
    if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){
        for(int i=2; i<s.size(); i++){
            if(isdigit(s[i])||isalpha(s[i])){
                ans<<=4;
                int t = (s[i] >= '0' && s[i] <= '9') ? s[i] - '0' : (s[i] >= 'a' && s[i] <= 'f') ? s[i] - 'a' + 10: s[i] - 'A' + 10;
				ans += t;
            }else return 0;
        }
    }else if(s[0]=='0')
        for(int i=1;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='7'){
                ans<<=3;
                int t=s[i]-'0';
                ans+=t;
            }else return 0;
        }
    else for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            ans*=10;
            int t = s[i]-'0';
            ans+=t;
        }else return 0;
    }
    return 1;
}
void info(string token,node a){
    if(skipflag)
        return;
    if (a.tp == 1)
		cout << "<" << a.id << ", " << token << ">" << '\n';
    else 
		cout << "<" << token << ">" << '\n';
	printf("LineNumber: %d\n", a.line);
	cout << "Type: " << typelist[a.tp] << '\n'<< '\n';
}
void errors(int tp,int line){
    if(skipflag)
        return;
    cout<<"--------------------------------------------"<<endl;
    cout<< "Error occur! In line: "<<line<<endl;
    cout<<Errors[tp]<<endl;
    cout<<"--------------------------------------------"<<endl;
}
void work(){
    int line=0;
    while(1){
        string tmp;
        if(!getline(cin,tmp))
            break;
        line++;
        int n=tmp.size();
        for(int i=0;i<n-1;){
            node aa;
            aa.line=line;
            string token="";
            if(tmp[i]==' '||tmp[i]=='\t'){
                i++;
                continue;
            }
            if(isalpha(tmp[i])||tmp[i]=='_'){
                while(isdigit(tmp[i])||isalpha(tmp[i])||tmp[i]=='_')
                    token.push_back(tmp[i++]);
                if(keyword.count(token)){
                    aa.tp=0;
                    info(token,aa);
                }else{
                    if(M.count(token))
                        info(token,M[token]);
                    else {
                        aa.tp=1,aa.id=M.size()+1;
                        M[token]=aa;
                        info(token,aa);
                    }
                }
                }else if(isdigit(tmp[i])){
                    while(isdigit(tmp[i])||hexa(tmp[i]))
                        token.push_back(tmp[i++]);
                        aa.tp=2;
                        if(!check(token))
                            errors(0,line);
                        else{
                            info(token,aa);
                            M[token]=aa;
                        }
                }else if(boundary.count(tmp[i])){
                    token.push_back(tmp[i]);
                    aa.tp=3;
                    info(token,aa);
                    i++;
                }else if(optword.count(tmp[i])){
                    while (optword.count(tmp[i]))
					    token.push_back(tmp[i++]);
                    if(token=="//")
                        break;
                    else if(token=="/*"){
                        i+=2;
                        skipflag=1;
                    }else if(token=="*/"){
                        i+=2;
                        skipflag=0;
                    }else if(opr.count(token)){
                        aa.tp=4;
                        info(token,aa);
                    }else
                        errors(1,line);
                }else
                    i++,errors(2,line);
        }
    }
}
int main(){
    freopen("tests/33_func_test1.sy","r",stdin);
    work();
}