class LRUCache {
public:
    vector<pair<int, int>> cache;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                pair<int, int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0; i<cache.size(); i++){
            if(cache[i].first == key){
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        if(n == cache.size()){
            cache.erase(cache.begin());
        }
        cache.push_back({key, value});
    }
};
