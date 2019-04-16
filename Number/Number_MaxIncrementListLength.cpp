#include <iostream>
#include <bits/stdc++.h>

/*
 * 给定一个数组，求出其中的最长公共子序列长度
 * 从动态规划的角度看，一个较大的父问题被分解为了两个较小的子问题，且父问题和子问题是同一种问题
 * 对于输入序列中的每个元素X，分别找出找出比X小且长度最长的子序列作为左边子序列，以此类推，最后最长的就是最长公共子序列
 * */

int main() {

    std::vector<int> allNum = {1, 5, 2, 14, 10, 3, 8, 41, 6};
    int size = allNum.size();
    std::vector<int> allSize;
    allSize.push_back(1);

    for(int i = 1; i < size; ++i){
        int tempSize = 1;
        for(int j = 0; j < i; ++j){
            if(allNum[j] < allNum[i] && (allSize[j] + 1) > tempSize){
                tempSize = allSize[j] + 1;
            }
        }
        allSize.push_back(tempSize);
    }

    int maxNum = 1;
    for(int i = 1; i < size; ++i){
//        std::cout << allSize[i] << std::endl;
        if(allSize[i] > maxNum){
            maxNum = allSize[i];
        }
    }

    //输出最终结果
    std::cout << "The max increment list length is : " << maxNum << std::endl;

    return 0;
}