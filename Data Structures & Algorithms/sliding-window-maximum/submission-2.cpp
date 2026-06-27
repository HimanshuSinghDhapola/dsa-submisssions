class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            // check whether the first element should be in window
            while(!window.empty() && window.front() <= i-k){
                window.pop_front();
            }

            // pop all the elements less than the current element inorder to maintain monotonic decreasing deque
            while(!window.empty() && nums[window.back()] < nums[i]){
                window.pop_back();
            }

            // push element in the window
            window.push_back(i);

            // check whether window is created if yes push the maxElement
            if(i >= k-1){
                ans.push_back(nums[window.front()]);
            }
        }
        return ans;
    }
};
