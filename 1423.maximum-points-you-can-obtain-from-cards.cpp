/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 * @lcpr version=30111
 *
 * [1423] 可获得的最大点数
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
    int maxScore(vector<int>& cardPoints, int k) {
        int count = 0;
        for (int i=0; i<k; i++) {
            count += cardPoints[i];
        }
        int ans = count;
        for (int i=0; i<k; i++) {
            count += cardPoints[cardPoints.size()-1-i];
            count -= cardPoints[k-1-i];
            if (count > ans) ans = count;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [9,7,7,9,7,7,9]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,1000,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,79,80,1,1,1,200,1]\n3\n
// @lcpr case=end

 */

