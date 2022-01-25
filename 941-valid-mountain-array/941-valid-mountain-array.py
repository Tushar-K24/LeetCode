class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr)<3 or arr[1]<=arr[0]:
            return False
        inc=True
        for i in range(1,len(arr)):
            if arr[i-1]==arr[i] or (arr[i-1]<arr[i] and not inc):
                return False
            elif arr[i-1]>arr[i] and inc:
                inc = False
        if inc:
            return False
        return True