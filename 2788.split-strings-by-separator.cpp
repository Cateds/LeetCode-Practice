/*
 * @lc app=leetcode.cn id=2788 lang=cpp
 * @lcpr version=30113
 *
 * [2788] 按分隔符拆分字符串
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
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> Ans;
        for (auto &str: words) {
            auto Prev = str.begin();
            for (auto ptr = str.begin(); ptr!=str.end(); ptr++) {
                if (*ptr == separator) {
                    if (Prev != ptr)
                        Ans.push_back(string(Prev,ptr));
                    Prev = ptr+1;
                }
            }
            if (Prev != str.end())
                Ans.push_back(string(Prev,str.end()));
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["one.two.three","four.five","six"]\n"."\n
// @lcpr case=end

// @lcpr case=start
// ["$easy$","$problem$"]\n"$"\n
// @lcpr case=end

// @lcpr case=start
// ["|||"]\n"|"\n
// @lcpr case=end

 */

