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
