class Solution {
public:
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

    vector<int> find_nge(vector<int>& arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int> stk;

        for(int i = n-1; i>=0; i--){
            while(!stk.empty() && arr[stk.top()] <= arr[i]){
                stk.pop();
            }

            res[i] = stk.empty() ? n : stk.top();
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

    vector<int> find_pgee(vector<int>& arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int> stk;

        for(int i = 0; i < n; i++){
            while(!stk.empty() && arr[stk.top()] < arr[i]){
                stk.pop();
            }

            res[i] = stk.empty() ? -1: stk.top();
            stk.push(i);
        }
        return res;
    }


    long long sum_of_subarray_min(vector<int>& arr){
        vector<int> nse= find_nse(arr);
        vector<int> psee= find_psee(arr);
        long long total = 0;

        for(int i =0; i<arr.size(); i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total += (right * left * 1LL * arr[i]);
        }
        return total;
    }

    long long sum_of_subarray_max(vector<int>& arr){
        vector<int> nge= find_nge(arr);
        vector<int> pgee= find_pgee(arr);
        long long total = 0;

        for(int i =0; i<arr.size(); i++){
            int left = i - pgee[i];
            int right = nge[i] - i;
            total += (right * left * 1LL * arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sum_of_subarray_max(nums) - sum_of_subarray_min(nums); 
    }
};