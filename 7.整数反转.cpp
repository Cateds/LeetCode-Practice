/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int Res=0;
        for (; x!=0; x/=10) {
            if ((0x7FFFFFFF-abs(x%10))/10 < abs(Res)) return 0;
            Res = Res*10 + x%10;
        }
        return Res;
    }
};
// @lc code=end

