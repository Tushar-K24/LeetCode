class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(int i:nums){
            if(i%2 == 0)
                sum += i;
        }
        vector<int> res;
        for(vector<int> &query: queries){
            if(nums[query[1]]%2 == 0)
                sum -= nums[query[1]];
            nums[query[1]]+=query[0];
            if(nums[query[1]]%2 == 0)
                sum += nums[query[1]];
            res.push_back(sum);
        }
        return res;
    }
};