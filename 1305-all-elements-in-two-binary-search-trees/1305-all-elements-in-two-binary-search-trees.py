# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(root):
            if root==None:
                return []
            l = inorder(root.left)
            l.append(root.val)
            l.extend(inorder(root.right))
            return l
        
        def merge(l1, l2):
            ptr1,ptr2 = 0,0
            res=[]
            while ptr1<len(l1) and ptr2<len(l2):
                if l1[ptr1]<l2[ptr2]:
                    res.append(l1[ptr1])
                    ptr1+=1
                else:
                    res.append(l2[ptr2])
                    ptr2+=1
            while ptr1<len(l1):
                res.append(l1[ptr1])
                ptr1+=1
            while ptr2<len(l2):
                res.append(l2[ptr2])
                ptr2+=1
            return res
        
        l1,l2 = inorder(root1), inorder(root2)
        return merge(l1,l2)
        