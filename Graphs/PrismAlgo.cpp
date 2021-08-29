int prism_algo(vector<vector<pii> > &l,int n){
    vector<int> vis(n+1,0);
    int ans=0;
    min_pq q;
    q.push({0,1});
    while(!q.empty()){
        int parent=q.top().ss,wt=q.top().ff;
        q.pop();

        if(vis[parent]) continue;
        vis[parent]=1,ans+=wt;
        for(auto child:l[parent]){
            if(!vis[child.ss]){
                q.push(child);
            }
        }
    }

    return ans;
}
