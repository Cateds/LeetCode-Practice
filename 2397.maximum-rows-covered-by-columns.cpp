/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 * @lcpr version=30112
 *
 * [2397] 被列覆盖的最多行数
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
#include <bit>
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        vector<int> data(matrix.size());
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                data[i] += matrix[i][j] << j;
            }
        }
        auto limit = 1 << matrix[0].size();
        int Ans = 0;
        for (auto i=0; i<limit; i++) {
            if (__builtin_popcount(i) != numSelect)
                continue;
            int count = 0;
            for (auto &n: data)
                if ((n & i) == n)
                    count++;
            if (count > Ans)
                Ans = count;
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0],[1,0,1],[0,1,1],[0,0,1]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1],[0]]\n1\n
// @lcpr case=end

 */

