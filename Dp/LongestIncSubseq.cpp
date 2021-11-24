int lis(vector<int> &a,int n){
    vector<int> v;
    for(int i=0;i<n;i++){
        int j=lb(all(v),a[i])-v.begin();
        if(j<sz(v)) v[j]=a[i];
        else v.pb(a[i]);
    }
    return sz(v);
}
