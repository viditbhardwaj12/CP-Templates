// gives indx of all occurrences string 'str' in string 'pat'
// T=O(|str|+|pat|)
    
const int p=31;
int hashFunct(string str){
    int ans=0;
    for(int i=0;i<str.length();i++){
        int x=mul(str[i]-'a'+1,_pow(p,i),mod);
        ans=add(ans,x,mod);
    }
    return ans;
}
vector<int> rabin_karp(string str,string pat){
    int pat_hash=hashFunct(pat);
    int n=str.size(),m=pat.size();

    vector<int> p_sum(n);
    for(int i=0;i<n;i++){
        p_sum[i]=mul(str[i]-'a'+1,_pow(p,i),mod);
    }
    for(int i=1;i<n;i++){
        p_sum[i]=add(p_sum[i-1],p_sum[i],mod);
    }

    vector<int> indx;
    for(int i=0;i+m-1<n;i++){
        int l=(i),r=(i+m-1);
        int curr_hash=p_sum[r];
        if(l) curr_hash=sub(curr_hash,p_sum[l-1],mod);

        if(curr_hash==mul(pat_hash,_pow(p,l),mod)){
            indx.pb(l);
        }
    }
    return indx;
}
