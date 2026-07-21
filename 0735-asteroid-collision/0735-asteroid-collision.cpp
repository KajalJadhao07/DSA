class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        
        for(int i =0; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                stk.push(asteroids[i]);
            }else{
                while(!stk.empty() && stk.top() > 0 && abs(asteroids[i]) > stk.top()){
                    stk.pop();
                }

                if(!stk.empty() && stk.top() >0 && abs(asteroids[i]) == stk.top()){
                    stk.pop();
                }else if(stk.empty() || stk.top() < 0){
                    stk.push(asteroids[i]);
                }

            }
        }

        vector<int> ans(stk.size());

        for(int i = stk.size() - 1; i >= 0; i--) {
            ans[i] = stk.top();
            stk.pop();
        }

        return ans;
    }
};