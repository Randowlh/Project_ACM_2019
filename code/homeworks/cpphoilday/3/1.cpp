#include <bits/stdc++.h>
using namespace std;
class link_list
{
private:
    struct node
    {
        int v;
        node *next = NULL;
    };
    node *head = NULL;

public:
    bool empty()
    {
        return head == NULL;
    }
    void insert(int v)
    {
        node *tmp=new node;
        tmp->v=v;
        if(head==NULL||head->v>v){    
            tmp->next=head;
            head=tmp;
            return;
        }
        node **now=&head;
        while(((*now)->next)!=NULL&&(*now)->next->v<=v)    
            now=&((*now)->next);
        tmp->next=((*now)->next);
        (*now)->next=tmp;
    }
    int top()
    {
        return head->v;
    }
    void pop()
    {
        node *t;
        t = head;
        head = head->next;
        delete t;
        return;
    }
    void clear()
    {
        while (!empty())
            pop();
    }
    vector<int> bianli()
    {
        vector<int> ans;
        node *now = head;
        while (now != NULL)
        {
            ans.push_back(now->v);
            now = now->next;
        }
        return ans;
    }
} ou, ji;
int main()
{
    int t;
    while (cin >> t)
    {
        if (t == 0)
            break;
        if (t & 1)
        {
            ji.insert(t);
        }
        else
        {
            ou.insert(t);
        }
    }
    vector<int> a = ji.bianli();
    if (!a.empty())
    {
        for (int i = 0; i < (int)a.size() - 1; i++)
        {
            cout << a[i] << "->";
        }
        cout << *(a.end() - 1) << endl;
    }
    a = ou.bianli();
    if (!a.empty())
    {
        for (int i = 0; i < (int)a.size() - 1; i++)
        {
            cout << a[i] << "->";
        }
        cout << *(a.end() - 1) << endl;
    }
    while (!ou.empty())
    {
        ji.insert(ou.top());
        ou.pop();
    }
    a = ji.bianli();
    for (int i = 0; i < (int)a.size() - 1; i++)
    {
        cout << a[i] << "->";
    }
    cout << *(a.end() - 1) << endl;
    ji.clear();
    return 0;
}