/*
 * @lc app=leetcode.cn id=447 lang=cpp
 * @lcpr version=30113
 *
 * [447] 回旋镖的数量
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <map>
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int Ans = 0;
        for (auto &p1: points) {
            unordered_map<int,int> length;
            for (auto &p2: points) {
                length[ (p1[0]-p2[0]) * (p1[0]-p2[0])+
                        (p1[1]-p2[1]) * (p1[1]-p2[1]) ]++;
            }
            for (auto &l: length)
                if (l.second > 1)
                    Ans += l.second * (l.second - 1);
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[1,0],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1]]\n
// @lcpr case=end

 */

