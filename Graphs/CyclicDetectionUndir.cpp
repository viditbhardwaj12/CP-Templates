bool dfs(int node,int parent,vector<vector<int> > &l,vector<int> vis){
    vis[node]=1;
    for(auto child:l[node]){
        if(!vis[child]){
            if(dfs(child,node,l,vis)) return true;
        }else{
            if(child!=parent) return true;  
        }
    }
    return false;
}
