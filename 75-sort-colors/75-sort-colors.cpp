class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr0 = 0, ptr2 = nums.size()-1;
        for(int i=0;i<nums.size();i++){
            while(ptr0<=i && ptr2>=i && nums[i]!=1){
                if(ptr0<=i && nums[i]==0){
                    swap(nums[i], nums[ptr0++]);
                }
                if(ptr2>=i && nums[i]==2){
                    swap(nums[i], nums[ptr2--]);
                }
            }
        }
    }
};