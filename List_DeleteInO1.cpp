#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于在O（1）时间复杂度内删除链表一个节点的算法，可以尝试将该节点后一个节点删除
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

    ListNode* tempNode = pHead;
    while(tempNode != NULL){
        std::cout << tempNode->val << "  ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;

    ListNode* toBeDeleteNode = temp3;
    //将待删除节点的后一个节点的值赋给待删除节点，然后删除后一个节点
    if(toBeDeleteNode->next == NULL){
        toBeDeleteNode = NULL;
    }else{
        ListNode* nextNode = toBeDeleteNode->next;
        toBeDeleteNode->val = nextNode->val;
        toBeDeleteNode->next = nextNode->next;
        delete nextNode;
    }

    //输出结果验证算法
    tempNode = pHead;
    while(tempNode != NULL){
        std::cout << tempNode->val << "  ";
        tempNode = tempNode->next;
    }
    std::cout << std::endl;

    return 0;
}