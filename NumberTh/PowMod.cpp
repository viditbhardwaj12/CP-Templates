int pow(int a,int b,int m){
    int ans=1;
    while(b){
        if(b%2) ans=(ans*a)%m;
        b/=2,a=(a*a)%m;
    }
    return ans;
}
