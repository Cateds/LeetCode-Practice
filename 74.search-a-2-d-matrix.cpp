/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30204
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (50.36%)
 * Likes:    981
 * Dislikes: 0
 * Total Accepted:    474.7K
 * Total Submissions: 941.3K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 *
 *
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 *
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // 我是超级二分查找人
        // 内存乃身外之物，二分查找，递归爽
        auto Row_bs =
            [&](auto &bs,
                const int &begin, const int &end) {
                if (end - begin <= 1)
                    return begin;
                auto i = (begin + end) / 2;
                if (target >= matrix[i].front())
                    return bs(bs, i, end);
                else
                    return bs(bs, begin, i);
            };
        auto row = Row_bs(Row_bs, 0, matrix.size());
        auto Col_bs =
            [&](auto &bs,
                const int &begin, const int &end) {
                if (end - begin == 1)
                    return matrix[row][begin] == target;
                auto i = (begin + end) / 2;
                if (target >= matrix[row][i])
                    return bs(bs, i, end);
                else
                    return bs(bs, begin, i);
            };
        return Col_bs(Col_bs, 0, matrix[0].size());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */
