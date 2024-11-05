/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        long Res = 0; bool flag = true, isDone = false, ValuenceDone = false;
        for (auto &i: s) {
            if (i>='0' && i<='9') {
                isDone = true;
                Res = Res*10 + i-48;
                if (flag && Res>0x7FFFFFFF) return 0x7FFFFFFF;
                else if (!flag && Res>0x80000000) return -0x80000000;
            }
            else if (isDone) break;
            else if (i==' ' && !ValuenceDone) continue;
            else if (i=='+' && !ValuenceDone) ValuenceDone = true;
            else if (i=='-' && !ValuenceDone) {flag = false; ValuenceDone = true;}
            else if (!isDone) return 0;
        }
        return Res*(flag?1:-1);
    }
};
// @lc code=end

/*
    1088/1088 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 44.47 % of cpp submissions (6.4 MB)

    这个暴力算法怎么效率还意外的高，太离谱了，
*/