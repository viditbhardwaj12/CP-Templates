void dfs_top(int prnt,vector<int> &path,vector<int> &vis,vector<vector<int> > &l){
    vis[prnt]=1;
    for(auto ch:l[prnt]){
        if(!vis[ch]){
            dfs_top(ch,path,vis,l);
        }
    }
    path.pb(prnt);
}
vector<int> topsort(vector<vector<int> > &l,int n){
    vector<int> path;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs_top(i,path,vis,l);
        }
    }
    reverse(all(path));
    return path;
}
