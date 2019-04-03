#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于反转链表的题目，需要用到三个指针
 * 目前在面试中经常会被问到思路，以及要求写代码，需要熟练掌握
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
    int k = 10;

    ListNode* cur = pHead;
    while(cur != NULL){
        std::cout << cur->val << "  ";
        cur = cur->next;
    }
    std::cout << std::endl;

    //进行反转链表操作
    ListNode* rPHead = NULL;
    cur = pHead;
    ListNode* pLast = NULL;
    ListNode* pNext = cur->next;
    while(cur != NULL){
        cur->next = pLast;
        pLast = cur;
        cur = pNext;
        if(pNext != NULL){
            pNext = pNext->next;
        }
    }
    rPHead = pLast;

    cur = rPHead;
    while(cur != NULL){
        std::cout << cur->val << "  ";
        cur = cur->next;
    }
    std::cout << std::endl;

    return 0;
}