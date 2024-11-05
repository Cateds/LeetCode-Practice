#
# @lc app=leetcode.cn id=447 lang=python3
# @lcpr version=30113
#
# [447] 回旋镖的数量
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def numberOfBoomerangs(self, points: list[list[int]]) -> int:
        ans: int = 0
        for p1 in points:
            distance: dict[int,int] = {}
            for p2 in points:
                l = (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2
                if l in distance.keys():
                    distance[l] += 1
                else:
                    distance[l] = 1
            for dis in distance.values():
                if dis >= 2:
                    ans += dis * (dis - 1)
        return ans
# @lc code=end



#
# @lcpr case=start
# [[0,0],[1,0],[2,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1],[2,2],[3,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1]]\n
# @lcpr case=end

#

