#104. Maximum Depth of Binary Tree

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def getNextDepth(root:Optional[TreeNode]):
    leftDepth = 0
    rightDepth = 0
    if not root: return 0
    if root.left:
        leftDepth = getNextDepth(root.left)
    if root.right:
        rightDepth = getNextDepth(root.right)
    
    return 1 + max(leftDepth, rightDepth)
        
            
def maxDepth(root: Optional[TreeNode]) -> int:
    return getNextDepth(root)


print(maxDepth([3,9,20,None,None,15,7]))