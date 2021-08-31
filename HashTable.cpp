template<typename K,typename V>
class node{
public:
    node *next;
    K key; 
    V val;
    node(K key,V val){
        this->key=key;
        this->val=val;
        next=NULL;
    }
};

template<typename K,typename V>
class HashTable{
private:
    node<K,V> ** Table;
    int TableSize;
    int CurrSize;
    int HashFunc(K key){    // if(key==int) key=str
        int indx=0,mul=1;
        // string key=to_string(str); // if(key==int) cmnt out
        for(int i=0;i<key.size();i++){  
            key[i]%=TableSize;
            mul%=TableSize;
            indx=(indx+(mul*key[i]))%TableSize;
            mul*=37;
        }
        indx%=TableSize;
        return indx;
    }
    void Rehashing(){
        node<K,V> **OldTable=Table;
        int OldTableSize=TableSize;

        TableSize*=2,CurrSize=0;
        Table=new node<K,V> *[TableSize];
        for(int i=0;i<TableSize;i++){
            Table[i]=NULL;
        }

        for(int i=0;i<OldTableSize;i++){
            node<K,V> *temp=OldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }
        }
        delete[] OldTable;
    }
public:
    HashTable(int ts=10){
        TableSize=ts;
        CurrSize=0;

        Table=new node<K,V> *[TableSize];
        for(int i=0;i<TableSize;i++){
            Table[i]=NULL;
        }
    }
    void insert(K key,V val){
        int indx=HashFunc(key);

        node<K,V> *n=new node<K,V> (key,val);
        n->next=Table[indx];
        Table[indx]=n;
        CurrSize++;

        double load_factor=(double)(CurrSize/TableSize);        
        if(load_factor>0.6)
            Rehashing();
    }
    void deleteNode(K key){
        for(int i=0;i<TableSize;i++){
            node<K,V> *temp=Table[i],*prev=NULL;
            while(temp){
                if(temp->key==key){
                    if(prev==NULL){ 
                        prev=temp;
                        temp=temp->next;
                        Table[i]=temp;
                        delete(prev);
                    }else if(temp->next==NULL){
                        prev->next=NULL;
                        delete(temp);
                    }else{
                        prev->next=temp->next;
                        delete(temp);
                    }
                    CurrSize--;
                    return;
                }

                prev=temp;
                temp=temp->next;
            }
        }
    }
    void print(){   
        for(int i=0;i<TableSize;i++){
            cout<<i<<"->";
            node<K,V> *temp=Table[i];
            while(temp){
                cout<<"["<<temp->key<<","<<temp->val<<"]";
                temp=temp->next;
            }cout<<endl;
        }
    }
    node<K,V> *search(K key){
        int indx=HashFunc(key);
        node<K,V> *temp=Table[indx];
        while(temp){
            if(temp->key==key) 
                return temp;
            temp=temp->next;
        }
        return NULL;
    }
    V &operator[](K key){
        node<K,V> *ans=search(key);        
        if(ans){
            return ans->val;
        }else{
            int garbage_val=INT_MAX;
            insert(key,garbage_val);
            ans=search(key);
            return ans->val;
        }
    }
    int size_map(){
        return CurrSize;
    }   
    bool is_empty(){
        return (CurrSize==0);
    }    
};
