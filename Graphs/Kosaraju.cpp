// Dir Graph
// STRONGLY CONNECTED COMPONENT is a maximal subset of vertices C such that any two vertices of this subset are reachable from each other
// T=O(V+E)

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
void dfs(int prnt,vector<int> &comp,vector<int> &vis,vector<vector<int> > &rev_l){
    vis[prnt]=1,comp.pb(prnt);
    for(auto ch:rev_l[prnt]){
        if(!vis[ch]){
            dfs(ch,comp,vis,rev_l);
        }
    }
}
vector<vector<int> > kosaraju(int n,vector<vector<int> > &l,vector<vector<int> >  &rev_l){
    vector<int> path=topsort(l,n);

    vector<int> vis(n+1,0);
    vector<vector<int> > scc;
    for(int i=0;i<sz(path);i++){
        if(!vis[path[i]]){
            vector<int> comp;
            dfs(path[i],comp,vis,rev_l);
            scc.pb(comp);
        }
    }
    return scc;
}
