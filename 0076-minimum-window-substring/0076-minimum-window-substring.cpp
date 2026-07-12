class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        unordered_map<char, int>m;

        for(char ch : t){
            m[ch]++;
        }
        int k = t.size();
        int l = 0;
        int r = 0;
        int start_idx = -1;
        int length = INT_MAX;
        int cnt = 0;
        while(r < s.size()){
            m[s[r]]--;
            if(m[s[r]]>=0){
                cnt++;
            }

            while(cnt == k){
                if(length > r-l+1){
                    start_idx = l;
                    length = r-l+1;
                }
                m[s[l]]++;
                if(m[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if(start_idx == -1){
            return "";
        }
        return s.substr(start_idx, length);
    }
};