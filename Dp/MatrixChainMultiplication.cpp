#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> &a){
    int n=a.size()-1;
    vector<vector<int> > dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if((j-i)==1){
                dp[i][j]=a[i]*a[j]*a[j+1];
            }else{
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
                }
            }
        }
    }
    return dp[0][n-1];
}

signed main(){

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<mcm(a)<<endl;

    return 0;
}
/*
    (ABC)D = (AB)(CD) = A(BCD) = ....
    (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
    A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.
*/
