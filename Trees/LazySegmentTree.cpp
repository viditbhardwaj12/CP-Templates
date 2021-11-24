template<typename node,typename update>
class SegTree{
public:
    vector<node> tree,lazy;
    vector<int> a;
    int n;
    SegTree(vector<int> &arr){
        a=arr,n=sz(arr);
        tree.resize(4*n);
        lazy.resize(4*n);
        fill(all(tree),node());
        for(int i=0;i<4*n;i++){
            lazy[i].val=0;
        }
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

    void RangeUpdate(int s,int e,int indx,int qs,int qe,int val){
        if(lazy[indx].val){
            tree[indx].merge(tree[indx],lazy[indx].val*(s-e+1));
            if(s!=e){
                lazy[2*indx].merge(lazy[indx],lazy[2*indx]);
                lazy[2*indx+1].merge(lazy[indx],lazy[2*indx+1]);
            }
            lazy[indx]=0;
        }

        if(qs>e || qe<s) return;    
        
        if(qs<=s and e<=qe){    
            tree[indx].merge(tree[indx],val*(e-s+1));
            if(s!=e){
                lazy[2*indx].merge(val,lazy[2*indx]);
                lazy[2*indx+1].merge(val,lazy[2*indx+1]);
            }
            return;
        }

        int mid=(s+e)/2;
        RangeUpdate(s,mid,2*indx,qs,qe,val);
        RangeUpdate(mid+1,e,2*indx+1,qs,qe,val);
        tree[indx].merge(tree[2*indx],tree[2*indx+1]);
    }
    void update_range(int l,int r,int val){
        RangeUpdate(0,n-1,1,l,r,val);
    }

    void UpdateIdx(int s,int e,int indx,int pos,update &u){
        if(lazy[indx].val){
            tree[indx].merge(tree[indx],lazy[indx].val*(s-e+1));
            if(s!=e){
                lazy[2*indx].merge(lazy[indx],lazy[2*indx]);
                lazy[2*indx+1].merge(lazy[indx],lazy[2*indx+1]);
            }
            lazy[indx]=0;
        }

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

    int IndxQuery(int s,int e,int indx,int pos){
        if(lazy[indx].val){
            tree[indx].merge(tree[indx],lazy[indx].val*(e-s+1));
            if(s!=e){
                lazy[2*indx].merge(lazy[2*indx],lazy[indx]);
                lazy[2*indx+1].merge(lazy[2*indx+1],lazy[indx]);
            }
            lazy[indx]=0;
        }

        if(s>pos or e<pos) return 0;

        if(s==e and s==pos) return tree[indx].val;

        int mid=(s+e)/2;
        if(pos<=mid) return IndxQuery(s,mid,2*indx,pos);
        else return IndxQuery(mid+1,e,2*indx+1,pos);
    }
    int get_indx(int pos){
        return IndxQuery(0,n-1,1,pos).val;      
    }

    node RangeQuery(int s,int e,int indx,int l,int r){
        if(lazy[indx].val){
            tree[indx].merge(tree[indx],lazy[indx].val*(e-s+1));
            if(s!=e){
                lazy[2*indx].merge(lazy[2*indx],lazy[indx]);
                lazy[2*indx+1].merge(lazy[2*indx+1],lazy[indx]);
            }
            lazy[indx]=0;
        }

        if(e<l || s>r)
            return node();
        if(s>=l && e<=r)
            return tree[indx];

        int mid=(s+e)/2;
        node ans,left,right;
        left=RangeQuery(s,mid,2*indx,l,r);
        right=RangeQuery(mid+1,e,2*indx+1,l,r);
        ans.merge(left,right);
        return ans;
    }
    int get_range(int l,int r){
        return RangeQuery(0,n-1,1,l,r).val;
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
