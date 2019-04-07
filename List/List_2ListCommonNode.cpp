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
    temp52->next = temp31;

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

    //先得到两个链表的长度
    int listLen1 = 0;
    int listLen2 = 0;
    tempNode = pHead1;
    while(tempNode != NULL){
        ++listLen1;
        tempNode = tempNode->next;
    }
    tempNode = pHead2;
    while(tempNode != NULL){
        ++listLen2;
        tempNode = tempNode->next;
    }

    int len = 0;
    ListNode* temp1 = pHead1;
    ListNode* temp2 = pHead2;
    if(listLen1 > listLen2){
        len = listLen1 - listLen2;
        for(int i = 0; i < len; ++i){
            temp1 = temp1->next;
        }
    }else{
        len = listLen2 - listLen1;
        for(int i = 0; i < len; ++i){
            temp2 = temp2->next;
        }
    }

    //尝试得到公共节点
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    //验证结果
    std::cout << "Common node value : " << temp1->val << std::endl;

    return 0;
}