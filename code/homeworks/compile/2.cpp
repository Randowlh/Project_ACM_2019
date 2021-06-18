#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15, TerNum = 8, NonterNum = 9; 
string mp[8][9] = {{},                  // i        (       )       +        -       *        /       $
							/*E*/    {"", "::TE'", "::TE'", "NULL", "NULL",  "NULL", "NULL", "NULL", "NULL"},
							/*E'*/   {"", "NULL",  "NULL",  "::e",  "::ATE'","::ATE'","NULL","NULL", "::e"},
							/*T*/    {"", "::FT'", "::FT'", "NULL", "NULL",  "NULL", "NULL", "NULL", "NULL"},
							/*T'*/   {"", "NULL",  "NULL",  "::e",  "::e",   "::e",  "::MFT'","::MFT'","::e"}, 
							/*F*/    {"", "::i",   "::(E)", "NULL", "NULL",  "NULL", "NULL", "NULL", "NULL"}, 
							/*A*/    {"", "NULL",  "NULL",  "NULL", "::+",   "::-",  "NULL", "NULL", "NULL"}, 
							/*M*/    {"", "NULL",  "NULL",  "NULL", "NULL",  "NULL", "::*",  "::/",  "NULL"}};
int top,  cs = -1, xx, yy;
string str, Match, sta[MAXN];
string Ter[] = {"", "E", "E'", "T", "T'", "F", "A", "M"};
string Nonter[] = {"", "i", "(", ")", "+", "-", "*", "/", "$"};
map <string, int> endsin;
map <string, int> noted; 
void init()
{
	top = 0;
	sta[++top] = "$"; sta[++top] = "E";
	for(int i=1;i<=TerNum - 1;i++) endsin[Ter[i]] = i, noted[Ter[i]] = -1;
	for(int i=1;i<=NonterNum - 1;i++) noted[Nonter[i]] = i, endsin[Nonter[i]] = -1;
	cout<<"=Step=|=====Matched=====|=====Stack=====|=====Sentence=====|========Action========"<<endl;
}
string getstk()
{
	string tmp = "";
	for(int i=top;i>=1;i--) tmp += sta[i];
	return tmp;
}
string getaa()
{
	string tmp;
	int len = Match.size();
	if( cs == 0) tmp = "Matched " + (string){Match[len - 1]} + " Succefully";
	else if( cs == 1) tmp = mp[xx][yy];
	else if( cs == 2) tmp = "Accepted";
	else if( cs == -1) tmp = "";
	else tmp = "Error";
	return tmp;
}
int main()
{
	init();
	ifstream read("Test2.sy");
	getline(read, str); str += "$"; 
	int stp = 0, t = 0, len = str.size();
	while(1)
	{
		string tstk = getstk(), tact = getaa(); 
		cout<<setw(6)<<++stp<<"|"<<setw(17)<<Match<<"|"<<setw(15)<<tstk<<"|"
			<<setw(18)<<str.substr(t)<<"|"<<setw(22)<<tact<<endl;
		string tmp = {str[t]};
		if(top == 1) break;
		else if(sta[top] == tmp) top--, Match += str[t],  cs = top == 1? 2 : 0, t++;
		else 
		{
			xx = endsin[sta[top]], yy = noted[tmp];
			string tmp= mp[xx][yy];
			if(tmp== "NULL") t++, top--,  cs = 3;
			else 
			{
				top--;
				string s = ""; 
				int len = tmp.size();
				for(int i=len-1;i>=2;i--)
				{
					if(tmp[i] == '\'') s = {tmp[i - 1], tmp[i]}, i--;
					else s = {tmp[i]};
					if(s != "e") sta[++top] = s;
				}
				 cs = 1;
			}
		}
	}
	return 0;
}


