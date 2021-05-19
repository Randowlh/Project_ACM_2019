#include <bits/stdc++.h>
using namespace std;
//向前声明类模板和函数模板
template <class T, class ContT >
class CQueue;
template <class T, class ContT >
void Dump (ostream &os, CQueue<T, ContT> &rhs); //声明倒出队列内容函数模板

template <class T, class ContT = deque<T>>
class CQueue
{
private :
    ContT m_cont;
    string label;    // label of the container
public :
    typedef T   valueType;           //类型成员举例，表示队列内元素类型
    inline void push (const T & x);     //入队列
    inline bool empty () const;  //判队列空
    inline const T& top () const;    //取队列顶元素
    inline void pop ();             //出队列
    friend void Dump<T, ContT> (ostream &os, CQueue &rhs); //模板函数特定实例作为友元
};
template <class T, class ContT>inline void  CQueue<T,ContT>::push(const T& x){m_cont.push_back(x);}
template <class T, class ContT> inline bool CQueue<T,ContT>::empty () const{return m_cont.empty();}
template <class T, class ContT> inline const T& CQueue<T,ContT>::top () const{return m_cont.front();}
template <class T, class ContT>  inline void CQueue<T,ContT>::pop (){m_cont.pop_front();}

/* 请在这里填写答案：template <class T, class ContT>Cqueue的完整定义 */



//先进先出显示队列内容函数模板定义
template <class T, class ContT>
void Dump (ostream &os, CQueue<T, ContT> &S)
{
    while (!S.m_cont.empty())//相当于!S.empty (),主要用于测试友元
    {
        os << S.top () << " ";
        S.pop ();
    }
    os << endl;
}

//输入函数模板
template <class T, class ContT = deque<T>>
void    Input (int n)
{
    CQueue<T, ContT> S1;
    int i;
    T    x;

    for (i = 0; i < n; i++)
    {
        //执行输入每条指令
        cin >> x;
        S1.push (x);
    }

    CQueue<T, ContT>  S2 (S1), S3; //拷贝构造S2，无参构造S3
    S3 = S2; //S1复制赋值给S3
    CQueue<T, ContT>  S4 (std::move (S2)), S5; //移动构造S4，无参构造S6
    S5 = std::move (S4);//S3移动赋值给S5

    // 顺序显式队列内容
    Dump (cout, S1);
    Dump (cout, S3);
    Dump (cout, S5);
}



// 定义一个苹果类 
class Apple
{
    public:
        Apple():product(""), weight(0.0), price(0.0){}
        Apple(string product, double weight, double price )
        {
            this->weight = weight;
            this->product = product;
            this->price = price;
        }
        friend istream& operator >> (istream &in, Apple &obj);
        friend ostream& operator << (ostream &out, const Apple &obj); 
    private:
        string product;
        double weight, price;
}; 

// Apple的输入重载 
istream & operator >> (istream &in, Apple &obj)
{
    in >> obj.product >> obj.weight >> obj.price;
    return in;
}

// Apple的输出重载
ostream & operator << (ostream &out, const Apple &obj)
{
    out << obj.product << " " << obj.weight << " " << obj.price;
    return out;
}

int main ()
{
    Input<Apple>(2);
}