#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15, TerNum = 8, NonterNum = 9; 
string Analytical_Statement[TerNum][NonterNum] = {{}, // i        (       )       +        -       *        /       $
										/*E*/    {"", "::TE'", "::TE'", "NULL", "NULL",  "NULL", "NULL", "NULL", "NULL"},
										/*E'*/   {"", "NULL",  "NULL",  "::e",  "::ATE'","::ATE'","NULL","NULL", "::e"},
										/*T*/    {"", "::FT'", "::FT'", "NULL", "NULL",  "NULL", "NULL", "NULL", "NULL"},
										/*T'*/   {"", "NULL",  "NULL",  "::e",  "::e",   "::e",  "::MFT'","::MFT'","::e"}, 
										/*F*/    {"", "::i",   "::(E)", "NULL", "NULL",  "NULL", "NULL", "NULL", "NULL"}, 
										/*A*/    {"", "NULL",  "NULL",  "NULL", "::+",   "::-",  "NULL", "NULL", "NULL"}, 
										/*M*/    {"", "NULL",  "NULL",  "NULL", "NULL",  "NULL", "::*",  "::/",  "NULL"}};
int top, LasAct = -1, Lasx, Lasy;
string str, Match, sta[MAXN];
string Ter[TerNum] = {"", "E", "E'", "T", "T'", "F", "A", "M"};
string Nonter[NonterNum] = {"", "i", "(", ")", "+", "-", "*", "/", "$"};
map <string, int> Terminal;
map <string, int> Nonterminal; 
void init()
{
	top = 0;
	sta[++top] = "$"; sta[++top] = Ter[1];
	for(int i=1;i<=TerNum - 1;i++) Terminal[Ter[i]] = i, Nonterminal[Ter[i]] = -1;
	for(int i=1;i<=NonterNum - 1;i++) Nonterminal[Nonter[i]] = i, Terminal[Nonter[i]] = -1;
	cout<<"=Step=|=====Matched=====|=====Stack=====|=====Sentence=====|========Action========"<<endl;
}
string GetSta()
{
	string tmp = "";
	for(int i=top;i>=1;i--) tmp += sta[i];
	return tmp;
}
string GetAct()
{
	string tmp;
	int len = Match.size();
	if(LasAct == 0) tmp = "Matched " + (string){Match[len - 1]} + " Succefully";
	else if(LasAct == 1) tmp = Analytical_Statement[Lasx][Lasy];
	else if(LasAct == 2) tmp = "Accepted";
	else if(LasAct == -1) tmp = "";
	else tmp = "Error";
	return tmp;
}
int main()
{
//	clock_t TAT = clock();
//=====================================
	init();
	ifstream read("Test1.sy");
	getline(read, str); str += "$"; 
	int stp = 0, t = 0, len = str.size();
	while(1)
	{
		string StaPrint = GetSta(), ActPrint = GetAct(); 
		cout<<setw(6)<<++stp<<"|"<<setw(17)<<Match<<"|"<<setw(15)<<StaPrint<<"|"
			<<setw(18)<<str.substr(t)<<"|"<<setw(22)<<ActPrint<<endl;
		string tmp = {str[t]};
		if(top == 1) break;
		else if(sta[top] == tmp) top--, Match += str[t], LasAct = top == 1? 2 : 0, t++;
		else 
		{
			Lasx = Terminal[sta[top]], Lasy = Nonterminal[tmp];
			string Form = Analytical_Statement[Lasx][Lasy];
			if(Form == "NULL") t++, top--, LasAct = 3;
			else 
			{
				top--;
				string s = ""; 
				int len = Form.size();
				for(int i=len-1;i>=2;i--)
				{
					if(Form[i] == '\'') s = {Form[i - 1], Form[i]}, i--;
					else s = {Form[i]};
					if(s != "e") sta[++top] = s;
				}
				LasAct = 1;
			}
		}
	}
	return 0;
}


