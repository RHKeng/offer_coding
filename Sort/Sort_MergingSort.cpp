#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，归并排序，是一个稳定的排序算法，时间复杂度是O（n log n）
 * 空间复杂度，因为需要另一个数组存储，所以是O（n）
 * 通常来说，都是在数量比较大的情况下才会考虑归并排序
 * 归并排序，在面试过程中很大可能会被问到思路以及写代码，所以需要熟练掌握，或者统计数组里面的逆序数对的时候也可以采用归并
 * */

//归并排序
void MergingSort(int* data, int* copy, int start, int end){

    if(start == end){
        copy[start] = data[start];
        return;
    }

    int length = (end - start) / 2;
    MergingSort(copy, data, start, start + length);
    MergingSort(copy, data, start + length + 1, end);

    int i = start;
    int j = start + length + 1;
    int index = i;
    while(i <= (start + length) && j <= end){
        if(data[i] <= data[j]){
            copy[index] = data[i];
            ++i;
            ++index;
        }else{
            copy[index] = data[j];
            ++j;
            ++index;
        }
    }

    for(; i <= start + length; ++i){
        copy[index++] = data[i];
    }

    for(; j <= end; ++j){
        copy[index++] = data[j];
    }

}

int main() {

    int num[7] = {2, 1, 8, 9, 0, 7, 6};
    int len = 7;

    std::cout<< "~~~~~~~~~~~~排序前~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    // 归并排序
    int* copy = new int[len];
    for(int i = 0; i < len; ++i){
        copy[i] = num[i];
    }
    MergingSort(num, copy, 0, len - 1);

    //排序完，最终的数组是copy

    std::cout<< "~~~~~~~~~~~~排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << copy[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    return 0;
}