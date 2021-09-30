vector<int> dist(N);
void bellman_ford(vector<vector<pii> > &l,int n){
    int neg_cycle=0,relax=n-1,node=0;
    fill(all(dist),inf);
    dist[1]=0;
    while(relax--){
        neg_cycle=0;
        for(int i=1;i<=n;i++){
            for(auto x:l[i]){
                int from=(i),to=x.ff,wt=x.ss;
                if(dist[to]>dist[from]+wt){
                    dist[to]=dist[from]+wt;
                    neg_cycle=1,node=to;
                } 
            }
        }
    }

    if(neg_cycle){
        exit(0);   
    }
}
