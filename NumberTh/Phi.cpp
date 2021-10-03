// EULER'S TOTIENT FUNCTION
// T=sqrt(n)

int phi(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            ans-=(ans/i);
        }
    }
    if(n>1) ans-=(ans/n);
    return ans;
}

// T=O(nlog(log(n)))
    
vector<int> phi_1_n(int n){
    vector<int> phi(n+1);
    phi[0]=0,phi[1]=1;
    for(int i=2;i<=n;i++) phi[i]=i;

    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i) phi[j]-=(phi[j]/i);
        }
    }
    return phi;
}
