#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，快速排序，是一个不稳定的排序算法，在每次从中间抽取index的时候，复杂度是O（n log n），在每次都是抽取两边的时候复杂度是O（n * n），平均时间复杂度是O（n log n）
 * 空间复杂度，因为递归参数传递而产生，最好情况是O（log n），最差情况是O（n）
 * 通常来说，都是在数量比较大的情况下才会考虑快速排序
 * 快速排序，在面试过程中很大可能会被问到思路以及写代码，所以需要熟练掌握，也有可能会叫你采用非递归的方式实现
 * */

//产生随机数函数
int Random(int a, int b){
    int random = ((rand() % (b - a + 1)) +  a);
    return random;
}

void Change(int num[], int a, int b){
    int temp = num[b];
    num[b] = num[a];
    num[a] = temp;
}

//Partition函数，用来实现局部排序功能
int Partition(int num[], int start, int end){

    if(start >= end){
        return end;
    }

    int index = Random(start, end);
//    int index = (start + end) / 2;
    int last = start - 1;
    Change(num, index, end);
    for(int i = start; i < end; ++i){
        if(num[i] < num[end]){
            ++last;
            if(last != i){
                Change(num, last, i);
            }
        }
    }
    ++last;
    Change(num, last, end);
    return last;

}

//首先实现递归方式
void QuickSort(int num[], int start, int end){

    int index = Partition(num, start, end);
    if(index > start){
        QuickSort(num, start, index - 1);
    }
    if(index < end){
        QuickSort(num, index + 1, end);
    }

}

//实现非递归方式
void QuickSortF(int num[], int start, int end){

    std::stack<int> stackStart;
    std::stack<int> stackEnd;
    stackStart.push(start);
    stackEnd.push(end);
    while(!stackStart.empty() && !stackEnd.empty()){
        int tempStart = stackStart.top();
        int tempEnd = stackEnd.top();
        stackStart.pop();
        stackEnd.pop();
        int index = Partition(num, tempStart, tempEnd);
        if(index > tempStart){
            stackStart.push(tempStart);
            stackEnd.push(index - 1);
        }
        if(index < tempEnd){
            stackStart.push(index + 1);
            stackEnd.push(tempEnd);
        }
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

    // 递归快速排序
    QuickSort(num, 0, len - 1);

    std::cout<< "~~~~~~~~~~~~递归排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    int num1[7] = {2, 1, 8, 9, 0, 7, 6};
    // 非递归快速排序
    QuickSortF(num1, 0, len - 1);

    std::cout<< "~~~~~~~~~~~~非递归排序后~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num1[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    return 0;
}