#include<bits/stdc++.h>
using namespace std;
//向前声明类模板和函数模板
template <class T>
class CQueue;
template <class T>
void Dump (ostream &os, CQueue<T> &rhs); //先进先出显示队列内容函数模板定义

template <class T>
class CQueue
{
    struct Node
    {
        T    data;
        Node *next;
    };
private :
    string label;    // label of the queue
    Node *m_sp;     // pointer to head
    Node *m_end;    // pointer to tail

public :
    CQueue(string s1) : m_sp(nullptr), label(s1)     //构造函数
    {
    }
    CQueue (const CQueue &rhs); //拷贝构造函数
    CQueue (CQueue &&rhs);      //移动构造
    CQueue & operator = (const CQueue &rhs);//赋值运算符重载
    CQueue & operator = (CQueue &&rhs);//移动赋值

    ~CQueue ();                 //析构函数
    inline void push (const T & x);     //入队列
    inline bool empty () const;  //判空
    inline const T& top () const;    //取队列首元素
    inline void pop ();             //出队列 
    friend void Dump<T> (ostream &os, CQueue &rhs); //模板函数特定实例作为友元
};

/* 请在这里填写答案：Template <class T> Cqueue的完整定义 */
template <class T> 
inline const T& CQueue<T>::top()const{
    return m_sp->data;
}
template <class T> 
 inline bool CQueue<T>::empty () const{
      if(m_sp==NULL)
         return true;
      return false;
   } 
   template <class T> 
   inline void CQueue<T>::push (const T & x){
      if(empty()){
         Node* tmp=new Node;
         tmp->data=x;
         tmp->next=NULL;
         m_sp=tmp;
         m_end=tmp;
         return;
      }
      Node* tmp=new Node;
      tmp->data=x;
      tmp->next=NULL;
      m_end->next=tmp;
      m_end=tmp;
   }     //入队;
     //判空
     template <class T> 
     inline void CQueue<T>::pop (){ 
        if(m_end==m_sp){
           Node *tmp=m_end;
           delete tmp;
           m_end=m_sp=NULL;
           return;
        }
          Node *tmp=m_sp;
          m_sp=m_sp->next;
          delete tmp;
     }
    template <class T> 
    CQueue<T>::CQueue (const CQueue &rhs){
        //  label=rhs.label;
         m_sp=NULL;
         m_end=NULL;
         Node* a=rhs.m_sp;
         while(a!=NULL){
            push(a->data);
            a=a->next;
         }
    } //拷贝构造函数
    template <class T> 
    CQueue<T>::CQueue (CQueue &&rhs){
    //    label=rhs.label;
         m_sp=rhs.m_sp;
         m_end=rhs.m_end;
         rhs.m_end=rhs.m_sp=NULL;
      return;
    }     //移动构造
    template <class T> 
    CQueue<T> & CQueue<T>::operator = (const CQueue &rhs){
        //  label=rhs.label;
         m_sp=NULL;
         m_end=NULL;
         Node* a=rhs.m_sp;
         while(a!=NULL){
            push(a->data);
            a=a->next;
         }
         return *this;
    }//赋值运算符重载
    template <class T> 
    CQueue<T> & CQueue<T>::operator = (CQueue &&rhs){
    //    label=rhs.label;
         m_sp=rhs.m_sp;
         m_end=rhs.m_end;
         rhs.m_end=rhs.m_sp=NULL;
      return *this;
    }//移动赋
    template <class T> 
    CQueue<T>::~CQueue (){
       while(!empty()){
          pop();
       }
    }  

// Dump<CQueue<Apple>>()显示队列中的所有苹果信息
template <class T>
void Dump (ostream &os, CQueue<T> &S)
{
    os << "Apples in " << S.label << ":"; 
    while (S.m_sp != nullptr) //相当于!S.empty (),主要用于测试友元
    {
        os << S.top () << " ";
        S.pop ();
    }
    os << endl;
}

// 输入函数模板
template  <class T>
void    Input (int n)
{
    CQueue<T> S1("S1");
    int i;
    T    x;

    for (i = 0; i < n; i++)
    {
        //执行输入每条指令
        cin >> x;
        S1.push (x);
    }

    CQueue<T>  S2 (S1), S3("S3"); //拷贝构造S2，无参构造S3
    S3 = S2; //S1复制赋值给S3
    CQueue<T>  S4 (std::move (S2)), S5("S5"); //移动构造S4，无参构造S6
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

// 主程序输入3个苹果信息
int main ()
{
    Input<Apple>(3);
}