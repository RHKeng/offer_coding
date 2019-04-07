#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于二叉树的前序遍历递归和非递归实现，经常会被问到非递归实现方式，需要借助栈来实现
 * */

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}

};

//递归前序遍历
void preOrderRecur(TreeNode* root, std::vector<int>& rVector){

    if(root == NULL){
        return;
    }else{
        rVector.push_back(root->val);
        preOrderRecur(root->left, rVector);
        preOrderRecur(root->right, rVector);
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
    preOrderRecur(pHead, rVector);

    //测试输出
    std::cout << "~~~~~~~~~~~~~~~~~~~~递归方式输出~~~~~~~~~~~~~" << std::endl;
    int len = rVector.size();
    for(int i = 0; i < len; ++i){
        std::cout << rVector[i] << std::endl;
    }
    rVector.clear();

    //非递归方式
    std::stack<TreeNode*> tempStack;
    TreeNode* p = NULL;
    tempStack.push(pHead);
    while(!tempStack.empty()){

        p = tempStack.top();
        tempStack.pop();
        rVector.push_back(p->val);
        if(p->right != NULL){
            tempStack.push(p->right);
        }
        if(p->left != NULL){
            tempStack.push(p->left);
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