// lol Method
bool cyclic(int node,int parent,vector<vector<int> > &l,vector<int> &vis){
    vis[node]=1;
    for(auto child:l[node]){
        if(!vis[child]){
            if(cyclic(child,node,l,vis)) return true;
        }else{
            if(child!=parent) return true;  
        }
    }
    return false;
}

// if (edges>=nodes)

void dfs(int i,int &edges,int &nodes,vector<int> &vis,vector<vector<int> > &l){
    vis[i]=1,nodes++;
    edges+=l[i].size();
    for(auto j:l[i]){
        if(!vis[j])
            dfs(j,edges,nodes,vis,l);
    }
}
bool cyclic(vector<vector<int> > &l,int n){
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int edges=0,nodes=0;
            dfs(i,edges,nodes,vis,l);
            if(edges/2>=nodes)
                return true;
        }
    }
    return false;
}
