class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l,r = -1,len(matrix)*len(matrix[0])
        while r-l>1:
            m = (l+r)>>1
            i = m//len(matrix[0])
            j = m%len(matrix[0])
            if matrix[i][j]<=target:
                l=m
            else:
                r=m
        i = l//len(matrix[0])
        j = l%len(matrix[0])
        return matrix[i][j]==target