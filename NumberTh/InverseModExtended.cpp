int extended_gcd(int a,int b,int& x,int& y){
    if(b==0){x=1,y=0; return a;}
    int x1,y1,g=extended_gcd(b,a%b,x1,y1);
    x=y1,y=x1-y1*(a/b);
    return g;
}
int inv_mod_extended(int a,int m){ 
    int x,y; extended_gcd(a,m,x,y);
    return x;
}
