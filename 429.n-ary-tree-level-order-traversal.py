#
# @lc app=leetcode.cn id=429 lang=python3
# @lcpr version=30122
#
# [429] N 叉树的层序遍历
#
# https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
#
# algorithms
# Medium (73.09%)
# Likes:    447
# Dislikes: 0
# Total Accepted:    188.2K
# Total Submissions: 255.9K
# Testcase Example:  '[1,null,3,2,4,null,5,6]'
#
# 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
# 
# 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
# 
# 
# 
# 示例 1：
# 
# 
# 
# 输入：root = [1,null,3,2,4,null,5,6]
# 输出：[[1],[3,2,4],[5,6]]
# 
# 
# 示例 2：
# 
# 
# 
# 输入：root =
# [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
# 
# 
# 
# 
# 提示：
# 
# 
# 树的高度不会超过 1000
# 树的节点总数在 [0, 10^4] 之间
# 
# 
#


# @lcpr-template-start

# Definition for a Node.

# @lcpr-template-
# @lc code=start
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
        
class Solution:
    def levelOrder(self, root: Node) -> list[list[int]]:
        ans: list = []
        if root is None:
            return ans
        task: list[Node] = [root]
        while task:
            val = []
            nextStage = []
            for t in task:
                val.append(t.val)
                nextStage.extend(t.children)
            ans.append(val)
            task = nextStage
        return ans
        
# @lc code=end

if __name__ == "__main__":
    obj = Solution()


#
# @lcpr case=start
# [1,null,3,2,4,null,5,6]\n
# @lcpr case=end

# @lcpr case=start
# [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n
# @lcpr case=end

#

