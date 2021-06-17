#include <bits/stdc++.h>
#define re read()
#define ll long long
#define pb(a) push_back(a)
#define mkp(a, b) make_pair(a, b)
#define mst(a, c) memset(a, c, sizeof(a))
#define rep(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define per(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
using namespace std;
const int OpNum = 16,
		  KeNum = 10,
		  DeNum = 9,
		  TyNum = 11,
		  ChNum = 12;
string str;
bool Annotation_Flag;
//预定义sysY所有分界符
const char Delimiter_List[DeNum] = {' ', ',', ';', '{', '}', '(', ')', '[', ']'};
//预定义sysY所有关键字
const string Keyword_List[KeNum] = {"", "if", "while", "break", "continue", "return", "int", "const", "void", "else"};
//预定义sysY所有操作符
const char opChar_List[ChNum] = {' ', '!', '+', '-', '*', '/', '%', '=', '<', '>', '&', '|'};
const string Operator_List[OpNum] = {"", "!", "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||"};
const string Type_List[TyNum] = {"Keywords", "Identifier", "Const", "Delimiter", "Operator"};
struct NUMBER
{
	int Line_Num, type, id;
};
map<string, NUMBER> Num_Table;
map<string, NUMBER> Identifier_Name;
bool isChar(char ch)
{
	rep(i, 1, ChNum - 1) if (ch == opChar_List[i]) return 1;
	return 0;
}
int isKey(string s)
{
	rep(i, 1, KeNum - 1) if (s == Keyword_List[i]) return i;
	return -1;
}
int isOperator(string s)
{
	rep(i, 1, OpNum - 1) if (s == Operator_List[i]) return i;
	return -1;
}
int isDelimiter(char ch)
{
	rep(i, 1, DeNum - 1) if (ch == Delimiter_List[i]) return i;
	return -1;
}
bool isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	return 0;
}
bool isLetter(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;
	return 0;
}
bool isHex(char ch)
{
	if (ch >= 'x')
		return 1;
	if (ch >= '0' && ch <= '9')
		return 1;
	if ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
		return 1;
	return 0;
}
int NumNorm(string s)
{
	if (Annotation_Flag)
		return 0;
	int tmp = 0, n = s.size(), base = 1;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		per(i, n - 1, 2)
		{
			if (isDigit(s[i]) || ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F')))
			{
				int t = (s[i] >= '0' && s[i] <= '9') ? s[i] - '0' : (s[i] >= 'a' && s[i] <= 'f') ? s[i] - 'a' + 10
																								 : s[i] - 'A' + 10;
				tmp += base * t;
				base *= 16;
			}
			else
				return -1;
		}
	}
	else if (s[0] == '0')
	{
		per(i, n - 1, 1)
		{
			if (s[i] >= '0' && s[i] <= '7')
			{
				int t = s[i] - '0';
				tmp += base * t;
				base *= 8;
			}
			else
				return -1;
		}
	}
	else
	{
		per(i, n - 1, 0)
		{
			if (isDigit(s[i]))
			{
				int t = s[i] - '0';
				tmp += base * t;
				base *= 10;
			}
			else
				return -1;
		}
	}
	cout << "<" << s << ", " << tmp << ">" << '\n';
	return 1;
}
void PrintInfo(string token, NUMBER a)
{
	if (Annotation_Flag)
		return;
	if (a.type == 1)
		cout << "<" << a.id << ", " << token << ">" << '\n';
	else if (a.type != 2)
		cout << "<" << token << ">" << '\n';
	printf("LineNumber: %d\n", a.Line_Num);
	cout << "Type: " << Type_List[a.type] << '\n'
		 << '\n';
}
void PrintError(int type, int line)
{
	if (Annotation_Flag)
		return;
	printf("============ERROR%d:: ", type);
	if (type == 0)
		printf("Numerical system error");
	else if (type == 1)
		printf("Unknow signal");
	else if (type == 2)
		printf("Unknow character");
	printf(" at line %d============\n\n", line);
}
int main()
{
	//	clock_t TAT = clock();
	//=====================================
	ifstream read("Test.sy");
	int Line = 1;
	while (1)
	{
		getline(read, str);
		int i = 0, n = str.size();
		while (i < n)
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				i++;
				continue;
			}
			//get KeyWords or Identifier
			if (isLetter(str[i]))
			{
				NUMBER tmp;
				string token = "";
				while (isLetter(str[i]) || isDigit(str[i]) || str[i] == '_')
					token += str[i++];
				if (isKey(token) != -1)
				{
					tmp.Line_Num = Line;
					tmp.type = 0;
					PrintInfo(token, tmp);
				}
				else
				{
					if (Identifier_Name.find(token) == Identifier_Name.end())
					{
						tmp.Line_Num = Line;
						tmp.type = 1;
						tmp.id = Identifier_Name.size() + 1;
						Identifier_Name[token] = tmp;
						PrintInfo(token, tmp);
					}
					else
					{
						map<string, NUMBER>::iterator it;
						it = Identifier_Name.find(token);
						tmp = it->second;
						PrintInfo(token, tmp);
					}
				}
			}
			//get Number
			else if (isDigit(str[i]))
			{
				string token = "";
				NUMBER tmp;
				while (isDigit(str[i]) || isHex(str[i]))
					token += str[i++];
				tmp.Line_Num = Line, tmp.type = 2, tmp.id = Num_Table.size() + 1;
				int Insert_Flag = NumNorm(token);
				if (Insert_Flag == -1)
					PrintError(0, Line);
				else
					PrintInfo(token, tmp);
				if (Insert_Flag != -1 && Num_Table.find(token) == Num_Table.end())
					Num_Table[token] = tmp;
			}
			else if (isDelimiter(str[i]) != -1)
			{
				NUMBER tmp;
				string s = {str[i]};
				tmp.Line_Num = Line;
				tmp.type = 3;
				PrintInfo(s, tmp);
				i++;
			}
			else if (isChar(str[i]))
			{
				string token = "";
				while (isChar(str[i]))
					token += str[i++];
				if (token == "//")
				{
					i += 2;
					break;
				}
				else if (token == "/*")
				{
					i += 2;
					Annotation_Flag = 1;
					continue;
				}
				else if (token == "*/")
				{
					i += 2;
					Annotation_Flag = 0;
					continue;
				}
				else if (isOperator(token) != -1)
				{
					NUMBER tmp;
					tmp.Line_Num = Line;
					tmp.type = 4;
					PrintInfo(token, tmp);
				}
				else
					PrintError(1, Line);
			}
			else
			{
				i++;
				PrintError(2, Line);
			}
		}
		Line++;
		if (read.eof())
			break;
	}
	//=====================================
	//	cout<<"Time::"<<clock() - TAT<<"ms"<<'\n';
	return 0;
}
