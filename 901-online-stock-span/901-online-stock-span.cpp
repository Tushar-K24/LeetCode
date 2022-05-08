class StockSpanner {
    stack<pair<int,int>> st;
    int curr;
public:
    StockSpanner() {
        st.push({INT32_MAX,-1});
        curr=0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans = curr - st.top().second;
        st.push({price,curr++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */