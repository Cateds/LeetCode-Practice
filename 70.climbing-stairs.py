#
# @lc app=leetcode.cn id=70 lang=python3
# @lcpr version=30204
#
# [70] 爬楼梯
#
# https://leetcode.cn/problems/climbing-stairs/description/
#
# algorithms
# Easy (54.92%)
# Likes:    3649
# Dislikes: 0
# Total Accepted:    1.6M
# Total Submissions: 3M
# Testcase Example:  '2'
#
# 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
# 
# 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
# 
# 
# 
# 示例 1：
# 
# 输入：n = 2
# 输出：2
# 解释：有两种方法可以爬到楼顶。
# 1. 1 阶 + 1 阶
# 2. 2 阶
# 
# 示例 2：
# 
# 输入：n = 3
# 输出：3
# 解释：有三种方法可以爬到楼顶。
# 1. 1 阶 + 1 阶 + 1 阶
# 2. 1 阶 + 2 阶
# 3. 2 阶 + 1 阶
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 45
# 
# 
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1:
            return 1;
        pair: list = [1,2]
        for i in range(2,n):
            pair = [pair[1],pair[0]+pair[1]]
        return pair[1]
        
# @lc code=end



#
# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

#

