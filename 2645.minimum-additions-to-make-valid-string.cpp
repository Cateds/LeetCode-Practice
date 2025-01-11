/*
 * @lc app=leetcode.cn id=2645 lang=cpp
 * @lcpr version=30113
 *
 * [2645] 构造有效字符串的最少插入数
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
    int addMinimum(string word) {
        enum Prev_Type{ A, B, C };
        Prev_Type Prev = C;
        int Ans = 0;
        for (auto &ch: word) {
            switch (ch) {
            case 'a':
                Ans += C - Prev;
                Prev = A;
                break;
            case 'b':
                if (Prev==A) Prev = B;
                else {
                    Ans += 1 + C - Prev;
                    Prev = B;
                }
                break;
            case 'c':
                switch (Prev) {
                case A: Ans++; break;
                case C: Ans += 2; break;
                }
                Prev = C;
                break;
            }
        }
        Ans += C - Prev;
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "b"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

