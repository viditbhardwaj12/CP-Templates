vector<int> divisors(int n){
    vector<int> d;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i!=n/i) d.pb(i),d.pb(n/i);
            else d.pb(i);
        }
    }
    sort(all(d));
    return d;
}
