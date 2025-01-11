/*
 * @lc app=leetcode.cn id=1483 lang=cpp
 * @lcpr version=30121
 *
 * [1483] 树节点的第 K 个祖先
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
class TreeAncestor {
    vector<pair<int,int>> Map;
public:
    TreeAncestor(int n, vector<int>& parent) {
        Map.resize(n);
        Map[0] = {parent[0],0};
        for (int i=1; i<n; i++) {
            Map[i].first = parent[i];
            Map[i].second = Map[parent[i]].second+1;
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (node==-1) return -1;
        if (Map[node].second<k) return -1;
        auto ans = node;
        for (int i=0; i<k; i++) {
            ans = Map[ans].first;
            if (ans==-1)
                return ans;
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end



/*
// @lcpr case=start
// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"][[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]\n
// @lcpr case=end

 */

