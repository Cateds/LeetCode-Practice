/*
 * @lc app=leetcode.cn id=2132 lang=cpp
 * @lcpr version=30111
 *
 * [2132] 用邮票贴满网格图
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
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        auto Task = grid;
        for (auto &Row: Task)
            Row.erase(remove(begin(Row),end(Row),0),end(Row));
        for (int Row=0; Row<Task.size(); Row++)
            for (auto &Col: Task[Row]) {
                // Part 1: 确认左边
                
                // Part 2: 确认右侧

                // Part 3: 确认下侧

            }

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]]\n2\n2\n
// @lcpr case=end

 */

