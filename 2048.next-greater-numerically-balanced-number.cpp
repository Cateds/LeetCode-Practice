/*
 * @lc app=leetcode.cn id=2048 lang=cpp
 * @lcpr version=30111
 *
 * [2048] 下一个更大的数值平衡数
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
    int nextBeautifulNumber(int n) {
        while (true) {
            bool flag_notRight = false;
            array<int,10> Number_Nums = {0};
            for (int i=++n,j=i%10; i!=0; i/=10,j=i%10)
                if (++Number_Nums[j]>j) {
                    flag_notRight = true;
                    break;
                }
            if (flag_notRight) continue;
            for (int i=2; i<10; i++)
                if (Number_Nums[i] && Number_Nums[i]!=i) { 
                    flag_notRight = true;
                    break;
                }
            if (flag_notRight) continue;
            return n;
        }
    }
};
// @lc code=end
int main(void) {
    Solution obj;
    cout << obj.nextBeautifulNumber(1000);
}


/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 1000\n
// @lcpr case=end

// @lcpr case=start
// 3000\n
// @lcpr case=end

 */

