#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于二叉树的广度遍历算法实现，在面试中被问思路和写代码的概率挺高的，需要借助队列来实现
 * */

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}

};

int main() {

    TreeNode* pHead = new TreeNode(0);
    TreeNode* temp1 = new TreeNode(1);
    TreeNode* temp2 = new TreeNode(2);
    pHead->left = temp1;
    pHead->right = temp2;
    TreeNode* temp3 = new TreeNode(3);
    TreeNode* temp4 = new TreeNode(4);
    temp1->left = temp3;
    temp1->right = temp4;
    TreeNode* temp5 = new TreeNode(5);
    temp2->right = temp5;

    //实现深度优先遍历算法
    std::stack<TreeNode*> tempStack;
    tempStack.push(pHead);
    std::vector<int> rVector;
    while(!tempStack.empty()){
        TreeNode* temp = tempStack.top();
        tempStack.pop();
        rVector.push_back(temp->val);
        if(temp->right != NULL){
            tempStack.push(temp->right);
        }
        if(temp->left != NULL){
            tempStack.push(temp->left);
        }
    }

    int len = rVector.size();
    for(int i = 0; i < len; ++i){
        std::cout << rVector[i] << "  " << std::endl;
    }

    return 0;
}