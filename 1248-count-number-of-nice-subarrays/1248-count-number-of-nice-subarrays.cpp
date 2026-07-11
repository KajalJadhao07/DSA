class Solution {
public:

    int cnt_lteq(vector<int>& nums, int k){
        int l =0;
        int r = 0;
        int odds_cnt = 0;
        int valid_odds = k;

        while(r < nums.size()){
            if(nums[r] % 2 != 0){
                while(valid_odds <= 0){
                    if(nums[l] % 2 != 0){
                        valid_odds++;
                    }
                    l++;
                }
                valid_odds--;
                
            }
            odds_cnt += (r-l+1);
            r++;
        } 
        return odds_cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cnt_lteq(nums, k)-cnt_lteq(nums, k-1);
    }
};