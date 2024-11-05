/*
 * @lc app=leetcode.cn id=2908 lang=cpp
 * @lcpr version=30120
 *
 * [2908] 元素和最小的山形三元组 I
 */


// @lcpr-template-start
using namespace std;
#include <vector>
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        if (nums.size()<=2) return -1;
        int ans = nums[0] + nums[1] + nums[2];
        bool isIncreasing = nums[1] > nums[0];
        for (int i=1; i<nums.size()-1; i++) {
            if (isIncreasing and (nums[i+1] < nums[i])) {
                int count = nums[i-1] + nums[i] + nums[i+1];
                if (count < ans) ans = count;
            }
            isIncreasing = nums[i+1] > nums[i];
        }
        return ans;
    }
};
// 之后突然意识到了这玩意没说是连续三个数字
// 笑死
// @lc code=end



/*
// @lcpr case=start
// [8,6,1,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,7,10,2]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,3,4,5]\n
// @lcpr case=end

 */

