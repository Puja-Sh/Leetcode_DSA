class LRUCache {
public:
    // We will use doubly LL and unordered hash map also I will create two function to 'add Node' and 'delete Node'
    
    // Creating a class for doubly LL
    class node{
        public:
            int key,val;
            node* next;
            node* prev;
            node(int _key_, int _val_){
                key = _key_;
                val = _val_;
         }
    };
  
    // new node named 'head' and 'tail' & between them addition/deletion of node will take place
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    // creating map of integer and node*(which will store the address of the node and fetching will be O(1))
    unordered_map<int, node*> m;
    
    // global variable to store the capacity so that we can use it in put method 
    int cap; 
    
    // initializing cap with the capacity
    // point head's next to tail
    // point tail's prev to head
    //
    // head -----> tail
    // head <----- tail
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    // head---NEW---node---node---tail
    
    // new->next -------------> head->next
    // new->prev -------------> head
    // head->next ------------> new
    // new->next->prev ------> new
    void addNode(node* addnode) {
        node* temp = head->next;
        addnode->next = temp;
        addnode->prev = head;
        head->next = addnode;
        temp->prev = addnode;
    }
    
    // head---node---DEL_NODE---tail
    
    // delprev(node) and delnext(tail)
    // node->next = delnode->next
    // tail->prev = delnode->prev
    void deleteNode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    
    
    //-> Search in the hash map with the key
    //  - if we got one we have to delete it from the LL as well as from the map
    //  - Again add as a new node(of same key & value) into the LL and hash map(with new address which will be obvioulsy be head->next because new added node will be there just after the head node)
    //-> If not found return -1
    
    int get(int _key) {
        if(m.find(_key) != m.end()) {
            node* resnode = m[_key];
            int res = resnode->val;
            m.erase(_key);
            deleteNode(resnode);
            addNode(resnode);
            m[_key] = head->next;
            return res;
        }
        
        return -1;
    }
    
    //-> Two possibility:
    //  1.map is full       2.We found it already in the map
    
    // 1.map is full
    //    - We have to delete the least recent which must be before the TAIL
    //    - Also delete from the HASH MAP with key
    // 2.It already present in the map
    //    - Delete from the LL
    //    - Delete from the map
    
    //-> Add new node with key & value in LL || In hash map with key and node(head->next)
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size() == cap) {
            node* del = tail->prev;           
            m.erase(del->key);
            deleteNode(del);
        }
        
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */