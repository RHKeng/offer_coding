#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于查找数组中出现次数大于三分之一的数字，解题思路与寻找出现次数大于二分之一的数字类似
 * 解题思路：用两个数字存储前面数字出现次数，两个数字存储前面出现最多的两个数字，采用抵消的方式
 * 如果当前数字和前面出现的那两个数字不一样，则次数都减1，否则对应的加1，还要注意times为0的情况
 * */


int main() {

    std::vector<int> allNum = {12, 3, 2, 5, 1, 15, 1, 1, 1, 1, 3, 3, 3};
    int size = allNum.size();

    int finalNum1 = allNum[0];
    int finalNum2 = allNum[1];
    int times1 = 1;
    int times2 = 1;
    for(int i = 2; i < size; ++i){
        if(times1 == 0 || times2 == 0){
            if(times1 == 0){
                if(finalNum2 != allNum[i]){
                    ++times1;
                    finalNum1 = allNum[i];
                }else{
                    ++times2;
                }
            }else{
                if(finalNum1 != allNum[i]){
                    ++times2;
                    finalNum2 = allNum[i];
                }else{
                    ++times1;
                }
            }
        }else{
            if(finalNum1 == allNum[i]){
                ++times1;
            }else{
                if(finalNum2 == allNum[i]){
                    ++times2;
                }else{
                    --times1;
                    --times2;
                }
            }
        }
    }

    int finalNum;
    if(times1 >= times2){
        finalNum = finalNum1;
    }else{
        finalNum = finalNum2;
    }

    std::cout << finalNum1 << std::endl;
    std::cout << finalNum2 << std::endl;
    std::cout << times1 << std::endl;
    std::cout << times2 << std::endl;

    std::cout << "Appear times more than 1/3 number is : " << finalNum << std::endl;

    return 0;
}