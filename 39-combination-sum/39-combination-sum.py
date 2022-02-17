class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        combinations=[]
        def find_comb(target,cur_set,n):
            if target<0:
                return
            if target==0:
                combinations.append(cur_set)
                return
            if n==0:
                return
            new_set1 = cur_set[::]
            find_comb(target,new_set1,n-1)
            new_set2 = cur_set[::]
            new_set2.append(candidates[n-1])
            find_comb(target-candidates[n-1],new_set2,n)
        find_comb(target,[],len(candidates))
        return combinations