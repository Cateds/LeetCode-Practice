/*
 * @lc app=leetcode.cn id=828 lang=cpp
 * @lcpr version=30111
 *
 * [828] 统计子串中的唯一字符
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
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> left(n, -1), right(n, n);
        unordered_map<char, int> last;
        for (int i = 0; i < n; ++i) {
            if (last.count(s[i])) {
                left[i] = last[s[i]];
            }
            last[s[i]] = i;
        }
        last.clear();
        for (int i = n - 1; i >= 0; --i) {
            if (last.count(s[i])) {
                right[i] = last[s[i]];
            }
            last[s[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (i - left[i]) * (right[i] - i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ABC"\n
// @lcpr case=end

// @lcpr case=start
// "ABA"\n
// @lcpr case=end

// @lcpr case=start
// "LEETCODE"\n
// @lcpr case=end

 */

