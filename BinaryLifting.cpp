class BinaryLifting{
public:
    int n;
    int maxLevel;
    vector<vector<int> > parent;
    BinaryLifting(int nodes,vector<vector<int> > &l,int root){
        n=nodes;
        maxLevel=(int)log2(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i].resize(maxLevel+1);
            fill(all(parent[i]),-1);
        }

        fillParent(l,root);
    }
    void fillParent(vector<vector<int> > &l,int root){
        vector<int> vis(n,0);
        dfs(l,root,vis);

        for(int i=1;i<=maxLevel;i++){
            for(int node=0;node<n;node++){
                int v=parent[node][i-1];
                if(v!=-1){
                    parent[node][i]=parent[v][i-1];
                }
            }
        }    
    }
    void dfs(vector<vector<int> > &l,int node,vector<int> &vis){
        vis[node]=1;
        for(auto ch:l[node]){
            if(!vis[ch]){
                parent[ch][0]=node;
                dfs(l,ch,vis);
            }
        }
    }
    int getKthLCA(int node,int k){
        while(k>0){
            int x=log2(k);
            node=parent[node][x];
            if(node==-1) break;
            k-=_pow(2,x);
        }
        return node;
    }
};

class LCA{
public:
    int n;
    vector<int> level;
    LCA(int nodes,vector<vector<int> > &l,int root){
        n=nodes;
        level.resize(n);

        dfs(root,l,-1);   
    }
    void dfs(int node,vector<vector<int> > &l,int par){
        for(auto ch:l[node]){
            if(ch!=par){
                level[ch]=level[node]+1;
                dfs(ch,l,node);
            }
        }
    }
    int getLCA(int u,int v,BinaryLifting &BL){
        if(level[u]>level[v]) swap(u,v);
        v=BL.getKthLCA(v,level[v]-level[u]);
        if(u==v) return u;

        int ans=-1;
        for(int i=BL.maxLevel;i>=0;i--){
            int p1=BL.parent[u][i];
            int p2=BL.parent[v][i];
            if(p1==-1 || p2==-1) continue;
            if(p1!=p2) break;
            ans=p1;
        }

        return ans;
    }
};
