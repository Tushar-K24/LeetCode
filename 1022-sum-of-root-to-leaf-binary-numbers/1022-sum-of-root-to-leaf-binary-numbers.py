# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        self.ans=0
        def solve(root, prev):
            if not root.left and not root.right:
                self.ans+=prev*2 + root.val
                return
            prev*=2
            prev+=root.val
            if root.left:
                solve(root.left,prev)
            if root.right:
                solve(root.right,prev)
            return
        solve(root,0)
        return self.ans
            