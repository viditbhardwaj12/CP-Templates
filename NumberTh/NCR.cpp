int ncr(int n,int r){
    int ans=1;
    for(int i=1;i<=r;i++)
        ans=(ans*(n+1-i))/i;
    return ans;
}
