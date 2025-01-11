/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30111
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i=0; i<nums.size();) {
            if (nums[i]==0) {
                count++;
                nums.erase(nums.begin()+i);
            }
            else i++;
        }
        for (int i=0; i<count; i++) nums.push_back(0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

