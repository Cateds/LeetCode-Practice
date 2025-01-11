#
# @lc app=leetcode.cn id=739 lang=python3
# @lcpr version=30122
#
# [739] 每日温度
#
# https://leetcode.cn/problems/daily-temperatures/description/
#
# algorithms
# Medium (68.73%)
# Likes:    1750
# Dislikes: 0
# Total Accepted:    544.8K
# Total Submissions: 792.5K
# Testcase Example:  '[73,74,75,71,69,72,76,73]'
#
# 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i
# 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
# 
# 
# 
# 示例 1:
# 
# 输入: temperatures = [73,74,75,71,69,72,76,73]
# 输出: [1,1,4,2,1,1,0,0]
# 
# 
# 示例 2:
# 
# 输入: temperatures = [30,40,50,60]
# 输出: [1,1,1,0]
# 
# 
# 示例 3:
# 
# 输入: temperatures = [30,60,90]
# 输出: [1,1,0]
# 
# 
# 
# 提示：
# 
# 
# 1 <= temperatures.length <= 10^5
# 30 <= temperatures[i] <= 100
# 
# 
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def dailyTemperatures(self, temperatures: list[int]) -> list[int]:
        stack: list[int] = [-1]
        ans: list[int] = [0]
        for i in range(-2,-len(temperatures)-1,-1):
            while stack and temperatures[stack[-1]]<=temperatures[i]:
                del stack[-1]
            if not stack:
                ans.insert(0,0)
            else:
                ans.insert(0,stack[-1]-i)
            stack.append(i)
        return ans
            
        
# @lc code=end

if __name__ == "__main__":
    print(Solution().dailyTemperatures([89,62,70,58,47,47,46,76,100,70]))


#
# @lcpr case=start
# [73,74,75,71,69,72,76,73]\n
# @lcpr case=end

# @lcpr case=start
# [30,40,50,60]\n
# @lcpr case=end

# @lcpr case=start
# [30,60,90]\n
# @lcpr case=end

#

