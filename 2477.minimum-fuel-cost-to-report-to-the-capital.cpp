/*
 * @lc app=leetcode.cn id=2477 lang=cpp
 * @lcpr version=30111
 *
 * [2477] 鍒拌揪棣栭兘鐨勬渶灏戞补鑰?
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
    struct TreeNode {
        vector<TreeNode*> links;
    };
    // 第一个参数是当前树的根部，第二个参数是从哪里进入这根树
    // 返回值前面是总耗油量，后面是总人数
    pair<long long,int> CountVol(TreeNode*& Root,const TreeNode* From, const int &seats) {
        if (Root->links.size()==1) return pair<int,int>{1,1};
        pair<long long,int> Ans = {0,1};
        for (auto &nextNode: Root->links) {
            if (nextNode==From) continue;
            auto count = CountVol(nextNode,Root,seats);
            Ans.first += count.first;
            Ans.second += count.second;
        }
        Ans.first += (Ans.second+seats-1)/seats;
        return Ans;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        auto City = new TreeNode[roads.size()+1];
        for (auto& road: roads) {
            City[road[0]].links.push_back(&City[road[1]]);
            City[road[1]].links.push_back(&City[road[0]]);
        }
        long long Ans = 0;
        for (auto& link: City[0].links) {
            Ans += CountVol(link,&City[0],seats).first;
        }
        delete [] City;
        return Ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,2],[0,3]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]]\n2\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

 */

