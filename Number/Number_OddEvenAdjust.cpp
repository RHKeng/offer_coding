#include <iostream>
#include <bits/stdc++.h>

/*
 * 给定一个整型数组，调整数组，使得所有的奇数都在偶数前面
 * 可以采用两个指针，一头一尾，来遍历完成
 * */

int main() {

    int allNum[] = {1, -2, 2, -5, 3, 6};
    int size = 6;

    int pre = size - 1;
    int aft = 0;
    while(pre > aft){
        if(allNum[pre] % 2 != 0){
            if(allNum[aft] % 2 == 0){
                int temp = allNum[pre];
                allNum[pre] = allNum[aft];
                allNum[aft] = temp;
                ++aft;
                --pre;
            }else{
                ++aft;
            }
        }else{
            --pre;
            if(allNum[aft] % 2 != 0){
                ++aft;
            }
        }
    }

    //输出校验结果
    for(int i = 0; i < size; ++i){
        std::cout << allNum[i] << "  ";
    }
    std::cout << std::endl;

    //尝试不改变数组中奇数和偶数的相对位置
    int allNum1[] = {1, -2, 2, -5, 3, 6};

    //采用直接插入的方式
    int lastOddIndex = -1;
    for(int i = 0; i < size; ++i){
        if(allNum1[i] % 2 != 0){
            ++lastOddIndex;
            for(int j = i; j > lastOddIndex; --j){
                int temp = allNum1[j];
                allNum1[j] = allNum1[j - 1];
                allNum1[j - 1] = temp;
            }
        }
    }

    //输出校验结果
    for(int i = 0; i < size; ++i){
        std::cout << allNum1[i] << "  ";
    }
    std::cout << std::endl;

    return 0;
}