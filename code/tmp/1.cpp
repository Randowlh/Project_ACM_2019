#include <bits/stdc++.h>
using namespace std;
template <class T>
class CMyVector
{
private :
    T    *m_pBuffer;     //存放元素缓冲区指针
    int  m_size, m_bufferSize; //存放元素个数，缓冲区大小
public:
    CMyVector () : m_pBuffer (nullptr), m_size (0), m_bufferSize (0) {}
    CMyVector (int n) : m_pBuffer (nullptr),m_size (n), m_bufferSize (n)
    {
        if  (m_bufferSize > 0)
            m_pBuffer = new T [m_bufferSize];
    }
    ~CMyVector ()
    {
        delete [] m_pBuffer;
    }
    CMyVector (const CMyVector &rhs);//复制构造
    CMyVector (CMyVector &&rhs);  //C++11 移动构造
    CMyVector& operator = (const CMyVector &rhs);//复制赋值
    CMyVector& operator = (CMyVector &&rhs);//C++ 11 移动赋值
    void push_back (const T &rhs);  //尾部添加元素
    T  & at (int i);     //at重载，下标越界时抛出异常
    T  & operator [] (int i); //下标运算符重载，为效率不检查下标越界
    int size () const;  //获得元素个数
};
class CException : public exception
{
    string m_errMsg;
public :
    CException (string errMsg, int i) : m_errMsg (errMsg)
    {
        stringstream stream; //字符串流
        stream << i;  //插入字符串流，整形输出成字符流
        string str;
        stream >> str; //从字符串流提取字符串，字符流成为字符串
        m_errMsg += str; //字符串拼接
    }
    const char * what () const noexcept
    {
        return m_errMsg.c_str ();
    }
};

template <typename T>
void printElements(CMyVector<T> &vect);
class Computer
{
    private:
        double m_price;
        string m_vendor;

    public:
        Computer():m_price(0.0), m_vendor(""){        }
        Computer(string vendor, double price):m_price(price), m_vendor(vendor){}
        friend ostream & operator << (ostream &out, const Computer &obj);
        friend istream & operator >> (istream &in, Computer &obj);
}; 
template <class T>
T& CMyVector<T>::at(int i){
	if(i>m_size)
		throw CException("invalid index:",i);
	else return m_pBuffer[i];
}
template <class T>
T  & CMyVector<T>::operator [] (int i){
	return m_pBuffer[i];
}
template <class T>
int   CMyVector<T>::size ()const{
	return m_size;
}
template <class T>
T  & CMyVector<T>::operator [] (int i){
	return m_pBuffer[i];
}
template <class T>
T  & CMyVector<T>::operator [] (int i){
	return m_pBuffer[i];
}
template <class T>
T  & CMyVector<T>::operator [] (int i){
	return m_pBuffer[i];
}

/* 请在这里填写答案 */

int main ()
{
    CMyVector<Computer> vect1(2);
    cin>>vect1[0];
    Computer t1("lenovo", 7800.0);
    vect1[1] = t1;
    printElements(vect1);
    // try put additional one
    try{
        Computer t2("Dell", 8000);
        vect1.push_back(t2);
        vect1.at(3);
    }
    catch (exception &ex)
    {
        cout << "exception:" << ex.what() << endl;
    }
    try{
        // copy constructor
        CMyVector<Computer> vect2 = vect1;
        vect2.push_back(Computer("Huashuo", 6000));
        cout << vect2.at(3) << endl;

        // copy assignment
        CMyVector<Computer> vect3(3);
        vect3 = vect2;
        printElements(vect3);
        // move constructor
        CMyVector<Computer> vect4 = std::move(vect2);
        printElements(vect4);

        // move assignment
        vect4.push_back(Computer("Apple", 10000));
        vect4 = std::move(vect3);
        printElements(vect3);
    }
    catch(exception &ex)
    {
        cout << "exception:" << ex.what() << endl;
    } 
}

