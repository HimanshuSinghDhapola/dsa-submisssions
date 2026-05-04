class Solution {
private: 
    bool canEatAll(vector<int>& piles, int eatingRate, int h){
        int time = 0;
        for(auto &it: piles){
            time += it/eatingRate;
            if(it%eatingRate != 0){
                time++;
            }
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while(l<r){
            int mid = l + (r-l)/2;
            if(canEatAll(piles, mid, h)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
