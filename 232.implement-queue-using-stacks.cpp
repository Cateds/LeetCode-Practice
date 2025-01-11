/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30118
 *
 * [232] 用栈实现队列
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
class MyQueue {
private:
    stack<int> data;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stack<int> backUp;
        while (!data.empty()) {
            backUp.push(data.top());
            data.pop();
        }
        data.push(x);
        while (!backUp.empty()) {
            data.push(backUp.top());
            backUp.pop();
        }
    }
    
    int pop() {
        auto ans = data.top();
        data.pop();
        return ans;
    }
    
    int peek() {
        return data.top();
    }
    
    bool empty() {
        return data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

