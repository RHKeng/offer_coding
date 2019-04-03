#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于输出链表的倒数第k个节点的值，利用两个指针来完成
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
    int k = 1;

    ListNode* cur = pHead;
    ListNode* pre = pHead;
    bool isValid = true;
    for(int i = 0; i < k; ++i){
        if(pre == NULL){
            isValid = false;
            break;
        }
        pre = pre->next;
    }

    if(isValid){
        while(pre != NULL){
            pre = pre->next;
            cur = cur->next;
        }
        std::cout << cur->val <<std::endl;
    }else{
        std::cout << "Invalid input k !!!" <<std::endl;
    }

    return 0;
}