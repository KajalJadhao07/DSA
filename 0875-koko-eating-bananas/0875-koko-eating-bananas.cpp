class Solution {
public:
    bool check(int mid, vector<int>& piles, int hr){
        int hour = 0;
        for(int i =0; i<piles.size(); i++){
            if(piles[i] <= mid){
                hour++;
            }else if(piles[i]%mid == 0){
                hour += (piles[i]/mid);
            }else{
                hour += (piles[i]/mid) + 1;
            }
            if(hour > hr){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(mid, piles, h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};