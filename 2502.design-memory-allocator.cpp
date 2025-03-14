/*
 * @lc app=leetcode.cn id=2502 lang=cpp
 * @lcpr version=30204
 *
 * [2502] 设计内存分配器
 *
 * https://leetcode.cn/problems/design-memory-allocator/description/
 *
 * algorithms
 * Medium (52.67%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 21.5K
 * Testcase Example:  '["Allocator","allocate","allocate","allocate","freeMemory","allocate","allocate","allocate","freeMemory","allocate","freeMemory"]\n' +
  '[[10],[1,1],[1,2],[1,3],[2],[3,4],[1,1],[1,1],[1],[10,2],[7]]'
 *
 * 给你一个整数 n ，表示下标从 0 开始的内存数组的大小。所有内存单元开始都是空闲的。
 *
 * 请你设计一个具备以下功能的内存分配器：
 *
 *
 * 分配 一块大小为 size 的连续空闲内存单元并赋 id mID 。
 * 释放 给定 id mID 对应的所有内存单元。
 *
 *
 * 注意：
 *
 *
 * 多个块可以被分配到同一个 mID 。
 * 你必须释放 mID 对应的所有内存单元，即便这些内存单元被分配在不同的块中。
 *
 *
 * 实现 Allocator 类：
 *
 *
 * Allocator(int n) 使用一个大小为 n 的内存数组初始化 Allocator 对象。
 * int allocate(int size, int mID) 找出大小为 size 个连续空闲内存单元且位于  最左侧 的块，分配并赋 id mID
 * 。返回块的第一个下标。如果不存在这样的块，返回 -1 。
 * int freeMemory(int mID) 释放 id mID 对应的所有内存单元。返回释放的内存单元数目。
 *
 *
 *
 *
 * 示例：
 *
 * 输入
 * ["Allocator", "allocate", "allocate", "allocate", "freeMemory", "allocate",
 * "allocate", "allocate", "freeMemory", "allocate", "freeMemory"]
 * [[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2],
 * [7]]
 * 输出
 * [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
 *
 * 解释
 * Allocator loc = new Allocator(10); // 初始化一个大小为 10 的内存数组，所有内存单元都是空闲的。
 * loc.allocate(1, 1); // 最左侧的块的第一个下标是 0 。内存数组变为 [1, , , , , , , , , ]。返回 0 。
 * loc.allocate(1, 2); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,2, , , , , , , , ]。返回 1 。
 * loc.allocate(1, 3); // 最左侧的块的第一个下标是 2 。内存数组变为 [1,2,3, , , , , , , ]。返回 2 。
 * loc.freeMemory(2); // 释放 mID 为 2 的所有内存单元。内存数组变为 [1, ,3, , , , , , , ] 。返回 1
 * ，因为只有 1 个 mID 为 2 的内存单元。
 * loc.allocate(3, 4); // 最左侧的块的第一个下标是 3 。内存数组变为 [1, ,3,4,4,4, , , , ]。返回 3 。
 * loc.allocate(1, 1); // 最左侧的块的第一个下标是 1 。内存数组变为 [1,1,3,4,4,4, , , , ]。返回 1 。
 * loc.allocate(1, 1); // 最左侧的块的第一个下标是 6 。内存数组变为 [1,1,3,4,4,4,1, , , ]。返回 6 。
 * loc.freeMemory(1); // 释放 mID 为 1 的所有内存单元。内存数组变为 [ , ,3,4,4,4, , , , ] 。返回 3
 * ，因为有 3 个 mID 为 1 的内存单元。
 * loc.allocate(10, 2); // 无法找出长度为 10 个连续空闲内存单元的空闲块，所有返回 -1 。
 * loc.freeMemory(7); // 释放 mID 为 7 的所有内存单元。内存数组保持原状，因为不存在 mID 为 7 的内存单元。返回 0
 * 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, size, mID <= 1000
 * 最多调用 allocate 和 free 方法 1000 次
 *
 *
 */

