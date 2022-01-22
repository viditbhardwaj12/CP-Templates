// A bipartite graph is a graph whose vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets 
// (i.e. there are no edges which connect vertices from the same set).
// condition->Undir Graph & there should be no odd sycle present
// The min(number of black, number of white) nodes is <= n / 2.
// T=O(V+E)

void dfs(int parent,int clr,vector<int> &color,int &odd_cycle,vector<int> &vis,vector<vector<int> > &l){
    vis[parent]=1,color[parent]=clr;
    for(auto child:l[parent]){
        if(!vis[child]){
            dfs(child,1-clr,color,odd_cycle,vis,l);
        }else{
            if(color[child]==color[parent]) odd_cycle=1;
        }
    }
}
vector<int> bipartite(vector<vector<int> > &l,int n){
    int odd_cycle=0;
    vector<int> vis(n+1,0),color(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0,color,odd_cycle,vis,l);
        }
    }

    if(odd_cycle)
        exit(0);
    return color;
}
