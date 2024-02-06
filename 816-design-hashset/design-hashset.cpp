class MyHashSet {

    vector<list<int>>arr;
    int max_size = 1e6;

public:

    MyHashSet() 
    {
        arr.resize(max_size);
    }

    int getIndex(int key)
    {
        return (key % max_size);
    }
    
    void add(int key) 
    {
        if(contains(key))return;

        int index = getIndex(key);
        arr[index].push_back(key);
    }

    void remove(int key) 
    {
        if(!contains(key))return;
        
        int index = getIndex(key);
        list<int>::iterator it = find(arr[index].begin(),arr[index].end(),key);
        arr[index].erase(it);
    }
    
    bool contains(int key) 
    {
        int index = getIndex(key);

        return (find(arr[index].begin(),arr[index].end(),key) != arr[index].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */