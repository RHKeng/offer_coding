#include <iostream>
#include <bits/stdc++.h>

/*
 * 给定一个整型数组，寻找里面最小的k个数
 * 对于数据量比较小且允许修改原数组数据的情况下，可以采用快排中的partition函数，当partition返回的index刚好是k时数组前k个数字就是最小的k个数，时间复杂度是O（n）
 * 对于数据量比较大的情况，可以采用一个最大堆来存储当前最小的k个数，对于后面的数字都进行堆调整，时间复杂度是O（n log k）
 * 面试中经常会涉及到大数据那块
 * */

//首先尝试用partition函数解决问题
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

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator setIterator;

//大数据情况
void GetLeastNumbers(const std::vector<int>& data, intSet& leastNumbers, int k){

    leastNumbers.clear();

    if(k < 1 || (data.size() < k)){
        return;
    }

    std::vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); ++iter){
        if((leastNumbers.size()) < k){
            leastNumbers.insert(*iter);
        }else{
            setIterator iterGreatest = leastNumbers.begin();
            if(*iter < *(leastNumbers.begin())){
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }

}

int main() {

    int k = 3;
    int allNum[] = {1, -2, 3, 2, -5, 3, 6};
    int size = 7;

    int index = Partition(allNum, 0, size - 1);
    int start = 0;
    int end = size - 1;
    int realK = k - 1;
    while(index != realK){
        if(index > realK){
            end = index;
            index = Partition(allNum, start, end);
        }else{
            start = index;
            index = Partition(allNum, start, end);
        }
    }

    //开始验证partition函数效果
    for(int i = 0; i < k; ++i){
        std::cout << allNum[i] << "  ";
    }
    std::cout << std::endl;

    //下面开始数据量很大的情况
    std::vector<int> dataNum = {1, -2, 3, 2, -5, 3, 6};
    intSet leastNumbers;
    GetLeastNumbers(dataNum, leastNumbers, k);
    setIterator iter = leastNumbers.begin();
    while(iter != leastNumbers.end()){
        std::cout << *iter << "  ";
        ++iter;
    }
    std::cout << std::endl;

    return 0;
}