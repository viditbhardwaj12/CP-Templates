int _pow(int a,int b){if(!b){return 1;}int ans=_pow(a,b/2); ans*=ans; if(b%2){return ans*=a;}return ans;}
