
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    bool ltag;
    bool rtag;

    TreeNode(int val, 
             TreeNode *lchild = nullptr,
             TreeNode *rchild = nullptr,
             bool ltag = 0, bool rtag = 0):
             val(val),lchild(lchild),rchild(rchild),ltag(ltag),rtag(rtag) {}
};

/*
    @var    arr1:    前序序列
            arr2:    中序序列
*/
TreeNode* buildTree(std::vector<int> arr1, std::vector<int> arr2) {
    std::function<int>
}