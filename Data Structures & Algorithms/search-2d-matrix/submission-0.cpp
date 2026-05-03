class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int start = 0;
        int end = (rowSize * colSize) - 1;

        while(start <= end){
            int mid = start + (end-start)/2;
            int row = mid/colSize;
            int col = mid%colSize;

            if(target < matrix[row][col]){
                end = mid-1;
            }else if(target > matrix[row][col]){
                start = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};
