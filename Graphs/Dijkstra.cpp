// conditn:
// Directed or undirected weighted graph & The weights of all edges are non-negative.
// Finds the lengths of the shortest paths from a src vertix to all other vertices.
// T=O(V+E*log(V)).
    
void dijkstra(int src,vector<vector<pii> > &l,int *dist,int n){
    for(int i=1;i<=n;i++) dist[i]=inf;

    set<pii> s;
    dist[src]=0,s.insert({0,src});
    while(!s.empty()){
        int parent=(*(s.begin())).ss;
        int p_dist=(*(s.begin())).ff;
        s.erase(s.begin());

        for(auto nbr:l[parent]){
            int child=nbr.ff,wt=nbr.ss;
            if(dist[child]>p_dist+wt){
                auto it=s.find({dist[child],child});
                if(it!=s.end()) s.erase(it);
                dist[child]=(p_dist+wt);
                s.insert({dist[child],child});
            }
        }
    }
}
