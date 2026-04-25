class Solution {
    bool traverse(vector<vector<char>>& board, int sr, int er, int sc, int ec){
        unordered_set<char> st;
        for(int i=sr; i<=er; i++){
            for(int j=sc; j<=ec; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(st.find(board[i][j]) != st.end()){
                    return false;
                }else{
                    st.insert(board[i][j]);
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        // Traverse rows
        for(int row = 0; row<size; row++){
            unordered_set<char> st;
            for(int col = 0; col<size; col++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }else{
                    st.insert(board[row][col]);
                }
            }
        }
        // Traverse cols
        for(int col=0; col<size; col++){
            unordered_set<char> st;
            for(int row=0; row<size; row++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }else{
                    st.insert(board[row][col]);
                }
            }
        }
        // Traverse box
        for(int i=0; i<size; i+=3){
            for(int j=0; j<size; j+=3){
                if(!traverse(board, i, i+2, j, j+2)) return false;
                else continue;
            }
        }
        return true;
    }
};
