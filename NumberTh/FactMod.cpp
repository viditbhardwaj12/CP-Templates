// We consider the case when 'm' is relatively small & n is a large value
// T=O(log{base(m)}(n))

int fact_mod(int n,int m){
    vector<int> f(m);
    f[0]=1;
    for(int i=1;i<m;i++) f[i]=(f[i-1]*i)%m;
    int ans=1;
    while(n>1){
        if((n/m)%2) ans=m-ans;
        ans=ans*f[n%m]%m,n/=m;
    }
    return ans; 
}
