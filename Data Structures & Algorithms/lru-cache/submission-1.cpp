class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mpp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }

    void makeKeyRecentlyUsed(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        makeKeyRecentlyUsed(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp[key].second = value;
            makeKeyRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            size--;
        }
        if(size<0){
            int key_to_be_del = dll.back();
            mpp.erase(key_to_be_del);
            dll.pop_back();
            size++;
        }
    }
};
