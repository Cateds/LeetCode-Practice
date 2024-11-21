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
#include <format>
using namespace std;

class Solution {
public:
    struct Node {
        vector<int> link;
    };
    struct SpanningTree{
        vector<Node> nodes;
        int root;
    };
    SpanningTree findMinSpanningTree(vector<vector<int>> &graph) {
        int n = graph.size();
        SpanningTree st {vector<Node>(n)};
        auto &ans = st.nodes;
        vector<array<int, 3>> links;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (graph[i][j] != INT_MAX)
                    links.push_back({i, j, graph[i][j]});
        sort(links.begin(), links.end(),
             [](array<int, 3> &l, array<int, 3> &r) {
                 return l[2] < r[2];
             });
        vector<int> TreeNum(n,-1);
        int count = 0;
        for (auto &li: links) {
            if (count == n-1) break;
            if (TreeNum[li[0]]==-1 and TreeNum[li[1]]==-1) {
                TreeNum[li[0]] = TreeNum[li[1]] = li[0];
                ans[li[0]].link.push_back(li[1]);
                ans[li[1]].link.push_back(li[0]);
                count++;
            }
            else if (TreeNum[li[0]]==TreeNum[li[1]])
                continue;
            else if (TreeNum[li[0]]==-1 or TreeNum[li[1]]==-1) {
                if (TreeNum[li[0]]==-1) {
                    TreeNum[li[0]] = TreeNum[li[1]];
                }
                else {
                    TreeNum[li[1]] = TreeNum[li[0]];
                }
                ans[li[0]].link.push_back(li[1]);
                ans[li[1]].link.push_back(li[0]);
                count++;
            }
            else if (TreeNum[li[0]]!=TreeNum[li[1]]) {
                ans[li[0]].link.push_back(li[1]);
                ans[li[1]].link.push_back(li[0]);
                count++;
                auto temp = TreeNum[li[1]];
                for (auto &tn: TreeNum)
                    if (tn==temp)
                        tn = TreeNum[li[0]];
            }
        }
        st.root = links.front()[1];
        return st;
    }
};

int main(void) {
    vector<vector<int>> graph(6, vector<int>(6, INT_MAX)); 
    graph[0][1] = 6; graph[0][2] = 1; graph[0][3] = 5; graph[1][0] = 6; 
    graph[1][2] = 5; graph[1][4] = 3; graph[2][0] = 1; graph[2][1] = 5; 
    graph[2][3] = 5; graph[2][4] = 6; graph[2][5] = 4; graph[3][0] = 5; 
    graph[3][2] = 5; graph[3][5] = 2; graph[4][1] = 3; graph[4][2] = 6; 
    graph[4][5] = 6; graph[5][2] = 4; graph[5][3] = 2; graph[5][4] = 6;
    auto st =
        Solution().findMinSpanningTree(graph);
    auto dfs = 
        [&](auto &dfs, const int &cur, const int &prv) ->void {
            printf("%c->%c\n",'A'+prv,'A'+cur);
            for (auto &li: st.nodes[cur].link) {
                if (li==prv) continue;
                dfs(dfs,li,cur);
            }
        };
    dfs(dfs,0,-1);
}