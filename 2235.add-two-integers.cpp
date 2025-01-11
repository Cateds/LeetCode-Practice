/*
 * @lc app=leetcode.cn id=2235 lang=cpp
 * @lcpr version=30111
 *
 * [2235] 两整数相加
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
    int sum(int num1, int num2) {
        return num1+num2;
        // 我觉得这道题大概是想要考我们机算机系的加法运算的底层原理
        // 但是很可惜我完全不会按位然后加个进位flag的那种做法
    }
};
// @lc code=end
/*
    class Solution {
    public:
        int sum(int num1, int num2) {
            return num1 + num2;
        }
    };

    作者：力扣官方题解
    链接：https://leetcode.cn/problems/add-two-integers/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

    byd官方题解直接用operator+是吧，你是不是在开玩笑
    tmd给我气笑了
*/


/*
// @lcpr case=start
// 12\n5\n
// @lcpr case=end

// @lcpr case=start
// -10\n4\n
// @lcpr case=end

 */

