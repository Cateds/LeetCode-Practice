#
# @lc app=leetcode.cn id=104 lang=python3
# @lcpr version=30204
#
# [104] 二叉树的最大深度
#
# https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
#
# algorithms
# Easy (78.04%)
# Likes:    1888
# Dislikes: 0
# Total Accepted:    1.5M
# Total Submissions: 1.9M
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# 给定一个二叉树 root ，返回其最大深度。
# 
# 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 
# 
# 输入：root = [3,9,20,null,null,15,7]
# 输出：3
# 
# 
# 示例 2：
# 
# 输入：root = [1,null,2]
# 输出：2
# 
# 
# 
# 
# 提示：
# 
# 
# 树中节点的数量在 [0, 10^4] 区间内。
# -100 <= Node.val <= 100
# 
# 
#


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def maxDepth(self, root) -> int:
        if root==None:
            return 0
        def dfs(ptr: TreeNode, depth: int) -> int:
            if ptr == None:
                return depth
            else:
                return max(
                    dfs(ptr.left,depth+1),
                    dfs(ptr.right,depth+1)
                )
        return dfs(root,0)
        
# @lc code=end



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [1,null,2]\n
# @lcpr case=end

#

