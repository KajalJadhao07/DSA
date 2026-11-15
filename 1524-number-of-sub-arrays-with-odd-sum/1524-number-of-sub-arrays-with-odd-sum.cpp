class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0;
        long long even = 1;
        long long sum = 0;
        long long cnt = 0;

        int MOD = 1e9 + 7;

        for(int num : arr){
            sum += num;
            if(sum % 2 == 0){
                cnt += odd;
                even++;
            }else{
                cnt += even;
                odd++;
            }
            cnt %= MOD;
            
        }
        return cnt;
    }
};