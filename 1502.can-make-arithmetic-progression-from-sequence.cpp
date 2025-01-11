/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 * @lcpr version=30111
 *
 * [1502] 判断能否形成等差数列
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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for (int i=1; i<arr.size()-1; i++) {
            if (2*arr[i]!=arr[i-1]+arr[i+1]) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4]\n
// @lcpr case=end

 */

