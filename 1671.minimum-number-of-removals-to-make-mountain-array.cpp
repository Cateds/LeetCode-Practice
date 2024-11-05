/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 * @lcpr version=30112
 *
 * [1671] 得到山形数组的最少删除次数
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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> increasing(n, 1);
        vector<int> decreasing(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    increasing[i] = max(increasing[i], increasing[j] + 1);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    decreasing[i] = max(decreasing[i], decreasing[j] + 1);
                }
            }
        }

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (increasing[i] > 1 && decreasing[i] > 1) {
                maxLen = max(maxLen, increasing[i] + decreasing[i] - 1);
            }
        }

        return n - maxLen;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,5,6,2,3,1]\n
// @lcpr case=end

 */

