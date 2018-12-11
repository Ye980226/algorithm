### Problem
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
### example
Given binary tree [3,9,20,null,null,15,7],

```auto    
    3
   / \
  9  20
    /  \
   15   7
```
return its level order traversal as:

```auto
[
  [3],
  [9,20],
  [15,7]
]
```

```python
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
        if root==None:return []#判断root是否为空，为空直接返回空列表
        #trees用来模拟队列，先进先出，从左到右把每一个node存到列表里，每次弹出一个
        trees=[]
        #vals用来存每层的值
        vals=[]
        #符合列表的index习惯所以用了0开始
        trees.append((root,0))
        # vals.append([root.val])#用index控制层数
        #循环这棵树
        while len(trees):
            #先进先出，右进左出
            node,index=trees.pop(0)
            left=node.left
            right=node.right
            # left有值就把left加到tree的列表里，并把index增加1
            if left:
                trees.append((left,index+1))
            #right同left理
            if right:
                trees.append((right,index+1))
            # print(len(vals),index)
            #如果是上一层，就把值append到上一层的列表里
            if len(vals)-1==index:
                vals[index].append(node.val)
            #如果是新的一层，就重新创建一个列表并且append进去
            elif len(vals)==index:
                vals.append([node.val])

        return vals
```

二叉树的中序遍历，给每一层做一个标记，方便在列表里append元素。

还有前序遍历，中序遍历，后序遍历，用递归实现比较简单：
1. pre-order是node，左，右
2. in-order是左，node，右
3. post-order是左，右，node