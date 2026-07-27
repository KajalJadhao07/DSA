class Solution {
public:
    int largest_rect_area(vector<int>& heights){
        stack<int>stk;
        int maxArea = 0;
        int n = heights.size();

        for(int i =0; i<n; i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                int ele = stk.top();
                stk.pop();
                int nse = i;
                int pse = stk.empty() ? -1 : stk.top();
                maxArea = max(maxArea, (nse-pse-1)*heights[ele]);
            }
            stk.push(i);
        }

        while(!stk.empty()){
            int ele = stk.top();
                stk.pop();
                int nse = n;
                int pse = stk.empty() ? -1 : stk.top();
                maxArea = max(maxArea, (nse-pse-1)*heights[ele]);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        int area = 0;
        vector<int> heights(cols,0);

        for(int i =0; i<rows; i++){
    
            for(int j =0; j<cols; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }else{
                    heights[j]=0;
                }

                if(j == cols-1){
                    area = max(area, largest_rect_area(heights));
                }
            }
        }
        return area;
    }
};