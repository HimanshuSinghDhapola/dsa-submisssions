class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int l=0, r=l+1;
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                res = max(res, profit);
            }else{
                l=r;
            }
            r++;
        }
        return res;
    }
};
