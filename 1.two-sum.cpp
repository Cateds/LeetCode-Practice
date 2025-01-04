/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30111
 *
 * [1] 两数之和
 */

// @lcpr-template-start
#include <unordered_map>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (mp.find(nums[i]) != mp.end())
                return vector<int> {mp[nums[i]]-1,i};
            mp.insert({target-nums[i], i+1});
        }
        return vector<int>();
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
