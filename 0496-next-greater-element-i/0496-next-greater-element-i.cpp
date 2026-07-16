class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m;
        stack<int> stk;
        int n = nums2.size()-1;

        for(int i = n; i>=0 ; i--){
            while(!stk.empty() && stk.top()<=nums2[i]){
                stk.pop();
            }
            if(stk.empty()){
                m[nums2[i]] = -1;
            }else{
                m[nums2[i]]=stk.top();
            }
            stk.push(nums2[i]);
        }

        vector<int>res;
        for(int i =0; i<nums1.size(); i++){
            res.push_back(m[nums1[i]]);
        }
        return res;


    }
};