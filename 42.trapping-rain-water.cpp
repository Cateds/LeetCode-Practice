/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30112
 *
 * [42] 接雨水
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
    int trap(vector<int>& height) {
        int max_total=0;
        int water_total = 0;
        int water_count = 0;
        for (int i=1; i<height.size(); i++) {
            if (height[i]>=height[max_total]) {
                water_total += water_count;
                water_count = 0;
                max_total = i;
            }
            else {
                water_count += height[max_total] - height[i];
            }
        }
        water_count = 0;
        for (int max_temp=height.size()-1,i=max_temp-1; i>=max_total; i--) {
            if (height[i]>=height[max_temp]) {
                water_total += water_count;
                water_count = 0;
                max_temp = i;
            }
            else {
                water_count += height[max_temp] - height[i];
            }
        }
        return water_total;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */

