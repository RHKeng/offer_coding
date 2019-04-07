#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于合并两个有序链表的算法，用两个指针分别在两个链表，往前移动
 * */

struct ListNode{

    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}

};

int main() {

    ListNode* pHead1 = new ListNode(0);
    ListNode* temp11 = new ListNode(1);
    ListNode* temp21 = new ListNode(5);
    ListNode* temp31 = new ListNode(9);
    ListNode* temp41 = new ListNode(14);
    ListNode* temp51 = new ListNode(20);
    pHead1->next = temp11;
    temp11->next = temp21;
    temp21->next = temp31;
    temp31->next = temp41;
    temp41->next = temp51;

    ListNode* pHead2 = new ListNode(3);
    ListNode* temp12 = new ListNode(4);
    ListNode* temp22 = new ListNode(7);
    ListNode* temp32 = new ListNode(12);
    ListNode* temp42 = new ListNode(29);
    ListNode* temp52 = new ListNode(60);
    pHead2->next = temp12;
    temp12->next = temp22;
    temp22->next = temp32;
    temp32->next = temp42;
    temp42->next = temp52;

    ListNode* tempNode = pHead1;
    std::cout << "First List : ";
    while(tempNode != NULL){
        std::cout << tempNode->val << "  ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;
    tempNode = pHead2;
    std::cout << "Second List : ";
    while(tempNode != NULL){
        std::cout << tempNode->val << "  ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;

    //合并两个有序链表
    ListNode* finalPHead = NULL;
    if(pHead1 == NULL){
        finalPHead = pHead2;
    }else{
        if(pHead2 == NULL){
            finalPHead = pHead1;
        }else{
            ListNode* list1 = pHead1;
            ListNode* list2 = pHead2;
            ListNode* lastNode = NULL;
            while(list1 != NULL && list2 != NULL){
                if(list1->val <= list2->val){
                    if(finalPHead == NULL){
                        finalPHead = list1;
                        lastNode = list1;
                        list1 = list1->next;
                    }else{
                        lastNode->next = list1;
                        lastNode = lastNode->next;
                        list1 = list1->next;
                    }
                }else{
                    if(finalPHead == NULL){
                        finalPHead = list2;
                        lastNode = list2;
                        list2 = list2->next;
                    }else{
                        lastNode->next = list2;
                        lastNode = lastNode->next;
                        list2 = list2->next;
                    }
                }
            }
            if(list1 != NULL){
                lastNode->next = list1;
            }
            if(list2 != NULL){
                lastNode->next = list2;
            }
        }
    }

    //验证结果
    tempNode = finalPHead;
    std::cout << "Final List : ";
    while(tempNode != NULL){
        std::cout << tempNode->val << "  ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;

    return 0;
}