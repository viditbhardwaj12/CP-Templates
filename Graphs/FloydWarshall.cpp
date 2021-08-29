// By : ViditBhardwaj
#include<bits/stdc++.h>
using namespace std;
 
#define endl             "\n"
#define int              long long int
#define all(v)           (v).begin(),(v).end()
#define SPD_emergency    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const int N=(5e2+10),inf=(1e18);

int n,m;
vector<vector<int> > dist(N,vector<int>(N));
void floyd_warshall(){
    for(int mid=0;mid<n;mid++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][mid]+dist[mid][j]);
            }
        }
    }
}
 
signed main(){
SPD_emergency
    
    int q;
    cin>>n>>m>>q;
    for(int i=0;i<=n;i++){
        fill(all(dist[i]),inf);
        dist[i][i]=0;
    }
 
    for(int i=0;i<m;i++){
        int x,y,wt; cin>>x>>y>>wt;
        x--,y--;
        dist[x][y]=min(dist[x][y],wt);
        dist[y][x]=min(dist[y][x],wt);
    }
 
    floyd_warshall();
 
    while(q--){
        int x,y; cin>>x>>y;
        x--,y--;
        if(dist[x][y]==inf) cout<<"-1"<<endl;
        else cout<<dist[x][y]<<endl;
    }
 
    return 0;
}
/*
 
*/
