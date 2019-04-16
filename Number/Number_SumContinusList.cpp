#include <iostream>
#include <bits/stdc++.h>

/*
 * 输入一个正数s，打印出所有和为s的连续正数序列（至少包含两个数）
 * 同样采用两个指针来完成，一前一后，并用一个数来存储临时的和
 * */

void PrintNum(int small, int big){
    for(int i = small; i <= big; ++i){
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}

int main() {

    int s = 15;

    //由于至少得两个数字，则index的最小值不会超过s的一半
    int middle = (1 + s) / 2;
    int small = 1;
    int big = 2;
    int tempSum = small + big;

    while(small < middle){
        if(tempSum == s){
            PrintNum(small, big);
        }

        while(tempSum > s && small < middle && small < big){
            tempSum -= small;
            ++small;

            if(tempSum == s){
                PrintNum(small, big);
            }
        }

        ++big;
        tempSum += big;

    }

    return 0;
}