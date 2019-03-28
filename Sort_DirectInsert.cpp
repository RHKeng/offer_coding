#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，直接插入排序，在排好序情况下时间复杂度是O（n），在逆序情况时间复杂度是O（n * n），是一个稳定的排序算法
 * 通常来说，都是在数量比较少的情况下才会考虑直接插入排序
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

    //直接插入排序
    for(int i = 0; i < len - 1; ++i){
        int insert = num[i + 1];
        int index = 0;
        for(int j = i; j >= 0; --j){
            if(num[j] <= insert){
                index = j + 1;
                break;
            }else{
                num[j + 1] = num[j];
            }
        }
        num[index] = insert;
    }

    std::cout<< "~~~~~~~~~~~~排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    return 0;
}