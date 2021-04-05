#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
#define chuu CLOCKS_PER_SEC
int heap[110000];
int heap_size;
int n;
vector<int> date,tt;
void max_heapify(int i)
{
    int largest = i;
    if (i * 2 <= heap_size && heap[i * 2] > heap[i])
        largest = i * 2;
    if (i * 2 + 1 <= heap_size && heap[i * 2 + 1] > heap[largest])
        largest = i * 2 + 1;
    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        max_heapify(largest);
    }
}
void build_max_heap()
{
    heap_size = n;
    for (int i = heap_size / 2; i >= 1; i--)
        max_heapify(i);
}
void heap_sort()
{
    build_max_heap();
    for (int i = n; i > 1; i--)
    {
        swap(heap[1], heap[i]);
        heap_size--;
        max_heapify(1);
    }
}
 
void insert_sort()
{
    for (int i = 1; i < date.size(); i++)
    {
        int k = date[i];
        int j = i - 1;
        while (j >= 0 && date[j] > k)
        {
            date[j + 1] = date[j];
            j--;
        }
        date[j + 1] = k;
    }
    return;
}
 
void merge(int left, int mid, int right)
{
    int l1 = mid - left + 1;
    int l2 = right - mid;
    vector<int> l, r;
    for (int i = 1; i <= l1; i++)
        l.push_back(date[left + i - 1]);
    for (int i = 1; i <= l2; i++)
        r.push_back(date[mid + i]);
    l.push_back(inf);
    r.push_back(inf);
    int i = 0;
    int j = 0;
    for (int k = left; k <= right; k++)
    {
        if (l[i] <= r[j])
        {
            date[k] = l[i];
            i++;
        }
        else
        {
            date[k] = r[j];
            j++;
        }
    }
    return;
}
void merge_sort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) >> 1;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}
 
int get_max()
{
    int ma = date[0];
    for (int i = 1; i < date.size(); i++)
        ma = max(date[i], ma);
    int t = 1;
    while (ma > 0)
    {
        t++;
        ma /= 10;
    }
    return t;
}
void radix_sort()
{
    int d = get_max();
    vector<int> tmp[10];
    int chu = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < date.size(); j++)
            tmp[date[j] / chu % 10].push_back(date[j]);
        date.clear();
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < tmp[j].size(); k++)
                date.push_back(tmp[j][k]);
        for (int j = 0; j < 10; j++)
            tmp[j].clear();
        chu *= 10;
    }
    return;
}
int partition(int left, int right)
{
    int x = date[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++)
        if (date[j] <= x)
        {
            i++;
            swap(date[i], date[j]);
        }
    swap(date[i + 1], date[right]);
    return i + 1;
}
void quicksort(int left, int right)
{
    if (left < right)
    {
        int mid = partition(left, right);
        quicksort(left, mid - 1);
        quicksort(mid + 1, right);
    }
}
vector<int> out;
vector<int> C;
void count_sort()
{
    for (int i = 0; i < C.size(); i++)
        C[i] = 0;
    for (int i = 0; i < date.size(); i++)
        C[date[i]]++;   
    for (int i = 1; i < C.size(); i++)
        C[i] += C[i - 1];
    out.resize(date.size() + 1);
    for (int i = date.size() - 1; i >= 0; i--)
    {
        out[C[date[i]]] = date[i];
        C[date[i]]--;
    }
    return;
}
void bubble_sort(){
    for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n-1; j++)
		{
			if (date[i]>date[j])
				swap(date[j],date[i]);
		}
	}
}
mt19937 rnd(233);
vector<int> aa;
signed main(){
    system("chcp 65001");
    cout<<"请输入数据范围"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
        aa.push_back(rnd()%100000);
    for(int i=1;i<=n;i++)
        heap[i]=aa[i-1];
    clock_t st=clock();
    clock_t ed;
    heap_sort();
    ed=clock();
    cout<<"heap_sort:"<<(ed-st)<<endl;
    date=aa;
    st=clock();
    insert_sort();
    ed=clock();
    cout<<"insert_sort:"<<(ed-st)<<endl;
    date=aa;
    st=clock();
    merge_sort(0,n-1);
    ed=clock();
    cout<<"merge_sort:"<<(ed-st)<<endl;
    date=aa;
    st=clock();
    radix_sort();
    ed=clock();
    cout<<"radix_sort:"<<(ed-st)<<endl;
    date=aa;
    st=clock();
    quicksort(0,n-1);
    ed=clock();
    cout<<"quick_sort:"<<(ed-st)<<endl;
    st=clock();
    bubble_sort();
    ed=clock();
    cout<<"bubble_sort"<<(ed-st)<<endl;
}