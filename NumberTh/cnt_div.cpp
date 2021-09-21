// This will give count of all divisors till 'n'
// nlog(n)

vector<int> cnt_div(int n){
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            cnt[j]++;
        }
    }
    return cnt;
}
