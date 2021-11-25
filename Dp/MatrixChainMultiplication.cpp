#include<bits/stdc++.h>
using namespace std;

#define ff               first
#define ss               second
#define endl             "\n"
#define pb               push_back
#define popb             pop_back
#define int              long long int
#define sz(x)            (int)(x.size()) 
#define mset(a,b)        memset(a,b,sizeof(a))
#define all(v)           (v).begin(),(v).end()
#define SPD_emergency    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC               int TT; cin>>TT; while(TT--)

const int N=(2e5+10),mod=(1e9+7),inf=(1e18);

int mcm(vector<int> &a){
    int n=sz(a)-1;
    vector<vector<int> > dp(n,vector<int>(n));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i>=j){
                dp[i][j]=0;
            }else if((j-i)==1){
                dp[i][j]=a[i]*a[j]*a[j+1];
            }else{
                dp[i][j]=inf;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
                }
            }
        }
    }
    return dp[0][n-1];
}

signed main(){
SPD_emergency

TC{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<mcm(a)<<endl;
}

    return 0;
}