// @lcpr-template-start
#include <format>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Allocator {
    int n;
    struct Node {
        int size;
        int mID;
        Node(int size = 0, int mID = -1)
            : size(size), mID(mID) {}
    };
    vector<Node> arr;

public:
    Allocator(int n) : n(n), arr(n) {
        arr.front() = Node{n, -1};
    }

    int allocate(int size, int mID) {
        int idx = 0;
        while (idx < n and (arr[idx].mID != -1 or
                            arr[idx].size < size))
            idx += arr[idx].size;
        if (idx >= n)
            return -1;
        arr[idx].mID = mID;
        if (arr[idx].size > size) {
            arr[idx + size].size = arr[idx].size - size;
            arr[idx].size = size;
        }
        return idx;
    }

    int freeMemory(int mID) {
        int ans = 0;
        int idx = 0;
        while (idx < n) {
            if (arr[idx].mID != mID and arr[idx].mID != -1) {
                idx += arr[idx].size;
            } else {
                auto start = idx;
                int cnt = 0;
                while (idx < n and (arr[idx].mID == mID or arr[idx].mID == -1)) {
                    auto nxt = arr[idx].size + idx;
                    cnt += arr[idx].size;
                    if (arr[idx].mID == mID)
                        ans += arr[idx].size;
                    arr[idx].size = 0;
                    arr[idx].mID = -1;
                    idx = nxt;
                }
                arr[start].size = cnt;
            }
        }
        return ans;
    }

    void showArr(void) {
        int idx = 0;
        while (idx < n) {
            cout << format("({},{},{})\t", idx, arr[idx].size, arr[idx].mID);
            idx += arr[idx].size;
        }
        cout << endl;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
// @lc code=end

// Debug用的神器长串垃圾代码
int main(void) {
    auto obj = new Allocator(100);
    vector<vector<int>> arr = {
        {27}, {12}, {53}, {61}, {80}, {21, 78}, {81, 40}, {50, 76}, {40}, {76}, {63}, {25, 100}, {96, 12}, {92}, {92}, {84}, {19, 71}, {22, 90}, {60}, {42, 79}, {26, 41}, {59, 33}, {79}, {58}, {97}, {92}, {97}, {92}, {40}, {52, 74}, {40}, {53, 17}, {17}, {36, 32}, {51, 13}, {41}, {5, 87}, {44, 66}, {71}, {53}, {74, 14}, {78}, {14}, {32, 54}, {45, 28}, {84, 47}, {16}, {100, 78}, {5, 99}, {33}, {100}, {62, 79}, {31, 32}, {85, 81}, {78}, {34, 45}, {47, 7}, {7}, {84}, {6}, {35, 55}, {94}, {87}, {20}, {87}, {96, 60}, {40, 66}, {28, 96}, {28}, {25, 2}, {100}, {96}, {19, 35}, {16}, {92, 42}, {80}, {79}};
    vector<int> expected = {
        0, 0, 0, 0, 0, 0, -1, 21, 0, 50, 0, 21, -1, 0, 0, 0, 46, 65, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, 87, -1, 19, 0, -1, 21, 0, -1, -1, -1, 0, -1, 0, 0, 25, -1, 5, -1, 0, -1, -1, 0, 0, 0, -1, 0, 5, 0, 0, -1, -1, 36, 0, -1, 0, 28, 36, 0, -1, 0, 0};
    for (int i = 0; i < arr.size(); i++) {
        auto &op = arr[i];
        auto &ans = expected[i];
        cout << format("{}/{}:\t", i, expected.size());
        if (op.size() == 1) {
            auto res = obj->freeMemory(op[0]);
            cout << format("FreeMem(mID:{})\n", op[0]);
            cout << format("Result/Expect:\t{}\t{}\t{}\n", res, ans, res == ans);
            obj->showArr();
        } else {
            auto res = obj->allocate(op[0], op[1]);
            cout << format("Alloc(size:{},mID:{})\n", op[0], op[1]);
            cout << format("Result/Expect:\t{}\t{}\t{}\n", res, ans, res == ans);
            obj->showArr();
        }
        cout << endl;
    }
}