/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 * @lcpr version=30118
 *
 * [2575] 找出字符串的可整除数组
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long long cur = 0;
        for (char& c : word) {
            cur = (cur * 10 + (c - '0')) % m;
            res.push_back(cur == 0 ? 1 : 0);
        }
        return res;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/solutions/2668264/zhao-chu-zi-fu-chuan-de-ke-zheng-chu-shu-pv8v/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end



/*
// @lcpr case=start
// "998244353"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n10\n
// @lcpr case=end

 */

