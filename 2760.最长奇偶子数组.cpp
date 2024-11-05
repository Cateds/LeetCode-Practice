/*
 * @lc app=leetcode.cn id=2760 lang=cpp
 *
 * [2760] 最长奇偶子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int Res=0, count=0; bool flag = false;
        for (int &i: nums)
            if (i%2==flag && i<=threshold) {
                count++;
                flag = !flag;
            }
            else {
                Res = (Res>=count)?Res:count;
                flag = count = (i%2==0 && i<=threshold);
            }
        Res = (Res>=count)?Res:count;
        return Res;
    }
};
// @lc code=end

