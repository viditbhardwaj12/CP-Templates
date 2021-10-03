// Dir or undir
// Gives the shortest path between each pair of vertices i and j.
// The graph may have negative weight edges, but no negative weight cycles.
// Undir graph cannot have any -ve wt edges,such edge forms already a -ve cycle as we can move back and forth along that edge.(Shortest path is undefined)
// T=O(n^3)

// if(dist[i][j]== inf) shortest path from 'i' to 'j' doesn't exists
// if(dist[i][j]== -ve) -ve wt cycle exists(detects -ve cycle)

// Line 32: if the graph has -ve wt edges,it is better to it in the following way,so that it does not perform transitions using paths that don't exist.

// Maintain p[][] for getting path.Recursively find path between i and p[i][j], p[i][j] and j.

// Remember nodes exists from 0 to (n-1)
vector<vector<int> > floyd_warshall(vector<vector<int> > &l,int n){
    vector<vector<int> > dist(n,vector<int>(n));
    for(int i=0;i<n;i++){
        fill(all(dist[i]),inf);
        dist[i][i]=0;
    }

    for(auto &e:l){
        int x=e[0],y=e[1],w=e[2];
        dist[x][y]=min(dist[x][y],w);
        dist[y][x]=min(dist[y][x],w);
    }

    for(int mid=0;mid<n;mid++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][mid]<inf && dist[mid][j]<inf){
                    dist[i][j]=min(dist[i][j],dist[i][mid]+dist[mid][j]);
                }
            }
        }
    }
    return dist;
}
