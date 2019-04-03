#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于查找链表中是否存在环的问题，可通过一快一慢两个指针来完成
 * 目前在面试中还没看到有被问到
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
    temp5->next = temp3;

    bool hasCircle = false;
    ListNode* aft = pHead;
    ListNode* pre = pHead;
    while(pre->next != NULL && pre->next->next != NULL){
        aft = aft->next;
        pre = pre->next->next;
        if(aft == pre){
            hasCircle = true;
            break;
        }
    }

    if(hasCircle){
        std::cout << "List has circle !!!" << std::endl;
    }else{
        std::cout << "List has not circle !!!" << std::endl;
    }

    return 0;
}