#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <format>
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
#include <fstream>
using namespace std;

class Solution {
public:
    struct Node {
        vector<int> link;
    };
    struct SpanningTree {
        vector<Node> nodes;
        int root;
    };
    struct path {
        int node[2];
        double val;
    };
    SpanningTree findMinSpanningTree(vector<vector<double>> &graph) {
        int n = graph.size();
        SpanningTree st{vector<Node>(n)};
        auto &ans = st.nodes;
        vector<path> paths;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (graph[i][j] > 0)
                    paths.push_back({i, j, graph[i][j]});
        sort(paths.begin(), paths.end(),
             [](path &l, path &r) {
                 return l.val < r.val;
             });
        vector<int> TreeNum(n, -1);
        int count = 0;
        for (auto &li : paths) {
            if (count == n - 1)
                break;
            if (TreeNum[li.node[0]] == -1 and TreeNum[li.node[1]] == -1) {
                TreeNum[li.node[0]] = TreeNum[li.node[1]] = li.node[0];
                ans[li.node[0]].link.push_back(li.node[1]);
                ans[li.node[1]].link.push_back(li.node[0]);
                count++;
            } else if (TreeNum[li.node[0]] == TreeNum[li.node[1]])
                continue;
            else if (TreeNum[li.node[0]] == -1 or TreeNum[li.node[1]] == -1) {
                if (TreeNum[li.node[0]] == -1) {
                    TreeNum[li.node[0]] = TreeNum[li.node[1]];
                } else {
                    TreeNum[li.node[1]] = TreeNum[li.node[0]];
                }
                ans[li.node[0]].link.push_back(li.node[1]);
                ans[li.node[1]].link.push_back(li.node[0]);
                count++;
            } else if (TreeNum[li.node[0]] != TreeNum[li.node[1]]) {
                ans[li.node[0]].link.push_back(li.node[1]);
                ans[li.node[1]].link.push_back(li.node[0]);
                count++;
                auto temp = TreeNum[li.node[1]];
                for (auto &tn : TreeNum)
                    if (tn == temp)
                        tn = TreeNum[li.node[0]];
            }
        }
        st.root = paths.front().node[0];
        return st;
    }
};

int main(void) {
    int n;
    ifstream fi("graph.txt");
    fi >> n;
    vector<vector<double>> graph(n, vector<double>(n, -1));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            double temp;
            fi >> temp;
            graph[i][j] = temp;
        }
    }
    for (auto &r: graph) {
        for (auto &v: r) {
            cout << v << ' ';
        }
        cout << endl;
    }
    fi.close();
    cout << "--------------------\n";
    auto st =
        Solution().findMinSpanningTree(graph);
    auto dfs =
        [&](auto &dfs, const int &cur, const int &prv) -> void {
        if (prv!=-1)
            printf("(%c,%c)\n", 'A' + prv, 'A' + cur);
        for (auto &li : st.nodes[cur].link) {
            if (li == prv)
                continue;
            dfs(dfs, li, cur);
        }
    };
    dfs(dfs, 0, -1);
}