class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int prefix =0;
        int count =0;
        int n= nums.size();
        //1 1 1 
        //2
        //2
        hashMap[0]=1;
        for(int i=0;i<n;i++)
        {
            prefix += nums[i];
            if(hashMap.find(prefix - k) != hashMap.end())
                count += hashMap[prefix-k];
            hashMap[prefix]++;
        }
        return count;
    }
};