#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，冒泡排序，在排好序情况下时间复杂度是O（n），在逆序情况时间复杂度是O（n * n），是一个稳定的排序算法
 * 通常来说，都是在数量比较少的情况下才会考虑冒泡排序
 * 冒泡排序，相对来说，在面试时经常会被要求coding或者回答思路，主要是要回答好冒泡的过程，以及flag的作用
 * */

int main() {

    int num[7] = {2, 1, 8, 9, 0, 7, 6};
    int len = 7;

    std::cout<< "~~~~~~~~~~~~排序前~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    //冒泡排序
    bool flag = true;
    for(int i = 0; (i < len - 1 && flag); ++i){
        flag = false;
        for(int j = len - 1; j > i; --j){
            if(num[j] < num[j - 1]){
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
                flag = true;
            }
        }
    }

    std::cout<< "~~~~~~~~~~~~排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    return 0;
}