#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，堆排序，是一个不稳定的排序算法，时间复杂度是O（n log n）
 * 空间复杂度，因为不需要额外数组存储中间结果，只需要在原数组建堆
 * 通常来说，都是在数量比较大的情况下才会考虑堆排序
 * 堆排序相对来说，在面试的时候问得不多，但是也会问到思路，也有可能会被叫到写代码
 * */

void Change(int num[], int a, int b){
    int temp = num[b];
    num[b] = num[a];
    num[a] = temp;
}

//堆调整
void HeapAdjust(int* data, int s, int m){

    int j, temp;
    temp = data[s];
    for(j = 2 * s + 1; j <= m; j = 2 * j + 1){
        if(j <= m - 1 && data[j] < data[j + 1]){
            ++j;
        }
        if(temp > data[j]){
            break;
        }
        data[s] = data[j];
        s = j;
    }
    data[s] = temp;
}

//堆排序
void HeapSort(int* data, int n){

    int i;

    //调整堆，建堆为最大堆
    for(i = n / 2 - 1; i >= 0; --i){
        HeapAdjust(data, i, n);
    }

    //开始堆排序
    for(i = n - 1; i > 0; --i){
        Change(data, 0, i);
        HeapAdjust(data, 0, i - 1);
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

    // 堆排序
    HeapSort(num, len);

    std::cout<< "~~~~~~~~~~~~排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    return 0;
}