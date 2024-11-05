/*
 * @lc app=leetcode.cn id=514 lang=cpp
 * @lcpr version=30114
 *
 * [514] 自由之路
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
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> Characters;
        int Ans = 0;
        for (int i=0; i<ring.size(); i++) {
            Characters[ring[i]].push_back(i);
        }
        function <int(const int&,const int&)> dfs = 
            [&key, &Characters, &dfs, &ring](const int &index,const int &pointer) -> int {
                int distance;
                for (auto &i: Characters[key[index]]) {
                    auto temp = min(abs(pointer-i),abs(pointer+ring.size()-i));
                }
            };
        for (auto &ch: key) {
            
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "godding"\n"gd"\n
// @lcpr case=end

// @lcpr case=start
// "godding"\n"godding"\n
// @lcpr case=end

 */

