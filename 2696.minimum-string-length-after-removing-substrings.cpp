/*
 * @lc app=leetcode.cn id=2696 lang=cpp
 * @lcpr version=30113
 *
 * [2696] 删除子串后的字符串最小长度
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
    int minLength(string s) {
        // .first === character
        // .second === count
        // 栈，观察是否全部符合要求
        stack<pair<char,int>> Prev;
        int count = 0;
        for (auto &ch: s) {
            if (ch == 'A' || ch == 'C')
                Prev.push({ch,count});
            else if (ch == 'B' || ch == 'D') {
                if (!Prev.empty() && ch-1 == Prev.top().first) {
                    if (count!=Prev.top().second)
                        count += 2;
                    Prev.pop();
                }
                else
                    count++;
            }
            else
                count++;
        }
        return count + Prev.size();
    }
};
// @lc code=end

int main(void) {
    cout << Solution().minLength("VKBAJBOYY");
    // QHAATQBB
}


/*
// @lcpr case=start
// "ABFCACDB"\n
// @lcpr case=end

// @lcpr case=start
// "ACBBD"\n
// @lcpr case=end

 */

