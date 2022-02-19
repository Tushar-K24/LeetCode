#define pii pair<int,int> 
#define ff first
#define ss second

struct mycomp{
    bool operator()(pii p1, pii p2){
        return p1.ff>p2.ff;
    }
};

class Solution {
    int odd(int n){
        while((n&1)==0) n>>=1;
        return n;
    }
public:
    int minimumDeviation(vector<int>& nums){
        priority_queue<pii,vector<pii>,mycomp> pq;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            int x=odd(nums[i]);
            mx=max(mx,x);
            pq.push({x,i});
        }
        int ans = INT_MAX;
        while(pq.size()==nums.size()){
            pii x = pq.top();
            pq.pop();
            ans = min(ans,mx-x.ff);
            if((x.ff&1)||(x.ff<nums[x.ss])){
                mx=max(mx,2*x.ff);
                pq.push({2*x.ff,x.ss});
            }
        }
        return ans;
    }
};