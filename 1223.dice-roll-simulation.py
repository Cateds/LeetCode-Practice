#
# @lc app=leetcode.cn id=1223 lang=python3
# @lcpr version=30122
#
# [1223] 掷骰子模拟
#
# https://leetcode.cn/problems/dice-roll-simulation/description/
#
# algorithms
# Hard (61.83%)
# Likes:    225
# Dislikes: 0
# Total Accepted:    18.4K
# Total Submissions: 29.7K
# Testcase Example:  '2\n[1,1,2,2,2,3]'
#
# 有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。
# 
# 不过我们在使用它时有个约束，就是使得投掷骰子时，连续 掷出数字 i 的次数不能超过 rollMax[i]（i 从 1 开始编号）。
# 
# 现在，给你一个整数数组 rollMax 和一个整数 n，请你来计算掷 n 次骰子可得到的不同点数序列的数量。
# 
# 假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 模 10^9 + 7 之后的结果。
# 
# 
# 
# 示例 1：
# 
# 输入：n = 2, rollMax = [1,1,2,2,2,3]
# 输出：34
# 解释：我们掷 2 次骰子，如果没有约束的话，共有 6 * 6 = 36 种可能的组合。但是根据 rollMax 数组，数字 1 和 2
# 最多连续出现一次，所以不会出现序列 (1,1) 和 (2,2)。因此，最终答案是 36-2 = 34。
# 
# 
# 示例 2：
# 
# 输入：n = 2, rollMax = [1,1,1,1,1,1]
# 输出：30
# 
# 
# 示例 3：
# 
# 输入：n = 3, rollMax = [1,1,1,2,2,3]
# 输出：181
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= n <= 5000
# rollMax.length == 6
# 1 <= rollMax[i] <= 15
# 
# 
#


# @lcpr-template-start
import numpy as np
# @lcpr-template-end
# @lc code=start
class Solution:
    def dieSimulator(self, n: int, rollMax: list[int]) -> int:
        Count = []
        for i in range(0,6):
            Count.append([0 for x in range(0,rollMax[i])])
            Count[-1][0] = 1
        Count_everyNum = [1 for x in range(0,6)]
        print("Ct:\n",Count)
        print("Ct_EvNm\n",Count_everyNum)
        for i in range(1,n):
            Count_total = 0
            for j in range(0,6):
                Count_total += Count_everyNum[j]
            for j in range(0,6):
                Count_everyNum[j] -= Count[j][-1]
            for num_set in Count:
                for k in range(-1,-len(num_set),-1):
                    num_set[k] = num_set[k-1]
            for j in range(0,6):
                Count[j][0] = Count_total - Count[j][0]
                Count_everyNum[j] += Count[j][0]
            print("Ct:\n",Count)
            print("Ct_EvNm\n",Count_everyNum)
        Count_total = 0
        for i in range(0,6):
            Count_total += Count_everyNum[i]
        return Count_total
            
        
# @lc code=end

if __name__ == "__main__":
    ans = Solution().dieSimulator(3,[1,1,1,2,2,3])
    print(ans)


#
# @lcpr case=start
# 2\n[1,1,2,2,2,3]\n
# @lcpr case=end

# @lcpr case=start
# 2\n[1,1,1,1,1,1]\n
# @lcpr case=end

# @lcpr case=start
# 3\n[1,1,1,2,2,3]\n
# @lcpr case=end

#

