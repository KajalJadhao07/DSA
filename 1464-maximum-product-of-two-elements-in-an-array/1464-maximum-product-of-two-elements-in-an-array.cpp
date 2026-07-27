class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ele = 0;
        int sec_max = 0;

        for(int i =0; i < nums.size(); i++){
            if(nums[i] > max_ele){
                sec_max = max_ele;
                max_ele = nums[i];
            }else{
                sec_max = max(sec_max, nums[i]);
            }
        }
        return (max_ele-1)*(sec_max-1);
    }
};