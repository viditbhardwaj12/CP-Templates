// works only on DAG(dir acyclic graph)
// gives permutation of vertices where there is an edge from p[i] to p[j] and i<j
// T:O(V+E) 

void dfs_top(int prnt,vector<int> &dag,vector<int> &vis,vector<vector<int> > &l){
    vis[prnt]=1;
    for(auto ch:l[prnt]){
        if(!vis[ch]){
            dfs_top(ch,dag,vis,l);
        }
    }
    dag.pb(prnt);
}
vector<int> topsort(vector<vector<int> > &l,int n){
    vector<int> dag;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs_top(i,dag,vis,l);
        }
    }
    reverse(all(dag));
    return dag;
}
