#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于复杂链表的复制算法，可以分三步完成
 * 1.复制后一个节点
 * 2.调整指向任意节点指针
 * 3.拆分成两个链表
 * */

struct ListNode{

    int val;
    ListNode* next;
    ListNode* sibling;
    ListNode(int x):val(x), next(NULL), sibling(NULL){}

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
    pHead1->sibling = temp31;
    temp41->sibling = temp11;
    temp11->sibling = temp51;

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
        //尝试复制后一个节点
        tempNode = pHead1;
        while(tempNode != NULL){
            ListNode* temp = new ListNode(tempNode->val);
            temp->next = tempNode->next;
            tempNode->next = temp;
            tempNode = temp->next;
        }

        //尝试复制指向任意指针
        tempNode = pHead1;
        while(tempNode != NULL){
            if(tempNode->sibling != NULL){
                tempNode->next->sibling = tempNode->sibling->next;
            }
            tempNode = tempNode->next->next;
        }

        //尝试拆分成两个链表
        tempNode = pHead1;
        ListNode* pHead = pHead1->next;
        ListNode* last1 = NULL;
        ListNode* last2 = NULL;
        while(tempNode != NULL){
            if(last1 == NULL){
                last1 = tempNode;
                last2 = tempNode->next;
            }else{
                last1->next = tempNode;
                last2->next = tempNode->next;
                last1 = last1->next;
                last2 = last2->next;
            }
            tempNode = tempNode->next->next;
        }
        last1->next = NULL;
        last2->next = NULL;

        //尝试输出验证结果
        tempNode = pHead1;
        std::cout << "First List : ";
        while(tempNode != NULL){
            std::cout << tempNode->val << "  ";
            tempNode = tempNode->next;
        }
        std::cout << std::endl;
        tempNode = pHead;
        std::cout << "Delete List : ";
        while(tempNode != NULL){
            std::cout << tempNode->val << "  ";
            tempNode = tempNode->next;
        }
        std::cout << std::endl;

        std::cout << pHead->sibling->val << std::endl;

    }

    return 0;
}