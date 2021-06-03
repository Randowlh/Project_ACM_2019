#include<bits/stdc++.h>
using namespace std;
// 集训队 
template <class T> 
class CTeam
{
    private:
        string m_name;  // 集训队名称
        vector<T> m_team;   // 集训队成员容器 
    public:
        void join(const T& obj);      // 加入集训队
        void quit(const T& obj);      // 退出集训队 
        CTeam(string name):m_name(name){}
};
// 班级 
template <class T>
class CClass
{
    private:
        string m_name;  // 班级名称 
        vector<T> m_class;  // 班级中的学生容器 

    public:
        CClass(string name):m_name(name){}
        void add(const T& obj);     // 向班级添加学生, 托管学生对象 
        void remove(const T& obj);  // 将学生从班级中移除, 解除学生对象托管 
        void print();                       // 输出班级所有学生 
}; 
// 学生
class CStudent
{public:
    
        string m_name;  // 名字 
        string m_no;    // 学号 
    
        CStudent(string name, string no):m_name(name), m_no(no){}
        friend ostream & operator << (ostream &out, const CStudent &obj);
        friend istream & operator >> (istream &in, CStudent &obj); 
};
template <class T> 
void CTeam<T>::join(const T& obj){
	m_team.push_back(obj);
}
template <class T> 
void CTeam<T>::quit(const T& obj){
	// m_team.erase(obj);
	int tail=0;
	for(int i=0;i<m_team.size();i++){
		if(m_team[i]==NULL)
			continue;
		if(m_team[i]==obj)
			m_team[i].reset();
	}
}
template <class T> 
void CClass<T>::add(const T& obj){
	m_class.push_back(obj);
}
template <class T> 
void CClass<T>::remove(const T& obj){
	int tail=0;
	for(int i=0;i<m_class.size();i++){
		if(m_class[i]==NULL)
			continue;
		if(m_class[i]==obj->m_no)
			m_class[i].reset();
	}

}
ostream & operator << (ostream &out, const CStudent &obj){
	cout<<obj.m_name<<' '<<obj.m_no<<endl;
	// cout<<"dadasd"<<endl;
	return out;
}
template <class T> 
void CClass<T>::print(){
	for(int i=0;i<m_class.size();i++){
		cout<<*m_class[i];
		// cout<<"dadas"<<endl;
	}
}

istream & operator >> (istream &in, CStudent &obj){
	in>>obj.m_name>>obj.m_no;
	return in;
}
/* 你的答案将被放置在这里 */
int main ()
{
    CStudent s1("Li", "001"), s2("Song", "002"), s3("Zhang", "003");
    CClass<shared_ptr<CStudent>> class1("ComputerOne");
    auto ps1 = make_shared<CStudent>(s1);
    auto ps2 = make_shared<CStudent>(s2);
    auto ps3 = make_shared<CStudent>(s3);
    class1.add(ps1);
    class1.add(ps2);
    class1.add(ps3);
    class1.print();

    CTeam<shared_ptr<CStudent>> team1("ACM");
    team1.join(ps1);
    team1.join(ps2);
    CTeam<shared_ptr<CStudent>> team2("PTA");
    team2.join(ps1);
    team2.join(ps3);
    cout << ps1.use_count() << " " << ps2.use_count() << " " << ps3.use_count() << endl;
    {
        shared_ptr<CStudent> pst = ps1;
        cout << ps1.use_count() << " " << ps2.use_count() << " " << ps3.use_count() << endl;
    }

    team1.quit(ps1);
    team1.quit(ps2);
    cout << ps1.use_count() << " " << ps2.use_count() << " " << ps3.use_count() << endl;

    // 以下是不好的示例 
    {
        /* CStudent *sx1 = new CStudent("Wrong", "000");
        shared_ptr<CStudent> px1 = shared_ptr<CStudent>(sx1);
        shared_ptr<CStudent> px2 = shared_ptr<CStudent>(sx1);*/
    }
}