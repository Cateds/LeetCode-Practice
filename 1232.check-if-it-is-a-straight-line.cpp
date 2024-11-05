/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 * @lcpr version=30112
 *
 * [1232] 缀点成线
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
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair<int,int> slope = {
            coordinates[0][0] - coordinates[1][0],  // Delta X
            coordinates[0][1] - coordinates[1][1]   // Delta Y
        };
        for (auto i = coordinates.begin()+2; i!=coordinates.end(); i++)
            if ((i[0][0] - coordinates[0][0]) * slope.second !=
                (i[0][1] - coordinates[0][1]) * slope.first )
                return false;
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]\n
// @lcpr case=end

 */

