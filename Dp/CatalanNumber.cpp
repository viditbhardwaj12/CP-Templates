// Count Number of Binary Search Trees with N Nodes Dynamic Programming - Catalan Numbers
int catalan(int n){
    vector<int> dp(n+1,0);
    dp[0]=1,dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    return dp[n];
}

int CatalanRec(int n,vector<int> &dp){
    if(n==0 || n==1){
        return dp[n]=1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=CatalanRec(n-i,dp)*CatalanRec(i-1,dp);
    }
    return dp[n]=ans;
}
