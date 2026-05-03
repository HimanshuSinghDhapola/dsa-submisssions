// Optimal solution single stack no extra computation one pass
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        stack<int> stk;
        int n=heights.size();
        for(int i=0; i<n; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                int idx = stk.top();
                stk.pop();

                int rightIdx = i;
                int leftIdx = stk.empty() ? -1 : stk.top();

                int width = rightIdx - leftIdx - 1;
                int area = heights[idx] * width;

                maxArea = max(maxArea, area);
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int idx = stk.top();
            stk.pop();

            int rightIdx = n;
            int leftIdx = stk.empty() ? -1 : stk.top();

            int width = rightIdx - leftIdx -1;
            int area = heights[idx] * width;

            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
