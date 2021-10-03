#include<bits/stdc++.h>
using namespace std;

const int mod=(1e7+9),p=(31);
int _pow(int a,int b){if(!b){return 1;}int ans=_pow(a,b/2);ans*=ans;if(b%2){return ans*=a;}return ans;}

int add(int a,int b,int m){return (a+b)%m;}
int mul(int a,int b,int m){return ((a%m)*(b%m))%m;}
int sub(int a,int b,int m){return ((a-b)%m+m)%m;}

int hashFunct(string str){
    int ans=0;
    for(int i=0;i<str.length();i++){
        int x=mul(str[i]-'a'+1,_pow(p,i),mod);
        ans=add(ans,x,mod);
    }
    return ans;
}

int main(){
    
    string str="abababbabab",pat="aba";

    int pat_hash=hashFunct(pat);
    int n=str.size(),m=pat.size();

    vector<int> p_sum(n);
    for(int i=0;i<n;i++){
        p_sum[i]=mul(str[i]-'a'+1,_pow(p,i),mod);
    }
    for(int i=1;i<n;i++){
        p_sum[i]=add(p_sum[i-1],p_sum[i],mod);
    }

    for(int i=0;i+m-1<n;i++){
        int l=(i),r=(i+m-1);
        int curr_hash=p_sum[r];
        if(l) curr_hash=sub(curr_hash,p_sum[l-1],mod);

        if(curr_hash==mul(pat_hash,_pow(p,l),mod)){
            cout<<l<<endl;
        }
    }

    return 0;
}
