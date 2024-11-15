// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3249 lang=cpp
 * @lcpr version=30204
 *
 * [3249] 统计好节点的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-good-nodes/description/
 *
 * algorithms
 * Medium (52.40%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 19.4K
 * Testcase Example:  '[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]'
 *
 * 现有一棵 无向 树，树中包含 n 个节点，按从 0 到 n - 1 标记。树的根节点是节点 0 。给你一个长度为 n - 1 的二维整数数组
 * edges，其中 edges[i] = [ai, bi] 表示树中节点 ai 与节点 bi 之间存在一条边。
 * 
 * 如果一个节点的所有子节点为根的 子树 包含的节点数相同，则认为该节点是一个 好节点。
 * 
 * 返回给定树中 好节点 的数量。
 * 
 * 子树 指的是一个节点以及它所有后代节点构成的一棵树。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
 * 
 * 输出：7
 * 
 * 说明：
 * 
 * 树的所有节点都是好节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]
 * 
 * 输出：6
 * 
 * 说明：
 * 
 * 树中有 6 个好节点。上图中已将这些节点着色。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：edges =
 * [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]
 * 
 * 输出：12
 * 
 * 解释：
 * 
 * 除了节点 9 以外其他所有节点都是好节点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * 输入确保 edges 总表示一棵有效的树。
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        struct Node {
            vector<int> link;
            vector<unsigned> cnt;
        };
        vector<Node> Nodes(1);
        int ans = 0;
        for (auto &ed: edges) {
            if (max(ed[0],ed[1])>=Nodes.size())
                Nodes.resize(max(ed[0],ed[1])+1);
            Nodes[ed[0]].link.push_back(ed[1]);
            Nodes[ed[1]].link.push_back(ed[0]);
        }
        auto dfs = 
        [&](auto &dfs, const int &ptr, const int &prv) {
            auto n = Nodes[ptr].link.size();
            if (ptr!=0 and n==1) {
                ans ++;
                return 1;
            }
            else {
                for (auto &li: Nodes[ptr].link)
                    if (li==prv)
                        continue;
                    else {
                        Nodes[ptr].cnt.push_back(
                            dfs(dfs, li, ptr)
                        );
                    }
                int cnt = Nodes[ptr].cnt[0];
                bool isGood = true;
                int end = n-1+(ptr==0);
                for (int i=1; i<end; i++) {
                    if (isGood and Nodes[ptr].cnt[i]!=Nodes[ptr].cnt[i-1]) {
                        isGood = false;
                    }
                    cnt += Nodes[ptr].cnt[i];
                }
                ans += isGood;
                return cnt+1;
            }
        };
        dfs(dfs,0,-1);
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countGoodNodes
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,0],[4,2],[1,2],[3,1],[5,1]]\n
// @lcpr case=end
 */

