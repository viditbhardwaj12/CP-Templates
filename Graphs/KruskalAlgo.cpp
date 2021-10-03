#include<bits/stdc++.h>
using namespace std;

#define pb     push_back
#define all(v) (v).begin(),(v).end()

class DSU{
public:
    int n,components;
    vector<int> rank,parent;
    DSU(int n){
        components=n;
        rank.resize(n),fill(all(rank),1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int get(int node){
        if(parent[node]==node) return node;
        return parent[node]=get(parent[node]);
    }
    void unite(int u, int v) {
        int super_u=get(u),super_v=get(v);
        if(super_u==super_v) return;

        if(rank[super_u]>rank[super_v]){
            swap(super_v,super_u);
        }

        parent[super_u]=super_v;
        rank[super_v]+=rank[super_u];
        rank[super_u]=0;
        components--;       
    }
};

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int> > edges;
    for(int i=0;i<m;i++){
        int x,y,wt; cin>>x>>y>>wt;
        x--,y--;
        edges.pb({wt,x,y});
    }

    sort(all(edges));

    DSU u(n);
    int ans=0;
    for(auto x:edges){
        int from=x[1],to=x[2],wt=x[0];
        if(u.get(from)!=u.get(to)){     
            u.unite(from,to);
            ans+=wt;
        }
    }

    cout<<ans;
    
    return 0;
}
