class Solution {
public:
    int check(int mid, vector<int>& nums, int k){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            if((nums[i] + sum) <= mid){
                sum += nums[i];
            }else{
                cnt++;
                sum = nums[i];
            }
            
            if(cnt > k){
                return 1;
            }

            
        }

        return 0;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            int res = check(mid, nums, k);
            if(res == 0){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;

    }
};