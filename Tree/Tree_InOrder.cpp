#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于二叉树的中序遍历递归和非递归实现，经常会被问到非递归实现方式，需要借助栈来实现
 * */

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}

};

//递归中序遍历
void inOrderRecur(TreeNode* root, std::vector<int>& rVector){

    if(root == NULL){
        return;
    }else{
        inOrderRecur(root->left, rVector);
        rVector.push_back(root->val);
        inOrderRecur(root->right, rVector);
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
    inOrderRecur(pHead, rVector);

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
    while(p != NULL || !tempStack.empty()){

        while(p != NULL){
            tempStack.push(p);
            p = p->left;
        }

        p = tempStack.top();
        rVector.push_back(p->val);
        tempStack.pop();

        if(p->right != NULL){
            p = p->right;
        }else{
            p = NULL;
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