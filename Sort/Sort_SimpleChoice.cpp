#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，简单的直接选择排序，时间复杂度都是O（n * n），是一个不稳定的排序算法，有可能排序过后两个相等元素的相对位置发生改变
 * 通常来说，都是在数量比较少的情况下才会考虑简单选择排序
 * */

int main() {

    int num[7] = {2, 1, 8, 9, 0, 7, 11};
    int len = 7;

    std::cout<< "~~~~~~~~~~~~排序前~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    //简单选择排序
    for(int i = 0; i < len - 1; ++i){
        int min = num[i];
        int minIndex = i;
        for(int j = i + 1; j < len; ++j){
            if(num[j] < min){
                min = num[j];
                minIndex = j;
            }
        }
        num[minIndex] = num[i];
        num[i] = min;
    }

    std::cout<< "~~~~~~~~~~~~排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    return 0;
}