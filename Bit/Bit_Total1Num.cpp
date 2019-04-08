#include <iostream>
#include <bits/stdc++.h>

/*
 * 开始统计一个数字二进制中1出现的个数
 * 可以通过移位来完成，注意到数字二进制中负数向右移位，高位是补1的，所以不能在原数字移位
 * 为此，可以讲标志位1不断往左移位运算的方式代替
 * */

int main() {

    int num = 3;
    int totalBits = 0;
    unsigned int flag = 1;
    while(flag){
        if(flag & num){
            ++totalBits;
        }
        flag = flag << 1;
    }

    std::cout << "Total 1 bits : " << totalBits << std::endl;

    //另一种解法：将原数字减1再与原数字做与运算，可以使得原数字最右边的一个1变为0
    int n = 3;
    totalBits = 0;
    while(n){
        ++totalBits;
        n = (n - 1) & n;
    }

    std::cout << "Total 1 bits : " << totalBits << std::endl;
    
    return 0;
}