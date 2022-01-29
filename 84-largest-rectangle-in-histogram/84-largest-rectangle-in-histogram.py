class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        def to_the_right():
            res,stack = [],[]
            for i in range(len(heights)-1,-1,-1):
                while len(stack) and heights[stack[-1]]>=heights[i]:
                    stack.pop()
                res.append(stack[-1] if len(stack) else len(heights))
                stack.append(i)
            return res[::-1]
        
        def to_the_left():
            res,stack = [],[]
            for i in range(len(heights)):
                while len(stack) and heights[stack[-1]]>=heights[i]:
                    stack.pop()
                res.append(stack[-1] if len(stack) else -1)
                stack.append(i)
            return res
        
        def max_area(left,right):
            mx_area=0
            for idx, height in enumerate(heights):
                mx_area = max(mx_area,height*(right[idx]-left[idx]-1))
            return mx_area
        
        left,right = to_the_left(),to_the_right()
        return max_area(left,right)
            
            