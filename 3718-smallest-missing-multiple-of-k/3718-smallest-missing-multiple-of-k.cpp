class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int i =0; i< nums.size(); i++){
            s.insert(nums[i]);
        }
        int multiply = k;

        while(true){
            if(s.find(multiply) == s.end()){
                return multiply;
            }

            multiply += k;
        }

        return multiply+k;
        
    }
};