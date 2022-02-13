class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        subs = []
        def all_subsets(n,my_set):
            if n==0:
                subs.append(my_set)
                return
            s1 = my_set[::]
            s2 = my_set[::]
            all_subsets(n-1,s1)
            s2.append(nums[n-1])
            all_subsets(n-1,s2)
        all_subsets(len(nums),[])
        return subs