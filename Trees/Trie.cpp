#include<bits/stdc++.h>
using namespace std;

class trie{
public:
    trie *child[26];
    bool isterminal;
    trie(){
        for(int i=0;i<26;i++) child[i]=NULL;
        isterminal=false;
    }
};

trie *root=new trie();

void insert(string str){
    trie *temp=root;
    for(int i=0;i<str.length();i++){
        if(temp->child[str[i]-'a']==NULL){
            temp->child[str[i]-'a']=new trie();
        }
        temp=temp->child[str[i]-'a'];
    }
    temp->isterminal=true;
}

bool search(string str){
    trie *temp=root;
    for(int i=0;i<str.length();i++){
        if(temp->child[str[i]-'a']==NULL) return false;
        temp=temp->child[str[i]-'a'];
    }
    return temp->isterminal;
}

int main(){
    int Tc; cin>>Tc;
    while(Tc--){
        string str; cin>>str;
        insert(str);
    }

    int q; cin>>q;
    while(q--){
        string str; cin>>str;
        if(search(str)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

/*

10
apple
apipie
appy
ape
boy
bottle
man
mango
sam
samsung
3
samsung
apple
bottle

*/
