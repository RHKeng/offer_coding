#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于腾讯正式批编程题，题目如下：给定一个数组，每次输出其中最小的数字的，然后其他数字减去该数字，循环输出，数组剩下全部是0，则输出0，结束
 * 解题思路：先对数组进行排序，去重，然后每次输出最小的数字，用一个数字记录减去的总数，避免多次运算
 * */


int main() {

    std::vector<int> allNum = {1, 2, 4, 1, 6, 3, 9, 12, 4, 0, 20, 20, 10};
    int size = allNum.size();

    //尝试先对数组进行排序
    sort(allNum.begin(), allNum.end());

    //尝试去重
    std::vector<int> coutNum;
    coutNum.push_back(allNum[0]);
    int lastNum = allNum[0];
    for(int i = 1; i < size; ++i){
        if(allNum[i] != lastNum){
            coutNum.push_back(allNum[i]);
            lastNum = allNum[i];
        }
    }

    //尝试输出
    int tempSum = 0;
    int coutSize = coutNum.size();

    //输出排序去重后数组
    for(int i = 0; i < coutSize; ++i){
        std::cout << coutNum[i] << std::endl;
    }

    for(int i = 0; i < coutSize; ++i){
        int temp = coutNum[i];
        if((temp - tempSum) != 0){
            std::cout << (temp - tempSum) << std::endl;
            tempSum  = temp;
        }
    }

    return 0;
}