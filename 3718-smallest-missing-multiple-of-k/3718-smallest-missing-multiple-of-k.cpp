class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int i =0; i< nums.size(); i++){
            s.insert(nums[i]);
        }
        int multiply = 1;

        for(int i =0; i<=nums.size(); i++){
            if(s.find(multiply*k) == s.end()){
                return multiply*k;
            }
            multiply += 1;
        }
        return (multiply+1)*k;
        
    }
};