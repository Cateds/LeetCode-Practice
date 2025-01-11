/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30112
 *
 * [73] 矩阵置零
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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> Rows(matrix.size()), Column(matrix[0].size());
        for (int row=0; row<matrix.size(); row++)
            for (int col=0; col<matrix[0].size(); col++)
                if (!matrix[row][col]) Rows[row] = Column[col] = true;
        for (int i=0; i<Rows.size(); i++)
            if (Rows[i])
                for (int j=0; j<matrix[0].size(); j++)
                    matrix[i][j] = 0;
        for (int i=0; i<Column.size(); i++)
            if (Column[i])
                for (int j=0; j<matrix.size(); j++) 
                    matrix[j][i] = 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */

