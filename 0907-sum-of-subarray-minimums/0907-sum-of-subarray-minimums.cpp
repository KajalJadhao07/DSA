class Solution {
public:
    const int mod = 1000000007;

    vector<int> find_nse(vector<int>& arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int> stk;

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                stk.pop();
            }

            res[i] = stk.empty() ? n: stk.top();
            stk.push(i);
        }
        return res;
    }
    vector<int> find_psee(vector<int>& arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int> stk;

        for(int i = 0; i < n; i++){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                stk.pop();
            }

            res[i] = stk.empty() ? -1: stk.top();
            stk.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = find_nse(arr);
        vector<int> psee = find_psee(arr);
        int total = 0;

        for(int i = 0; i < arr.size(); i++){
            int left = i- psee[i];
            int right = nse[i] - i;

            total =( total + (right * left * 1LL * arr[i])% mod) % mod;
        }
        return total;
    }
};