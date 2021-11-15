// Max Subarray Sum
int kadaneAlgo(vector<int> &a){
    int curr_max=0,ans=-inf,n=sz(a);
    for(int i=0;i<n;i++){
        curr_max=max(a[i],curr_max+a[i]);
        ans=max(ans,curr_max);
    }
    return ans;
}
