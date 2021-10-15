mob[1] = 1
mob[i] = 0      [if 'i' is a square of prime factor]
mob[i] = (-1)^k ['i' is product of 'k' distinct primes]

vector<int> least_prime_fact(int n){
    vector<int> lpf(n,0);
    for(int i=2;i<n;i++){
        if(lpf[i]) continue;
        for(int j=i;j<n;j+=i){
            if(!lpf[j]) lpf[j]=(i);
        }
    }
    return lpf;
}
vector<int> mobius(int n){
    vector<int> lpf=least_prime_fact(n+1);
    vector<int> mob(n+1,0);
    mob[1]=1;
    for(int i=2;i<=n;i++){
        if(lpf[i/lpf[i]]==lpf[i]) mob[i]=0;
        else mob[i]=(-1)*(mob[i/lpf[i]]);
    }
    return mob;
}
