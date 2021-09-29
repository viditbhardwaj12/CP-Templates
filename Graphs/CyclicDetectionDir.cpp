// This will work for both directed and undirected graph

vector<vector<ll>>a(1e5);
vector<ll>vis(1e5+10,0);

bool dfs(ll v) {
    vis[v]=1;
    for (ll u:a[v]){
        if (vis[u]==0){
            // parent[u] = v; for finding the cycle
            if(dfs(u))
                return true;
        } 
        else if(vis[u]==1){
            // cycle_end = v , cycle_start = u;
            return true;
        }
    }
    vis[v]=2;
    return false;
}

void solve(){
    for(int i=1;i<=n;i++){
        if(vis[i]==0 and dfs(i)){
            // cycle detected
            ok=1; break;
        }
    }
}
