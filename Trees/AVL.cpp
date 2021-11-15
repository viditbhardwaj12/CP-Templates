// AVL tree (self-banncing BST) does insertion in such a way that tree remains balanced one and we does not get a skewed tree. (h -> log(n))
// Balanced BST => balancing factor={-1,0,1} [balancing factor=(left_subtree_ht-right_subtree_ht)]

// Rotations:
// 1. LL[left-Left case]   {bf=2}   Rotate Right
  
//       20              
//      /                     10
//    10         =>          /  \          
//    /                     5    20
//   5

// 2. RR[Right-Right case]   {bf=-2}    Rotate Left

//     20      =>       30
//      \               / \
//      30             20 40 
//       \
//       40
      
// 3. LR[left-Right case]    {bf=2}   Rotate Right then left

//     30
//     /                  20
//    10       =>        /  \
//     \                10   30
//     20

// 4. RL[Right-Left case]    {bf=-2}    Rotate Left then Right

//     30
//      \                 40
//       50    =>        /  \
//       /              30   50
//      40
  
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int ht,data;
    node *left,*right;
    node(int d){
        data=d;
        ht=1;
        left=NULL;
        right=NULL;
    }
};

class AVL{
private:
    int height(node *root){
        return ((root==NULL)?(0):(root->ht));
    }

    int bf(node *root){
        return (height(root->left)-height(root->right));
    }

    node *l_rotate(node *root){
        node *root_r=root->right;
        node *root_r_l=(root->right)->left;

        root_r->left=root;
        root->right=root_r_l;

        root->ht=1+max(height(root->left),height(root->right));
        root_r->ht=1+max(height(root_r->left),height(root_r->right));
        
        return root_r;    
    }

    node *r_rotate(node *root){
        node *root_l=root->left;
        node *root_l_r=(root->left)->right;

        root_l->right=root;
        root->left=root_l_r;

        root->ht=1+max(height(root->left),height(root->right));
        root_l->ht=1+max(height(root_l->left),height(root_l->right));

        return root_l;
    }

    node *insert(node *root,int key){
        if(root==NULL) return new node(key);
        if(key>root->data) root->right=insert(root->right,key);
        else if(key<root->data) root->left=insert(root->left,key);
        else return root;

        root->ht=1+max(height(root->right),height(root->left));

        if(bf(root)==(2) && key<(root->left)->data)    // LL Case
            return r_rotate(root);
        if(bf(root)==(-2) && key>(root->right)->data)  // RR Case
            return l_rotate(root);
        if(bf(root)==(2) && key>(root->left)->data){    // LR Case
            root->left=l_rotate(root->left);
            return r_rotate(root);
        }
        if(bf(root)==(-2) && key<(root->right)->data){  // RL Case
            root->right=r_rotate(root->right);
            return l_rotate(root);
        }

        return root;
    }    
public:
    node *root=NULL;
    AVL(vector<int> nodes){
        for(auto n:nodes){
            root=insert(root,n);
        }
    }
    node *ret(){
        return root;
    }
};

void preorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    AVL tree(a);
    node *root=tree.ret();

    preorder(root);

    return 0;
}
/*
i/p=> 9 20 25 30 10 5 15 27 19 16
*/
