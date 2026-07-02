class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            if(matrix[i][m-1] < target){
                continue;
            }else{
                int l = 0;
                int r = m-1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }else if(matrix[i][mid]> target){
                        r = mid-1;
                    }else{
                        l = mid+1;
                    }
                }
            }
        }
        return false;
    }
};