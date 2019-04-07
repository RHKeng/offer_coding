#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于二叉树的后序遍历递归和非递归实现，经常会被问到非递归实现方式，需要借助栈来实现
 * 后序遍历非递归相对来说比较复杂，需要用一个pLast指针来存储上一次输出的节点
 * 在当前节点右节点非空情况下，如果上一次输出节点是当前节点的左节点，或者，当前节点左节点为空且上次输出不是当前节点右节点时，当前节点指向当前节点的右节点
 * */

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}

};

//递归后序遍历
void afterOrderRecur(TreeNode* root, std::vector<int>& rVector){

    if(root == NULL){
        return;
    }else{
        afterOrderRecur(root->left, rVector);
        afterOrderRecur(root->right, rVector);
        rVector.push_back(root->val);
        return;
    }

}

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

    //递归方式
    std::vector<int> rVector;
    afterOrderRecur(pHead, rVector);

    //测试输出
    std::cout << "~~~~~~~~~~~~~~~~~~~~递归方式输出~~~~~~~~~~~~~" << std::endl;
    int len = rVector.size();
    for(int i = 0; i < len; ++i){
        std::cout << rVector[i] << std::endl;
    }
    rVector.clear();

    //非递归方式
    std::stack<TreeNode*> tempStack;
    TreeNode* p = pHead;
    TreeNode* pLast = NULL;
    while(p != NULL || !tempStack.empty()){

        while(p != NULL){
            tempStack.push(p);
            p = p->left;
        }

        p = tempStack.top();
        if(p->right == NULL){
            rVector.push_back(p->val);
            tempStack.pop();
            pLast = p;
            p = NULL;
        }else{
            if(pLast == p->left || (p->left == NULL && pLast != p->right)){
                p = p->right;
            }else{
                rVector.push_back(p->val);
                pLast = p;
                tempStack.pop();
                p = NULL;
            }
        }

    }

    //测试输出
    std::cout << "~~~~~~~~~~~~~~~~~~~~非递归方式输出~~~~~~~~~~~~~" << std::endl;
    len = rVector.size();
    for(int i = 0; i < len; ++i){
        std::cout << rVector[i] << std::endl;
    }
    rVector.clear();

    return 0;
}