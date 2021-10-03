// LONGEST MATCHING PREFIX-SUFFIX
// T=O(n)

vector<int> kmp(string str){
    int n=str.size();
    vector<int> lps(n,0);
    for(int i=1;i<n;i++){
        int j=lps[i-1];
        while(j>0 && str[j]!=str[i]) j=lps[j-1];
        if(str[i]==str[j]) j++;
        lps[i]=j;
    }
    return lps;
}
