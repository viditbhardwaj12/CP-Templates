// Max Subarray Sum
int kadaneAlgo(vector<int> &a){
    int curr_max=a[0],ans=a[0];
    for(int i=1;i<a.size();i++){
        curr_max=max(a[i],curr_max+a[i]);
        ans=max(ans,curr_max);
    }
    return ans;
}
