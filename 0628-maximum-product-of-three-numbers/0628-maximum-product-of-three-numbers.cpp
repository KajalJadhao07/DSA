class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;

        int last_product = nums[n]*nums[n-1]*nums[n-2];
        int first_product = nums[n]*nums[0]*nums[1];
        

        return max(last_product, first_product);
    }
};