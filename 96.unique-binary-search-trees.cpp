/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30112
 *
 * [96] 不同的二叉搜索树
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> data = {1,1,2,5};
        if (n<=3) return data[n];
        for (int i=4; i<=n; i++) {
            auto count = 0;
            for (int j=0; j<i/2; j++)
                count += data[j] * data[i-1-j] * 2;
            if (i%2)
                count += pow(data[i/2],2);
            data.push_back(count);
        }
        return data.end()[-1];
    }
};
// @lc code=end
int main(void) {
    cout << Solution().numTrees(4);
}


/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

