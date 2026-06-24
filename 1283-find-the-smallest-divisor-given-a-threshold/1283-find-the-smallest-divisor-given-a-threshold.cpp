class Solution {
public:
    bool check(int divisor, vector<int>& nums, int threshold){
        int res = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%divisor == 0){
                res += nums[i]/divisor;
            }else if(nums[i] > divisor){
                res += (nums[i]/divisor) + 1;
            }else{
                res += 1;
            }
        }
        return res<=threshold ? true : false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(mid, nums, threshold)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};