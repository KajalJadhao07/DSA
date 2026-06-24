class Solution {
public:

    bool check(int mid, vector<int>& Bd, int flowerreq, int adjflow){
        int cnt = 0;
        int res = 0;
        for(int i =0; i<Bd.size(); i++){
            if(Bd[i] <= mid){
                cnt++;
                if(cnt == adjflow){
                    res++;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }

        return res >= flowerreq ? true: false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(mid, bloomDay, m, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};