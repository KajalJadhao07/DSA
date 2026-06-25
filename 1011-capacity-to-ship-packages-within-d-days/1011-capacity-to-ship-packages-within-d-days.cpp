class Solution {
public:
    bool check(int mid, vector<int>& weights, int days){
        int sum = 0;
        int cntdays = 1;

        for (int num : weights){
            if(sum + num <= mid){
                sum += num;
            }else{
                sum = num;
                cntdays++;
            }
            if(cntdays > days){
                return false;
            }
        }
        return cntdays <= days ? true : false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(mid, weights, days)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};