vector<int> factors(int n){
    vector<int> f;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i!=n/i) f.pb(i),f.pb(n/i);
            else f.pb(i);
        }
    }
    sort(all(f));
    return f;
}
