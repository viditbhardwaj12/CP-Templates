bool dfs(int node,vector<int> &curr_path,vector<vector<int> > &l,vector<int> &vis){
    vis[node]=1;
    curr_path[node]=1;
    for(auto child:l[node]){
        if(!vis[child]){
            if(dfs(child,curr_path,l,vis)) return true;
        }else{
            if(curr_path[child]) return true;
        }
    }
    curr_path[node]=0;
    return false;        
}
bool cyclic(vector<vector<int> > &l,int n){
    vector<int> vis(n+1,0),curr_path(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(i,curr_path,l,vis))
            return true;
    }
    return false;
}
