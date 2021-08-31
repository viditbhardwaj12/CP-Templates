int add_mod(int a,int b,int m){return (a+b)%m;}

int sub_mod(int a,int b,int m){return ((a-b)%m+m)%m;}

int mul_mod(int a,int b,int m){return ((a%m)*(b%m))%m;}

int pow(int a,int b,int m){
    int ans=1;
    while(b){
        if(b%2) ans=(ans*a)%m;
        b/=2,a=(a*a)%m;
    }
    return ans;
}
int inv_mod(int a,int m){return pow(a,m-2,m);}
int div_mod(int a,int b,int m){return (a*inv_mod(b,m))%m;}
