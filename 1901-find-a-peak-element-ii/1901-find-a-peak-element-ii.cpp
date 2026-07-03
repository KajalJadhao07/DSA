class Solution {
public:
    int findmax_row(vector<vector<int>>& mat, int col){
        int maxRow = 0;
        for(int i =1; i<mat.size(); i++){
            if(mat[maxRow][col] < mat[i][col]){
                maxRow = i;
            }
        }
        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = mat[0].size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            int row = findmax_row(mat, mid);

            int left = mid == 0 ? -1 : mat[row][mid-1];
            int right = mid ==  n-1 ? -1 : mat[row][mid+1];

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }else if(mat[row][mid] < left){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return {-1, -1};

    }
};