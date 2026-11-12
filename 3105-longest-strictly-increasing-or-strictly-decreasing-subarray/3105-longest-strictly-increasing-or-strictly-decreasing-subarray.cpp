class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }

        int n = nums.size();
        int max_length = 1;
        int inc = 1;
        int dec = 1;

        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                inc++;
            } else {
                inc = 1;
            }

            if (nums[i] < nums[i - 1]) {
                dec++;
            } else {
                dec = 1;
            }

            max_length = max(max_length, max(inc, dec));
        }

        return max_length;
    }
};