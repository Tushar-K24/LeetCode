class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            while(nums[temp-1]!=temp){
                swap(nums[i], nums[temp-1]);
                temp=nums[i];
            }
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1) res.push_back(i+1);
        }
        return res;
    }
};