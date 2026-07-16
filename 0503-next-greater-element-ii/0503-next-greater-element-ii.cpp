class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int>res(n);

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            stk.push(nums[i]);
        }

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }

            if(!stk.empty()){
                res[i] = stk.top(); 
            }else{
                res[i] = -1;
            }
            stk.push(nums[i]);
        }

        return res;
    }
};