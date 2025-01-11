#
# @lc app=leetcode.cn id=42 lang=python3
# @lcpr version=30113
#
# [42] 接雨水
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def trap(self, height: list[int]) -> int:
        max_temp: int = 0
        count: int = 0
        Ans: int = 0
        for i in range(1,len(height)):
            if height[i] >= height[max_temp]:
                Ans += count
                max_temp = i
                count = 0
            else:
                count += height[max_temp] - height[i]
        max_total: int = max_temp
        max_temp = len(height) - 1
        count = 0
        for i in range(len(height)-2,max_total-1,-1):
            if height[i] >= height[max_temp]:
                Ans += count
                max_temp = i
                count = 0
            else:
                count += height[max_temp] - height[i]
        return Ans
# @lc code=end



#
# @lcpr case=start
# [0,1,0,2,1,0,1,3,2,1,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [4,2,0,3,2,5]\n
# @lcpr case=end

#

