int fact[N];
void get_fact(){
    fact[0]=1;
    for(int i=1;i<N;i++) 
        fact[i]=(fact[i-1]*i)%mod;
}

int pow(int a,int b,int m){
    int ans=1;
    while(b){
        if(b%2) ans=(ans*a)%m;
        b/=2,a=(a*a)%m;
    }
    return ans;
}
int inv_mod(int a,int m){return pow(a,m-2,m);}
int ncrMod(int n,int r,int m){
    if(n<r) return 0;
    return (fact[n]*inv_mod(fact[r],m)%m*inv_mod(fact[n-r],m)%m)%m;
}
