/*
 * @lc app=leetcode.cn id=3033 lang=cpp
 * @lcpr version=30204
 *
 * [3033] 修改矩阵
 *
 * https://leetcode.cn/problems/modify-the-matrix/description/
 *
 * algorithms
 * Easy (80.07%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 22.7K
 * Testcase Example:  '[[1,2,-1],[4,-1,6],[7,8,9]]'
 *
 * 给你一个下标从 0 开始、大小为 m x n 的整数矩阵 matrix ，新建一个下标从 0 开始、名为 answer 的矩阵。使 answer 与
 * matrix 相等，接着将其中每个值为 -1 的元素替换为所在列的 最大 元素。
 * 
 * 返回矩阵 answer 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
 * 输出：[[1,2,9],[4,8,6],[7,8,9]]
 * 解释：上图显示了发生替换的元素（蓝色区域）。
 * - 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
 * - 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[3,-1],[5,2]]
 * 输出：[[3,2],[5,2]]
 * 解释：上图显示了发生替换的元素（蓝色区域）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 2 <= m, n <= 50
 * -1 <= matrix[i][j] <= 100
 * 测试用例中生成的输入满足每列至少包含一个非负整数。
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
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        auto num_row = matrix.size();
        auto num_col = matrix[0].size();
        for (int col=0; col<num_col; col++) {
            int value_max = 0;
            vector<int> index_minus;
            for (int row=0; row<num_row; row++) {
                if (matrix[row][col]>value_max) value_max = matrix[row][col];
                if (matrix[row][col]==-1) index_minus.push_back(row);
            }
            for (auto &index: index_minus)
                matrix[index][col] = value_max;
        }
        return matrix;
    }
};
// @lc code=end

int main(void) {
    Solution obj;
    vector<vector<int>> temp = {
        {1,2},{1,-1}
    };
    // auto result = temp;
    auto result = obj.modifiedMatrix(temp);
    for (auto &row: result) {
        for (auto &num: row)
            cout << num << ' ';
        cout << endl;
    }
}


/*
// @lcpr case=start
// [[1,2,-1],[4,-1,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,-1],[5,2]]\n
// @lcpr case=end

 */

