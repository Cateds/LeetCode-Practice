/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 * @lcpr version=30111
 *
 * [2646] 最小化旅行的价格总和
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
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        vector<vector<int>> next(n);
        for (auto &edge : edges) {
            next[edge[0]].push_back(edge[1]);
            next[edge[1]].push_back(edge[0]);
        }

        vector<int> count(n);
        function<bool(int, int, int)> dfs = [&](int node, int parent, int end) -> bool {
            if (node == end) {
                count[node]++;
                return true;
            }
            for (int child : next[node]) {
                if (child == parent) {
                    continue;
                }
                if (dfs(child, node, end)) {
                    count[node]++;
                    return true;
                }
            }
            return false;
        };
        for (auto &trip: trips) {
            dfs(trip[0], -1, trip[1]);
        }

        function<pair<int, int>(int, int)> dp = [&](int node, int parent) -> pair<int, int> {
            pair<int, int> res = {
                price[node] * count[node], price[node] * count[node] / 2
            };
            for (int child : next[node]) {
                if (child == parent) {
                    continue;
                }
                auto [x, y] = dp(child, node);
                res.first += min(x, y); // node 没有减半，因此可以取子树的两种情况的最小值
                res.second += x; // node 减半，只能取子树没有减半的情况
            }
            return res;
        };
        auto [x, y] = dp(0, -1);
        return min(x, y);
    }
};
// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end
int main(void) {
    Solution obj;
    int n = 4;
    vector<vector<int>> Edges = {{0,1},{1,2},{1,3}};
    vector<int> Prices = {2,2,10,6};
    vector<vector<int>> Trips = {{0,3},{2,1},{2,3}};
    // int n = 2;
    // vector<vector<int>> Edges = {{0,1}};
    // vector<int> Prices = {2,2};
    // vector<vector<int>> Trips = {{0,0}};
    cout << obj.minimumTotalPrice(n,Edges,Prices,Trips);
}


/*
// @lcpr case=start
// 4\n[[0,1],[1,2],[1,3]]\n[2,2,10,6]\n[[0,3],[2,1],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,1]]\n[2,2]\n[[0,0]]\n
// @lcpr case=end

 */

