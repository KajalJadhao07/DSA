class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));

        if(rows <= 1 && cols <= 1){
            return grid;
        }

        for(int i =0; i<k; i++){
            if(i!= 0){
                grid = res;
            }
            for(int i =0; i< rows; i++){
                for(int j =0; j< cols; j++){
                    if(j == cols-1 && i != rows-1){
                        res[i+1][0] = grid[i][j];
                    }else if(j == cols-1 && i == rows-1){
                        res[0][0] = grid[i][j];
                    }else{
                        res[i][j+1] = grid[i][j];
                    }

                }
            }
        }
        return res;
    }
};