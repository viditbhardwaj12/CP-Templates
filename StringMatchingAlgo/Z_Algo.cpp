// Z[i]=Length of longest subtring starting at ith indx which also is prefix of string
// a b a a b a b a b a a b a b a
// 0 0 1 3 0 3 0 8 0 1 3 0 3 0 1
// T=O(N)

vector<int> z_algo(string str){
    int n=sz(str);
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r) z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && str[z[i]]==str[i+z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l=i,r=(i+z[i]-1);
        }
    }
    return z;
}
