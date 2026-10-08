class LRUCache {
public:
  struct node{
    int key,val;
    node* prev;
    node* next;
     node(int k, int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
     }
  };

unordered_map<int,node*> f;
int cap;
node* head;
node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void remove(node* Node){
        Node->prev->next=Node->next;
        Node-> next->prev=Node->prev;
    }
     void insertFront(node* node1) {
        node1->next = head->next;
        node1->prev = head;

        head->next->prev = node1;
        head->next = node1;
    }
    int get(int key) {
        if (f.find(key) == f.end())
            return -1;

        node* node1 = f[key];

        remove(node1);
        insertFront(node1);

        return node1->val;
    }
    
    void put(int key, int value) {
        if (f.find(key) != f.end()) {
            node* node1 = f[key];

            node1->val = value;

            remove(node1);
            insertFront(node1);

            return;
        }
    node* node1 =new node(key,value);
          f[key]=node1;
          insertFront(node1);
          if(f.size()>cap){
            node* lru=tail->prev;
            f.erase(lru->key);
            remove(lru);
            delete lru;
          }
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */