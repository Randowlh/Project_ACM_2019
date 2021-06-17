#include <bits/stdc++.h>
#define re read()
#define ll long long
#define pb(a) push_back(a)
#define mkp(a, b) make_pair(a, b)
#define mst(a, c) memset(a, c, sizeof(a))
#define rep(a, b, c) for(int (a) = (b); (a) <= (c); (a)++)
#define per(a, b, c) for(int (a) = (b); (a) >= (c); (a)--)
using namespace std;
int read()
{
	int num = 0; bool f = 0; char ch = getchar();
	while(ch < '0' || ch > '9') {f = (ch == '-'); ch = getchar();}
	while(ch >= '0' && ch <= '9') {num = (num << 1) + (num << 3) + ch - '0'; ch = getchar();}
	return f? -num : num;
}
int p, fl, stp;
string str, Matched;
void E();
void E_();
void T();
void T_();
void F();
void A();
void M();
void print(string s)
{
	cout<<setw(6)<<++stp<<"|"<<setw(17)<<Matched<<"|"<<setw(18)<<str.substr(p)<<"|"
		<<setw(5)<<str[p]<<"|"<<setw(22)<<s<<endl;
}
void Error()
{
	print("Error");
	p++; fl = 1; 
	if(p >= str.size())
	{
		puts("=====The current statement is not valid=====");
		exit(0);
	}
	cout<<setw(50)<<"Skip Current Symbol."<<endl; 
}
void E()
{
	if(str[p] == 'i' || str[p] == '(') 
	{
		print("E->TE'");
		T(); E_();
	}
	else Error();
}
void E_()
{
	if(str[p] == '+' || str[p] == '-') 
	{
		print("E'->ATE'");
		A(); T(); E_();
		
	}
	else if(str[p] == ')' || str[p] == '$') print("E'->e");
	else Error();
}
void T()
{
	if(str[p] == 'i' || str[p] == '(') 
	{
		print("T->FT'");
		F(); T_();
	}
	else Error();
}
void T_()
{
	if(str[p] == '*' || str[p] == '/')
	{
		print("MFT'");
		M(); F(); T_();
	}
	else if(str[p] == ')' || str[p] == '+' || str[p] == '-' || str[p] == '$') print("T'->e");
	else Error();
}
void F()
{
	if(str[p] == 'i') 
	{
		print("F->i");
		Matched += str[p++];
	}
	else if(str[p] == '(')
	{
		print("F->(E)");
		Matched += str[p++]; E(); Matched += str[p++];
	}
	else Error();
}
void A()
{
	if(str[p] == '+')
	{
		print("A->+");
		Matched += str[p++];
	}
	else if(str[p] == '-')
	{
		print("A->-");
		Matched += str[p++];
	}
	else Error();
}
void M()
{
	if(str[p] == '*')
	{
		print("M->*");
		Matched += str[p++];
	}
	else if(str[p] == '/')
	{
		print("M->/");
		Matched += str[p++];
	}
	else Error();
}
int main()
{
//	clock_t TAT = clock();
//=====================================
	ifstream read("Test1.sy");
	getline(read, str); str += "$";
	cout<<"=Step=|=====Matched=====|=====Sentence=====|=Now=|========Action========"<<endl;
	p = 0; E();
	if(fl) cout<<setw(60)<<"=====The current statement is not valid====="<<endl;
	else cout<<setw(57)<<"=====The current statement is valid====="<<endl; 
//=====================================
//	cout<<"Time::"<<clock() - TAT<<"ms"<<'\n';
	return 0;
}


