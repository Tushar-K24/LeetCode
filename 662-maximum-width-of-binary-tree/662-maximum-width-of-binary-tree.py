# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        leftmost, rightmost=[],[]
        def solve(root,lvl,key):
            if not root:
                return
            if len(leftmost)<lvl:
                leftmost.append(key)
            else:
                leftmost[lvl-1]=min(leftmost[lvl-1],key)
            
            if len(rightmost)<lvl:
                rightmost.append(key)
            else:
                rightmost[lvl-1]=max(rightmost[lvl-1],key)
            solve(root.left,lvl+1,2*key-1)
            solve(root.right,lvl+1,2*key)
        
        solve(root,1,1)
        ans=0
        for i in range(min(len(leftmost),len(rightmost))):
            ans=max(ans,rightmost[i]-leftmost[i]+1)    
        return ans