#687. Longest Univalue Path

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    maxLength = 0

    def getUnivalue(self, node:Optional[TreeNode]):
        if not node: return 0
        leftUnivalue = 0
        rightUnivalue = 0 
        if node.left and node == node.left:
            leftUnivalue = 1 + self.getUnivalue(node.left)
        else:
            self.getUnivalue(node.left)
        if node.right and node == node.right:
            rightUnivalue = 1 + self.getUnivalue(node.right)
        else:
            self.getUnivalue(node.right)   

        univalue = leftUnivalue + rightUnivalue
        
        if self.maxLength < univalue:
            self.maxLength = univalue

        return univalue
            
                
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        self.getUnivalue(self,root)
        return self.maxLength


print(Solution.longestUnivaluePath(Solution,[5,4,5,1,1,5]))
