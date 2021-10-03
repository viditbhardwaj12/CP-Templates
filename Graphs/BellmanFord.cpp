// Single source shortest path with negative weight edges
// Unlike the Dijkstra , this algo can also be applied to graphs containing -ve weight edges.
// However, if the graph contains a -ve cycle, then, clearly, the shortest path to some vertices may not exist(-inf).
// This algo not only detects -ve wt cycle but help us get vertices of -ve wt cycle by retriving path.
// T=O(V*E)

// Remember the last vertex 'node' for which there was a relaxation in nth phase. 
// This vertex will either lie in a negative weight cycle, or is reachable from it. 
// To get the vertices that are guaranteed to lie in a -ve cycle,starting from the vertex 'node',
// pass through to the predecessors n times. Hence we will get the vertex y, 
// namely the vertex in the cycle earliest reachable from source.

void get_cycle(vector<int> &parent,int node){
    int n=sz(parent);
    for(int i=1;i<=n;i++)
        node=parent[node];

    int curr=node;
    vector<int> path;
    while(1){
        path.pb(curr);
        if(curr==node && sz(path)>1) break;
        curr=parent[curr];
    }

    reverse(all(path));
    for(auto p:path) cout<<p<<" ";
}

vector<int> bellman_ford(vector<vector<pii> > &l,int n){
    int neg_cycle=0,relax=n,node=0;
    vector<int> dist(n+1),parent(n+1);
    fill(all(dist),inf);
    dist[1]=0;
    while(relax--){
        neg_cycle=0;
        for(int p=1;p<=n;p++){
            for(auto ch:l[p]){
                int from=(p),to=ch.ff,wt=ch.ss;
                if(dist[to]>dist[from]+wt){
                    dist[to]=dist[from]+wt;
                    neg_cycle=1;
                    node=to,parent[to]=from;
                } 
            }
        }
    }

    if(neg_cycle){
        get_cycle(parent,node);
        exit(0);
    }
    return dist;
}
