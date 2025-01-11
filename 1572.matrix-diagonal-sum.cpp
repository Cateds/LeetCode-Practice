/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 * @lcpr version=30112
 *
 * [1572] 矩阵对角线元素的和
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
    int diagonalSum(vector<vector<int>>& mat) {
        int Ans = 0, size = mat.size();
        for (int i=0; i<size; i++) {
            Ans += mat[i][i] + mat[i][size-1-i];
        }
        if (size%2)
            Ans -= mat[size/2][size/2];
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[5]]\n
// @lcpr case=end

 */

