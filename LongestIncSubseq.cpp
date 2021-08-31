#include<bits/stdc++.h>
using namespace std;

#define pb               push_back
#define lb               lower_bound
#define sz(x)            (int)(x.size()) 
#define all(v)           (v).begin(),(v).end()
 
/*__________________________________________________________*/
 
signed main(){
    
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
 
    vector<int> v;
    for(int i=0;i<n;i++){
        int j=lb(all(v),a[i])-v.begin();
        if(j<sz(v)) v[j]=a[i];
        else v.pb(a[i]);
    }
 
    cout<<sz(v);
 
    return 0;
}
