#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于链表的反向输出，需要借助一个栈来实现
 * 目前还没有在面试中被问到，估计是题目难度相对来说比较小
 * */

struct ListNode{

    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}

};

int main() {

    ListNode* pHead = new ListNode(0);
    ListNode* temp1 = new ListNode(1);
    ListNode* temp2 = new ListNode(2);
    ListNode* temp3 = new ListNode(3);
    ListNode* temp4 = new ListNode(4);
    ListNode* temp5 = new ListNode(5);
    pHead->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;

    std::stack<ListNode*> tempStack;
    ListNode* cur = pHead;
    while(cur != NULL){
        std::cout << cur->val << "  ";
        tempStack.push(cur);
        cur = cur->next;
    }
    std::cout << std::endl;

    //实现链表的倒序输出
    std::vector<int> rVector;
    while(!tempStack.empty()){
        ListNode* temp = tempStack.top();
        tempStack.pop();
        rVector.push_back(temp->val);
    }

    int len = rVector.size();
    for(int i = 0; i < len; ++i){
        std::cout << rVector[i] << "  ";
    }
    std::cout << std::endl;

    return 0;
}