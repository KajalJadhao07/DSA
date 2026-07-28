class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int i =0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!stk.empty() && stk.top().first <= price){
            stk.pop();
        } 

        int span;

        if(stk.empty()){
            span = i + 1;
        }else{
            span = i - stk.top().second;
        }
        stk.push({price, i});
        i++;
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */