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
    struct Node {
        vector<int> links;
    };
    void Trip_Process(
        Node* &Nodes,                   // 节点
        const vector<int> &Trip,        // 从哪里到哪里
        vector<int> &NodesPassThrough   // 这个是输出的数组
    ) {
        // 写一个队列用来实现BFS
        // 我感觉从我bfs开始这玩意的内存占用和时间占用就低不下来
        // 现在我觉得Hard题目能写的出来答案就是胜利
        // 最终我的评价是去你的BFS
        NodesPassThrough[Trip[1]]++;
        if (Trip[0]==Trip[1]) return;
        queue<pair<int,vector<int>>> Tasks;
        for (auto &link: Nodes[Trip[0]].links) {
            if (link==Trip[1]) {
                NodesPassThrough[Trip[0]]++; return;
            }
            else Tasks.push({link,{Trip[0]}});
        }
        for (auto node = Tasks.front(); !Tasks.empty(); node=Tasks.front())
            for (auto &link: Nodes[node.first].links)
                if (link == *(node.second.end()-1)) continue;                 // Line 1034
                else if (link == Trip[1]) {
                    NodesPassThrough[node.first]++;
                    for (auto &num: node.second) {
                        NodesPassThrough[num]++;
                    }
                    return;
                }
                else {
                    Tasks.push({link,node.second});
                    Tasks.back().second.push_back(node.first);
                    Tasks.pop();
                }
    }
    int CalculatePrice(
        Node* &Nodes,
        vector<int> &Nodes_beAchieved,
        vector<int> &price
    ) {
        int start;
        for (start=0; Nodes_beAchieved[start]==0; start++) continue;
        unordered_map<int,int> Value_Map;
        // Price_1 => if the root is 50% off
        // Price_2 => if the root is not 50% off
        int Price_1 = 0.5 * price[start] * Nodes_beAchieved[start];
        int Price_2 = price[start] * Nodes_beAchieved[start];
        if (Nodes[start].links.size())
            for (auto &link: Nodes[start].links) {
                Price_1 += price[link] * Nodes_beAchieved[link];
                if (Nodes[link].links.size()>1)
                    for (auto &subLink: Nodes[link].links)
                        if (subLink!=start)
                            Price_1 += CalculatePrice_Process(Nodes,Nodes_beAchieved,price,{subLink,link},Value_Map);
                Price_2 += CalculatePrice_Process(Nodes,Nodes_beAchieved,price,{link,start},Value_Map);
            }
        return Price_1<Price_2 ? Price_1 : Price_2 ;
        // 一个比较可行的优化方法：把重复计算优化成查表
    }
    int CalculatePrice_Process(                 // 返回以PositionAndFrom.first为根的子树里面价格的最小值
        Node* &Nodes,
        vector<int> &Nodes_beAchieved,
        vector<int> &price,
        const pair<int,int> &Coordinate,        // .first 现在所处的位置; .second 从什么节点进入这个子树
        unordered_map<int,int> &Value_Map
    ) {
        if (Value_Map.count(Coordinate.first)) return Value_Map[Coordinate.first];
        if (Nodes[Coordinate.first].links.size()==1) {
            return Value_Map[Coordinate.first] = 0.5 * price[Coordinate.first] * Nodes_beAchieved[Coordinate.first];
        }
        else {
            int Price_1 = 0.5 * price[Coordinate.first] * Nodes_beAchieved[Coordinate.first];
            int Price_2 = price[Coordinate.first] * Nodes_beAchieved[Coordinate.first];
            for (auto &link: Nodes[Coordinate.first].links) {
                if (link==Coordinate.second) continue;
                Price_1 += price[link] * Nodes_beAchieved[link];
                if (Nodes[link].links.size()>1)
                    for (auto &subLink: Nodes[link].links)
                        if (subLink!=Coordinate.first)
                            Price_1 += CalculatePrice_Process(Nodes,Nodes_beAchieved,price,{subLink,link},Value_Map);
                Price_2 += CalculatePrice_Process(Nodes,Nodes_beAchieved,price,{link,Coordinate.first},Value_Map);
            }
        return Value_Map[Coordinate.first] = Price_1<Price_2 ? Price_1 : Price_2 ;
        }
    }

    int minimumTotalPrice(
        int n,                      // 总节点数目
        vector<vector<int>>& edges, // 节点之间的连接
        vector<int>& price,         // 通过节点的费用
        vector<vector<int>>& trips  // 旅行的起点终点
    ) {
        // 生成节点并连接节点
        auto Nodes = new Node [n];
        for (auto &edge: edges) {
            Nodes[edge[0]].links.push_back(edge[1]);
            Nodes[edge[1]].links.push_back(edge[0]);
        }
        // 统计所有的trip所走过各个节点的次数
        vector<int> Nodes_beAchieved(n);
        for (auto &trip: trips) {
            Trip_Process(Nodes,trip,Nodes_beAchieved);
        }
        // 开摆，DFS
        auto Ans = CalculatePrice(Nodes,Nodes_beAchieved,price);
        delete [] Nodes;
        return Ans;
    }
};
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

