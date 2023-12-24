class LRUCache {

    map<int,int>keyValue;
    map<int,list<int>::iterator>getAddress;
    list<int>linked_list;

    int total_capacity;
    int curr_capacity;

public:
    LRUCache(int capacity) {
        total_capacity = capacity;
        curr_capacity = 0;
    }
    
    int get(int key) 
    {
        if(keyValue.find(key) == keyValue.end())return -1;

        //Remove node
        list<int>::iterator it = getAddress[key];
        linked_list.erase(it);

        //Add node to front
        linked_list.push_front(key);
        getAddress[key] = linked_list.begin();

        //Return value
        return keyValue[key];    
    }
    
    void put(int key, int value) 
    {
        //If key already exists remove it
        if(keyValue.find(key) != keyValue.end())
        {
            list<int>::iterator it = getAddress[key];
            linked_list.erase(it);
            getAddress.erase(key);
            keyValue.erase(key);

            curr_capacity--;
        }    

        if(curr_capacity == total_capacity)
        {
            int last_key = linked_list.back();
            linked_list.pop_back();

            keyValue.erase(last_key);
            getAddress.erase(last_key);
            curr_capacity--;
        }

        curr_capacity++;
        linked_list.push_front(key);

        keyValue[key] = value;
        getAddress[key] = linked_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */