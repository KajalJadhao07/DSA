class Solution {
public:

    int check(int mid, vector<int>& arr, int k){
        vector<int> missing;
        int j = 0;
        int i = 1;
        while(i <= mid && j < arr.size()){
            if(arr[j] == i){
                j++;
            }else{
                missing.push_back(i);
                if(missing.size() >= k){
                    return missing[missing.size()-1];
                }
            }
            i++;
        }

        while(i <= mid){
            missing.push_back(i);
            if(missing.size() >= k){
                return missing[missing.size()-1];
            }
            i++;
        }
        return -1;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low = 1;
        int high = 1000 + *max_element(arr.begin(), arr.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high-low)/2;
            int res = check(mid, arr, k);

            if(res != -1){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};