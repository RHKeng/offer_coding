#include <iostream>
#include <bits/stdc++.h>

/*
 *2019抖音视频面coding题目，给定一个数组，以及区间长度t，输出所有连续长度为3区间的和
 * 采用滑动方式求和，用tempSum存储临时的和
 * */


int main() {

    int t = 3;
    std::vector<int> allNum = {1, 2, 3, 2, 5};
    int size = allNum.size();

    std::vector<int> allSum;
    int tempSum = 0;
    int lastIndex = 0;
    for (int i = 0; i < size; ++i) {
        if(i >= t){
            tempSum -= allNum[lastIndex];
            tempSum += allNum[i];
            ++lastIndex;
            allSum.push_back(tempSum);
        }else{
            if(i < t - 1){
                tempSum += allNum[i];
            }else{
                tempSum += allNum[i];
                allSum.push_back(tempSum);
            }
        }
    }

    //输出结果
    int sumSize = allSum.size();
    for(int i = 0; i < sumSize; ++i){
        std::cout << allSum[i] << "  ";
    }

    return 0;
}