// LINEAR DIOPHANTINE EQ;
// solves: ax+by=g (a & b are not co-prime) & ax+by=1 (a & b are co-prime)    
// x=> multiplicative modular inverse when 'm' & 'a' are not co-prime with one another
// g=> gcd(a,b)
// T=log(min(a,b))

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
