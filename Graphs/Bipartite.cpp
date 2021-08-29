void dfs(int node,int parent,int clr,map<int,int> &color,int *odd_cycle,vector<int> &vis,vector<vector<int> > &l){
    vis[node]=1;
    color[node]=clr;
    for(auto child:l[node]){
        if(!vis[child]){
            dfs(child,node,1-clr,color,odd_cycle,vis,l);
        }else{
            if(child!=parent && color[child]==clr) *odd_cycle=1;
        }
    }
}
void bipartite(vector<vector<int> > &l,int n){
    map<int,int> color;
    int odd_cycle=0;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0,1,color,&odd_cycle,vis,l);
        }
    }

    if(odd_cycle){
        cout<<"Odd Cycle Detected";
    }else{
        for(int i=1;i<=n;i++){
            cout<<color[i]+1<<" ";
        }
    }
}
