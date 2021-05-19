

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