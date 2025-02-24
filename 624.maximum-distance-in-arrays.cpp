// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=624 lang=cpp
 * @lcpr version=30204
 *
 * [624] 数组列表中的最大距离
 *
 * https://leetcode.cn/problems/maximum-distance-in-arrays/description/
 *
 * algorithms
 * Medium (40.45%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 35.6K
 * Testcase Example:  '[[1,2,3],[4,5],[1,2,3]]'
 *
 * 给定 m 个数组，每个数组都已经按照升序排好序了。
 *
 * 现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 a 和 b 之间的距离定义为它们差的绝对值 |a-b| 。
 *
 * 返回最大距离。
 *
 * 示例 1：
 *
 * 输入：[[1,2,3],[4,5],[1,2,3]]
 * 输出：4
 * 解释：
 * 一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
 *
 *
 * 示例 2：
 *
 * 输入：arrays = [[1],[1]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == arrays.length
 * 2 <= m <= 10^5
 * 1 <= arrays[i].length <= 500
 * -10^4 <= arrays[i][j] <= 10^4
 * arrays[i] 以 升序 排序。
 * 所有数组中最多有 10^5 个整数。
 *
 *
 *
 *
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        array<int, 2> maxIdx =
            arrays[0].back() > arrays[1].back()
                ? array{0, 1}
                : array{1, 0};
        array<int, 2> minIdx =
            arrays[0].front() < arrays[1].front()
                ? array{0, 1}
                : array{1, 0};
        int n = arrays.size();
        for (int idx = 0; idx < n; idx++) {
            if (arrays[idx].back() > arrays[maxIdx[0]].back()) {
                maxIdx[1] = maxIdx[0];
                maxIdx[0] = idx;
            } else if (arrays[idx].back() > arrays[maxIdx[1]].back())
                maxIdx[1] = idx;
            if (arrays[idx].front() < arrays[minIdx[0]].front()) {
                minIdx[1] = minIdx[0];
                minIdx[0] = idx;
            } else if (arrays[idx].front() < arrays[minIdx[1]].front())
                minIdx[1] = idx;
        }
        if (maxIdx[0] != minIdx[0])
            return arrays[maxIdx[0]].back() - arrays[minIdx[0]].front();
        else
            return max(
                arrays[maxIdx[0]].back() - arrays[minIdx[1]].front(),
                arrays[maxIdx[1]].back() - arrays[minIdx[0]].front());
    }
};
// @lc code=end

/**
  @brief 
    解题思路:
    1. 要获得最大距离，需要找到不同数组之间的最大值和最小值的最大差值
    2. 由于每个数组都是升序排序的，所以每个数组的最大值在末尾，最小值在开头
    3. 维护两个数组maxIdx和minIdx:
        - maxIdx存储最大值最大的两个数组的索引
        - minIdx存储最小值最小的两个数组的索引
    4. 遍历所有数组，更新maxIdx和minIdx
    5. 最后需要判断:
        - 如果最大值和最小值不在同一个数组，直接返回它们的差值
        - 如果在同一个数组，需要比较次大值-最小值和最大值-次小值，取较大者
    时间复杂度: O(n)，空间复杂度: O(1)
 */

// @lcpr-div-debug-arg-start
// funName=maxDistance
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [[1,2,3],[4,5],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[0,5]]
// @lcpr case=end
 */
