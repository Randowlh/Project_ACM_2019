#include<bits/stdc++.h>
using namespace std;
int main(){
    // freopen("in.txt","r",stdin);
    int a,b,k;
    cin>>a>>b>>k;
    if(k==0){
        vector<int> ans;
        while(b--)
            ans.push_back(1);
        while(a--)
            ans.push_back(0);
        cout<<"YES"<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];cout<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];cout<<endl;
        return 0;
    }
    b-=2;
    if(b<0||a==0){
        cout<<"NO"<<endl;
        return 0;
    }
    if(a+b>=k){
        cout<<"YES"<<endl;
        vector<int> ans1,ans2;
        int ta=a,tb=b;
        for(int i=1;i<k;i++){
            if(tb){
                ans1.push_back(1);
                tb--;
            }else{
                ans1.push_back(0);
                ta--;
            }
        }
        ans1.push_back(3);
            ta--;
        while(tb--)
            ans1.push_back(1);
        while(ta--)
            ans1.push_back(0);
        cout<<11;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]==3)
                cout<<0;
            else
                cout<<ans1[i];
        }
        cout<<endl;
        cout<<10;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]==3){
                cout<<1;
            }else cout<<ans1[i];
        }
        cout<<endl;
        
    }else cout<<"NO"<<endl;
}