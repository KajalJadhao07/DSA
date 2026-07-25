class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int max_area = 0;
        int n = heights.size();
        for(int i=0; i<n; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int element = stk.top();
                stk.pop();
                int nse = i;
                int pse = stk.empty() ? -1 : stk.top();
                max_area = max(max_area, (nse-pse-1)*heights[element]);
            }
            stk.push(i);
        }

        while(!stk.empty()){
            int nse = n;
            int element = stk.top();
            stk.pop();
            int pse = stk.empty() ? -1 : stk.top();
            max_area = max(max_area, (nse-pse-1)*heights[element]);
        }
        return max_area;
    }
};