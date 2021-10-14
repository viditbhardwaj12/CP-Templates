// nlog(n)

// This will give count of all divisors till 'n'
vector<int> cnt_div(int n){
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            cnt[j]++;
        }
    }
    return cnt;
}

// This will give count of all prime divisors till 'n'

vector<int> cnt_prime_div(int n){
    vector<int> cnt(n+1,0),vis(n+1,0);
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            for(int j=i;j<=n;j+=i){
                cnt[j]++,vis[j]=1;
            }
        }
    }
    return cnt;
}
  
// This will give prime factorization of 'n'
// 0(sqrt(n)/log(n))
// count of prime numbers is from 1 to n => (n/log(n))
vector<int> prime_fact(int n){
    vector<int> p,unique_p;
    if(n%2==0){
        unique_p.pb(2);
        while(n%2==0){
            p.pb(2),n/=2;
        }
    }

    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            unique_p.pb(i);
            while(n%i==0){
                n/=i,p.pb(i);
            }
        }
    }
    if(n>1) p.pb(n),unique_p.pb(n);
//     return unique_p;
    return p;
}
