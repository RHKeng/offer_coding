#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于查找链表中是否环的入口节点算法，可以先通过一快一慢指针得到环的长度，然后再通过两个指针得到环的入口节点
 * 在面试中也有可能会被问到，而且相对来说比较复杂
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

    //先判断链表是否存在环
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

        //尝试得到环的长度
        int circleLen = 1;
        ListNode* temp = pre->next;
        while(aft != temp){
            ++circleLen;
            temp = temp->next;
        }

        //尝试得到环的入口节点
        aft = pHead;
        pre = pHead;
        for(int i = 0; i <circleLen; ++i){
            pre = pre->next;
        }
        while(pre != aft){
            aft = aft->next;
            pre = pre->next;
        }

        std::cout << pre->val << std::endl;

    }else{
        std::cout << "List has not circle !!!" << std::endl;
    }

    return 0;
}