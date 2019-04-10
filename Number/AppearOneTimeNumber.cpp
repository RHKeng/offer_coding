#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于查找数组中只出现一次的数字算法，其他数字均出现了两次
 * 解题思路：采用位运算方法来做，时间复杂度O（n），异或来消除出现两次的数字
 * */


int main() {

    std::vector<int> allNum = {1, 2, 3, 1, 2, 5, -1, -1, 5};
    int size = allNum.size();

    int finalNum = allNum[0];
    for(int i = 1; i < size; ++i){
        finalNum = finalNum ^ allNum[i];
    }

    std::cout << "Appear one time number is : " << finalNum << std::endl;

    return 0;
}