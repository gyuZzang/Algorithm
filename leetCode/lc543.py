#543. Diameter of Binary Tree

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    maxDiameter = 0
    def getNextDepth(self, node:Optional[TreeNode]):
        if not node: return 0
        leftDepth = self.getNextDepth(node.left)
        rightDepth = self.getNextDepth(node.right)

        diameter = leftDepth + rightDepth + 2
        
        if self.maxDiameter < diameter:
            self.maxDiameter = diameter

        return 1 + max(leftDepth, rightDepth)
            
                
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.getNextDepth(root)
        return self.maxDiameter


print(Solution.diameterOfBinaryTree([1,2,3,4,5]))