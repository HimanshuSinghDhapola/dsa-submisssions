// Brute force solution TC: O(2N) ; SC: O(3N)

class Solution {
private:
    vector<int> findNSL(vector<int> &heights){
        int size = heights.size();
        vector<int> nsl(size);
        stack<int> stk;
        for(int i=0; i<size; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                nsl[i]=-1;
            }else{
                nsl[i]=stk.top();
            }
            stk.push(i);
        }
        return nsl;
    }

    vector<int> findNSR(vector<int> &heights){
        int size = heights.size();
        vector<int> nsr(size);
        stack<int> stk;
        for(int i=size-1; i>=0; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                nsr[i]=size;
            }else{
                nsr[i]=stk.top();
            }
            stk.push(i);
        }
        return nsr;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        vector<int> nsl = findNSL(heights);
        vector<int> nsr = findNSR(heights);

        for(int i=0; i<heights.size(); i++){
            int area = heights[i] * (nsr[i] - nsl[i] -1);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};
