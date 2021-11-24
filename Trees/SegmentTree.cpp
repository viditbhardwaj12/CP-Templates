// 0-based index segTree
// used only for indx update & queries
template<typename node,typename update>
class SegTree{
public:
    vector<node> tree;
    vector<int> a;
    int n;
    SegTree(vector<int> &arr){
        a=arr,n=sz(arr);
        tree.resize(4*n);
        fill(all(tree),node());
        BuildST(0,n-1,1);
    }
    void BuildST(int s,int e,int indx){
        if(s==e){
            tree[indx]=node(a[s]);
            return;
        }
        int mid=(s+e)/2;
        BuildST(s,mid,2*indx);
        BuildST(mid+1,e,2*indx+1);
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }

    void UpdateIdx(int s,int e,int indx,int pos,update &u){
        if(s==e){
            u.apply(tree[indx]);
            return;
        }
        int mid=(s+e)/2;
        if(mid>=pos) UpdateIdx(s,mid,2*indx,pos,u);
        else UpdateIdx(mid+1,e,2*indx+1,pos,u);
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }
    void update_indx(int pos,int val){
        update u=update(val);
        UpdateIdx(0,n-1,1,pos,u);
    }

    node Query(int s,int e,int indx,int l,int r){
        if(e<l || s>r)
            return node();
        if(s>=l && e<=r)
            return tree[indx];
        int mid=(s+e)/2;
        node ans,left,right;
        left=Query(s,mid,2*indx,l,r);
        right=Query(mid+1,e,2*indx+1,l,r);
        ans.merge(left,right);
        return ans;
    }
    node get_indx(int l,int r){
        return Query(0,n-1,1,l,r);
    }
};

class node1{
public:
    int val;
    node1(){
        val=0;    // may change
    }
    node1(int n){   // Actual Node
        val=n;    // may change
    }
    void merge(node1 a,node1 b){    
        val=(a.val+b.val);    // perform merge query here
    }
};
class update1{
public:
    int num;
    update1(int n){    // Actual update
        num=n;    // may change 
    }
    void apply(node1 &a){   
        a.val=num;    // perform update operation here
    }
};
