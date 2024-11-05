/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 * @lcpr version=30111
 *
 * [1466] 重新规划路线
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
    int minReorder(int n, vector<vector<int>>& connections) {
        enum Direction_Enum { From, To };
        vector<vector<pair<int,Direction_Enum>>> Nodes(n);
        for (auto &road: connections) {
            Nodes[road[0]].push_back({road[1],To});
            Nodes[road[1]].push_back({road[0],From});
        }
        int Ans = 0;
        for (auto &link: Nodes[0]) {
            if (link.second == To) Ans++;
            function<int(const int&, const int&)> dfs = 
            [&Nodes,&dfs] (const int &root, const int &parent) -> int {
                if (Nodes[root].size()==1) return 0;
                int Ans = 0;
                for (auto &link: Nodes[root]) {
                    if (link.first==parent) continue;
                    else if (link.second==To) {
                        Ans++;
                    }
                    Ans += dfs(link.first,root);
                }
                return Ans;
            };
            Ans += dfs(link.first,0);
        }
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[1,3],[2,3],[4,0],[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,0],[1,2],[3,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,0],[2,0]]\n
// @lcpr case=end

 */

