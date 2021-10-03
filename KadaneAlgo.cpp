#include<bits/stdc++.h>
using namespace std;

#define int              long long int

const int inf=(1e18);

signed main(){

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int curr_max=0,ans=-inf;
    for(int i=0;i<n;i++){
        curr_max=max(a[i],curr_max+a[i]);
        ans=max(ans,curr_max);
    }

    cout<<ans;

    return 0;
}
