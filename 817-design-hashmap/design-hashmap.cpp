class MyHashMap {

    vector<list<pair<int,int>>>arr;
    int max_size = 1e6;

public:
    MyHashMap() 
    {
        arr.resize(max_size);    
    }

    list<pair<int,int>>::iterator search(int key,int index)
    {
        list<pair<int,int>>::iterator it = arr[index].begin();

        while(it != arr[index].end())
        {
            if(it->first == key)return it;
            it++;
        }

        return it;
    }
    
    void put(int key, int value) 
    {
        int index = (key % max_size);
        list<pair<int,int>>::iterator it = search(key,index);

        if(it != arr[index].end())
        {
            arr[index].erase(it);
        }

        arr[index].push_back({key,value});
    }
    
    int get(int key) 
    {
        int index = (key % max_size);
        list<pair<int,int>>::iterator it = search(key,index);

        if(it == arr[index].end())return -1;
        return it->second;     
    }
    
    void remove(int key) 
    {
        int index = (key % max_size);
        list<pair<int,int>>::iterator it = search(key,index);

        if(it == arr[index].end())return;
        arr[index].erase(it);    
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */