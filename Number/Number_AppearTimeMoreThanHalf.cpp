#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于查找数组中出现次数大于一半的数字
 * 解题思路：用一个数字存储前面数字出现次数，一个数字存储前面出现最多的那个数字，采用两两抵消的方式，如果当前数字和前面出现的最多数字不一样，则次数减1，否则加1，还要注意times为0的情况
 * */


int main() {

    std::vector<int> allNum = {12, 1, 3, 1, 2, 5, 1, 1, 15, 1, 1};
    int size = allNum.size();

    int finalNum = allNum[0];
    int times = 1;
    for(int i = 1; i < size; ++i){
        if(times == 0){
            ++times;
            finalNum = allNum[i];
        }else{
            if(finalNum == allNum[i]){
                ++times;
            }else{
                --times;
            }
        }
    }

    std::cout << "Appear times more than 1/2 number is : " << finalNum << std::endl;

    return 0;
}