class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>m;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
        {
            return -1;
        }
        auto it = m[key];
        list<int> :: iterator itt = it.first;
        int val = it.second;
        dll.erase(itt);
        m.erase(key);
        dll.push_front(key);
        m.insert({key,{dll.begin(),val}});
        return val;
    }
    
    void put(int key, int value) {
        //check if it is already present in the dll
        if(m.find(key) != m.end())
        {
            list<int> :: iterator it = m[key].first;
            m[key].second = value;
            dll.erase(it);
            dll.push_front(key);
            m[key].first = dll.begin();
            return;
        }
        else
        {
            if(dll.size() == n)
            {
                int keyToBeDeleted = dll.back();
                m.erase(keyToBeDeleted);
                dll.pop_back();
                dll.push_front(key);
                m.insert({key,{dll.begin(),value}});
            }
            else
            {
                dll.push_front(key);
                m[key]={dll.begin(),value};
                return;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
