// By : ViditBhardwaj
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ff               first
#define ss               second
#define endl             "\n"
#define mp               make_pair
#define pb               push_back
#define popb             pop_back
#define lb               lower_bound
#define ub               upper_bound
#define int              long long int
#define double           long double
#define TC               int TT; cin>>TT; while(TT--)
#define sz(x)            (int)(x.size()) 
#define mset(a,b)        memset(a,b,sizeof(a))
#define all(v)           (v).begin(),(v).end()
#define setpos(x)        63ll-__builtin_clzll(x)
#define setbits(x)       __builtin_popcountll(x)
#define SPD_emergency    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ps(x,y)          fixed<<setprecision(y)<<x
#define YES              cout<<"YES"<<endl
#define NO               cout<<"NO"<<endl
#define Yes              cout<<"Yes"<<endl
#define No               cout<<"No"<<endl

template<typename T>    // *s.find_by_order(idx) & s.order_of_key(val)
using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using min_pq=priority_queue<T,vector<T>,greater<T> >;
template<typename T> using max_pq=priority_queue<T>;
typedef pair<int,int> pii;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<"["<<#x<<"]"<<"->"; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(int x){cerr<<x;}
void _print(double x){cerr<<x;}
void _print(char x){cerr<<x;}
void _print(bool x){cerr<<x;}
void _print(string x){cerr<<x;}

template<class T> void _print(vector<T> v);
template<class T> void _print(deque<T> dq);
template<class T> void _print(set<T> s);
template<class T> void _print(multiset<T> s);
template<class T> void _print(queue<T> q);
template<class T> void _print(min_pq<T> q); 
template<class T> void _print(max_pq<T> q); 
template<class T> void _print(stack<T> st);
template<class T1,class T2> void _print(pair<T1,T2> p); 
template<class T1,class T2> void _print(map<T1,T2> mp); 
template<class T> void _print(pbds<T> s);
template<class T> void _print(vector<T> v){int c=0; cerr<<"["; for(T x:v){cerr<<(c++?",":""),_print(x);}cerr<<"]";}
template<class T> void _print(deque<T> dq){int c=0; cerr<<"["; for(T x:dq){cerr<<(c++?",":""),_print(x);}cerr<<"]";}
template<class T> void _print(set<T> s){int c=0; cerr<<"["; for(T x:s){cerr<<(c++?",":""),_print(x);}cerr<<"]";}
template<class T> void _print(multiset<T> s){int c=0; cerr<<"["; for(T x:s){cerr<<(c++?",":""),_print(x);}cerr << "]";}
template<class T> void _print(queue<T> q){int c=0; cerr<<"["; while(!q.empty()){cerr<<(c++?",":""),_print(q.front()),q.pop();}cerr<<"]";}
template<class T> void _print(min_pq<T> q){int c=0; cerr<<"["; while(!q.empty()){cerr<<(c++?",":""),_print(q.top()),q.pop();}cerr<<"]";}
template<class T> void _print(max_pq<T> q){int c=0; cerr<<"["; while(!q.empty()){cerr<<(c++?",":""),_print(q.top()),q.pop();}cerr<<"]";}
template<class T> void _print(stack<T> st){int c=0; cerr<<"["; while(!st.empty()){cerr<<(c++?",":""),_print(st.top()),st.pop();}cerr<<"]";}
template<class T1,class T2> void _print(pair<T1,T2> p){cerr<<"{"; _print(p.ff); cerr<<","; _print(p.ss); cerr<<"}";}
template<class T1,class T2> void _print(map<T1,T2> mp){int c=0; cerr<<"["; for(auto x:mp){cerr<<(c++?",":""),_print(x);}cerr<<"]";}
void _print(pbds<int> s){int c=0; cerr<<"["; for(auto x:s){cerr<<(c++?",":""),_print(x);}cerr<<"]";}

const int N=(2e5+10),mod=(1e9+7),inf=(1e18);
const double pi=3.14159265358979323846264338;

int _pow(int a,int b){if(!b){return 1;}int ans=_pow(a,b/2); ans*=ans; if(b%2){return ans*=a;}return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}int lcm(int a,int b){return a/gcd(a,b)*b;}
/*____________________________________________________________________*/

signed main(){
SPD_emergency
#ifndef ViditBhardwaj
    freopen("Debug.txt","w",stderr);
#endif

TC{
    
}

    return 0;
}
/*

*/
