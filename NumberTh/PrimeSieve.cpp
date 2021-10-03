// T=O(nlog(log(n))) 
vector<int> sieve(int n){ 
    vector<int> p;
    bool prime[n+1];  
    mset(prime,true);     
    prime[0]=prime[1]=false;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i) prime[j]=false;
            p.pb(i);
        }
    }
    return p;
}
