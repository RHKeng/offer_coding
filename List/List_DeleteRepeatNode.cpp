#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于删除链表中重复出现节点算法
 * */

struct ListNode{

    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}

};

int main() {

    ListNode* pHead1 = new ListNode(0);
    ListNode* temp11 = new ListNode(0);
    ListNode* temp21 = new ListNode(5);
    ListNode* temp31 = new ListNode(9);
    ListNode* temp41 = new ListNode(14);
    ListNode* temp51 = new ListNode(20);
    ListNode* temp61 = new ListNode(20);
    pHead1->next = temp11;
    temp11->next = temp21;
    temp21->next = temp31;
    temp31->next = temp41;
    temp41->next = temp51;
    temp51->next = temp61;

    ListNode* tempNode = pHead1;
    std::cout << "First List : ";
    while(tempNode != NULL){
        std::cout << tempNode->val << "  ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;

    if(pHead1 == NULL){
        return 0;
    }else{
        //尝试删除链表中重复节点
        ListNode* pHead = NULL;
        ListNode* lastNode = NULL;
        ListNode* aft = pHead1;
        ListNode* pre = pHead1->next;
        while(pre != NULL && aft != NULL){
            if(pre->val == aft->val){
                while(pre != NULL && pre->val == aft->val){
                    pre = pre->next;
                }
                if(pre == NULL){
                    break;
                }else{
                    aft = pre;
                    pre = pre->next;
                }
            }else{
                if(pHead == NULL){
                    pHead = aft;
                    lastNode = aft;
                    aft = pre;
                    pre = pre->next;
                }else{
                    lastNode->next = aft;
                    lastNode = aft;
                    aft = pre;
                    pre = pre->next;
                }
            }
        }
        if(lastNode != NULL && aft != NULL && aft->next == NULL){
            lastNode->next = aft;
        }else{
            lastNode->next = NULL;
        }

        //尝试输出验证结果
        tempNode = pHead;
        std::cout << "Delete List : ";
        while(tempNode != NULL){
            std::cout << tempNode->val << "  ";
            tempNode = tempNode->next;
        }
        std::cout << std::endl;

    }

    return 0;
}