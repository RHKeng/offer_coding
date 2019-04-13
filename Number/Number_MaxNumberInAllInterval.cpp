#include <iostream>
#include <bits/stdc++.h>

/*
 *给定一个整型数组，里面有正数和负数，需要求出里面所有连续子数组和的最大值，时间复杂度为O（n）
 * 采用滑窗方法不断往前，用一个tempSum记录前面连续子数组的最大和
 * */


int main() {

    std::vector<int> allNum = {1, -2, 3, 2, -5, 3, 6};
    int size = allNum.size();

    int tempSum = allNum[0];
    int maxSum = allNum[0];
    for(int i = 1; i < size; ++i){
        if(tempSum < 0){
            tempSum = allNum[i];
        }else{
            tempSum += allNum[i];
        }
        if(tempSum > maxSum){
            maxSum = tempSum;
        }
    }

    //输出最终结果
    std::cout << "The max number in all interval is : " << maxSum << std::endl;

    return 0;
}