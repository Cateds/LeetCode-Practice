/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 * @lcpr version=30111
 *
 * [1670] 设计前中后队列
 * 
 * 2023/11/28 每日一题
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
class FrontMiddleBackQueue {
private:
    struct Node {
        Node* last;
        Node* next;
        int value;
    };
    Node *Start_Ptr, *End_Ptr, *Middle_Ptr;
    int size;
public:
    FrontMiddleBackQueue() {
        Start_Ptr = End_Ptr = Middle_Ptr = nullptr;
        size = 0;
    }
    
    void pushFront(int val) {
        size ++;
        if (Start_Ptr==nullptr) {
            Middle_Ptr = Start_Ptr = End_Ptr = new Node {nullptr,nullptr,val};
        }
        else {
            auto NewNode = new Node {nullptr,Start_Ptr,val};
            Start_Ptr = Start_Ptr->last = NewNode;
            if (!(size%2)) Middle_Ptr = Middle_Ptr->last;
        }
    }
    
    void pushMiddle(int val) {
        if (size==0) {
            Middle_Ptr = Start_Ptr = End_Ptr = new Node {nullptr,nullptr,val};
        }
        else if (size==1) {
            pushFront(val);
            return;
        }
        else if (size%2) {
            auto NewNode = new Node {Middle_Ptr->last,Middle_Ptr,val};
            Middle_Ptr = Middle_Ptr->last = Middle_Ptr->last->next = NewNode;
        }
        else {
            auto NewNode = new Node {Middle_Ptr,Middle_Ptr->next,val};
            Middle_Ptr = Middle_Ptr->next = Middle_Ptr->next->last = NewNode;
        }
        size ++;
    }
    
    void pushBack(int val) {
        size ++;
        if (End_Ptr==nullptr) {
            Middle_Ptr = Start_Ptr = End_Ptr = new Node {nullptr,nullptr,val};
        }
        else {
            auto NewNode = new Node {End_Ptr,nullptr,val};
            End_Ptr = End_Ptr->next = NewNode;
            if (size%2) Middle_Ptr = Middle_Ptr->next;
        }
    }
    
    int popFront() {
        if (size==0) return -1;
        else if (size==1) {
            int ans = Start_Ptr->value;
            delete Start_Ptr;
            size --;
            Start_Ptr = Middle_Ptr = End_Ptr = nullptr;
            return ans;
        }
        else {
            int ans = Start_Ptr->value;
            Start_Ptr = Start_Ptr->next;
            if (!(size%2)) Middle_Ptr = Middle_Ptr->next;
            delete Start_Ptr->last;
            Start_Ptr->last = nullptr;
            size --;
            return ans;
        }
    }
    
    int popMiddle() {
        if (size<3) {
            return popFront();
        }
        else if (size%2) {
            auto DelNote = Middle_Ptr;
            int ans = DelNote->value;
            Middle_Ptr->next->last = Middle_Ptr->last;
            Middle_Ptr->last->next = Middle_Ptr->next;
            Middle_Ptr = Middle_Ptr->last;
            size --;
            delete DelNote;
            return ans;
        }
        else {
            auto DelNote = Middle_Ptr;
            int ans = DelNote->value;
            Middle_Ptr->next->last = Middle_Ptr->last;
            Middle_Ptr->last->next = Middle_Ptr->next;
            Middle_Ptr = Middle_Ptr->next;
            size --;
            delete DelNote;
            return ans;
        }
    }
    
    int popBack() {
        if (size==0) return -1;
        else if (size==1) {
            int ans = End_Ptr->value;
            delete End_Ptr;
            size --;
            Start_Ptr = Middle_Ptr = End_Ptr = nullptr;
            return ans;
        }
        else {
            int ans = End_Ptr->value;
            End_Ptr = End_Ptr->last;
            if (size%2) Middle_Ptr = Middle_Ptr->last;
            delete End_Ptr->next;
            End_Ptr->next = nullptr;
            size --;
            return ans;
        }
    }
    // void showQueue() {
    //     for (auto i = Start_Ptr; i!=nullptr; i=i->next) {
    //         std::cout << i->value << ' ';
    //     }
    // }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end



/*
// @lcpr case=start
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle","popBack", "popFront"][[], [1], [2], [3], [4], [], [], [], [], []]\n
// @lcpr case=end

 */

int main(void) {
    FrontMiddleBackQueue Obj;
        Obj.popMiddle();
        Obj.popMiddle();
        Obj.pushMiddle(773222);
        Obj.pushMiddle(279355);
        Obj.popMiddle();
        Obj.popMiddle();
        Obj.popMiddle();
        Obj.popBack();
        Obj.popMiddle();
        Obj.popFront();
        Obj.pushBack(448905);
        Obj.popFront();
        Obj.pushMiddle(168284);
        Obj.pushMiddle(874541);
        Obj.popMiddle();
        Obj.popBack();
        Obj.pushFront(15656);
        Obj.popMiddle();
        Obj.pushMiddle(803226);
        Obj.pushMiddle(720129);
        Obj.pushMiddle(626048);
        Obj.popMiddle();
        Obj.pushMiddle(860306);
        Obj.popBack();
        // Obj.pushMiddle(630886);
        // Obj.popMiddle();
        // Obj.popMiddle();
        // Obj.popMiddle();
        // Obj.popMiddle();
        // Obj.popFront();
        // Obj.pushMiddle(837735);
        // Obj.pushMiddle(414354);
        // Obj.pushMiddle(404946);
        // Obj.pushFront(88719);
    // Obj.showQueue();
}