/*
 * @lc app=leetcode.cn id=551 lang=cpp
 * @lcpr version=30204
 *
 * [551] 学生出勤记录 I
 *
 * https://leetcode.cn/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (57.14%)
 * Likes:    164
 * Dislikes: 0
 * Total Accepted:    101.6K
 * Total Submissions: 173.2K
 * Testcase Example:  '"PPALLP"'
 *
 * 给你一个字符串 s 表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
 * 
 * 
 * 'A'：Absent，缺勤
 * 'L'：Late，迟到
 * 'P'：Present，到场
 * 
 * 
 * 如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
 * 
 * 
 * 按 总出勤 计，学生缺勤（'A'）严格 少于两天。
 * 学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
 * 
 * 
 * 如果学生可以获得出勤奖励，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "PPALLP"
 * 输出：true
 * 解释：学生缺勤次数少于 2 次，且不存在 3 天或以上的连续迟到记录。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "PPALLL"
 * 输出：false
 * 解释：学生最后三天连续迟到，所以不满足出勤奖励的条件。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] 为 'A'、'L' 或 'P'
 * 
 * 
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
#include <stdint.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        uint8_t Anum=0, Lnum=0;
        for (auto &ch: s)
            switch (ch) {
            case 'P':
                Lnum = 0; break;
            case 'L':
                if (++Lnum >=3) return false;
                break;
            case 'A':
                if (++Anum >=2) return false;
                Lnum = 0;
                break;
            }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "PPALLP"\n
// @lcpr case=end

// @lcpr case=start
// "PPALLL"\n
// @lcpr case=end

 */

