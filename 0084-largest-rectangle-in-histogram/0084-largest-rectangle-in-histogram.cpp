class Solution {
public:
    vector<int> find_nse(vector<int>& nums){
        stack<int> stk;
        int n = nums.size();
        vector<int> res(n);

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                res[i] = n;
            }else{
                res[i] = stk.top();
            }
            stk.push(i);
        }
        return res;
    }

    vector<int> find_pse(vector<int>& nums){
        stack<int> stk;
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0; i < n; i++){
            while(!stk.empty() && nums[stk.top()]>nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                res[i] = -1;
            }else{
                res[i] = stk.top();
            }
            stk.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = find_nse(heights);
        vector<int> pse = find_pse(heights);
        int area = 0;

        for(int i =0; i<nse.size(); i++){
            area = max(area, (nse[i]-pse[i]-1)* heights[i]);
        }
        return area;
    }
};