/*
 * @lc app=leetcode.cn id=2735 lang=cpp
 * @lcpr version=30112
 *
 * [2735] 收集巧克力
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
    long long minCost(vector<int> &nums, int x) {
        function<unsigned long long(const int &, const int &)> dfs =
        [&nums,&dfs,&x](const int &index, const int &modTimes) -> unsigned long long {
            // return the minimum value of num from index
            if (index >= nums.size())
                return 0;
            int val = nums[index];
            for (int i=0; i<modTimes; i++) {
                val = (val+1)%nums.size();
            }
            if (val < nums.size()-1)
                return val + dfs(index+1,modTimes);
            else
                return max(val + dfs(index+1,modTimes),
                        (val+1)%nums.size() + x + dfs(index+1,modTimes+1)
                );
        };
        return dfs(0,0);
        // 算法是错的，继续改
    }
};
// @lc code=end

/*
// @lcpr case=start
// [20,1,15]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

 */
