# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root==None:return []
        trees=[]
        vals=[]
        
        trees.append((root,0))
        # vals.append([root.val])#用index控制层数
        while len(trees):
            node,index=trees.pop(0)
            left=node.left
            right=node.right
            if left:
                trees.append((left,index+1))
                
            if right:
                trees.append((right,index+1))
            # print(len(vals),index)
            if len(vals)-1==index:
                vals[index].append(node.val)
            elif len(vals)==index:
                vals.append([node.val])

        return vals
            
            