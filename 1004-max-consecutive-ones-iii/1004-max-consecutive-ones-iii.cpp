class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flip = k;
        int l =0;
        int r = 0;
        int ans = 0;

        while(r < nums.size()){
            if(flip > 0 && nums[r] == 0){
                flip--;
                r++;
            }
            else if(flip == 0 && nums[r] == 0){
                while(flip < 1){
                    if(nums[l] == 0){
                        flip++;
                    }
                    l++;
                }
            }else if(nums[r] == 1){
                r++;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};