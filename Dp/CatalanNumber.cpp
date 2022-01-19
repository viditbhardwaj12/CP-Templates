// Count Number of Binary Search Trees with N Nodes - Catalan Numbers
// C0=1
// C1=1
// C2=C0*C1 + C1*C0 = 2
// C3=C0*C2 + C1*C1 + C2*C0 = 5
// C4=C0*C3 + C1*C2 + C2*C1 + C3*C0 = 14
// C5=C0*C4 + C1*C3 + C2*C2 + C3*C1 + C4*C0 = 42

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
