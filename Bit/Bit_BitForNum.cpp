#include <iostream>
#include <bits/stdc++.h>

/*
 * 题目是腾讯面试中被问到思路的一道题：给定一个整数N（N是大数），随机产生10个0到N的随机数
 * 可以采用位运算的思路来解决大数问题，先得到N的最大位数，然后产生最大位数对应个数的0和1来表示大数
 * */

int getRandom(int numBits, int N){
    int finalNum = 0;
    for(int i = 0; i < numBits; ++i){
        int temp = rand() % 2;
        finalNum = finalNum + pow(2, i) * temp;
    }
    if(finalNum > N){
        return -1;
    }else{
        return finalNum;
    }
}

int main() {

    int N = 12658;
    int num = 20;

    //首先尝试得到最大位数
    int numBits = 0;
    int temp = N;
    while(temp != 0){
        ++numBits;
        temp = temp >> 1;
    }

    for(int i = 0; i < num; ++i){
        int tempNum = getRandom(numBits, N);
        while(tempNum == -1){
            tempNum = getRandom(numBits, N);
        }
        std::cout << "The " << i + 1 << "'th num : " << tempNum << std::endl;
    }

    return 0;
}