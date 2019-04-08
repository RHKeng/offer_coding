#include <iostream>
#include <bits/stdc++.h>

/*
 * 不用急加减乘除做加法，考虑采用位运算来解决这个问题
 * 两个数取异或，得到sum，两个数取与，得到进位carry，然后把sum和carry赋值给那两个数，重复迭代，直到carry为0为止
 * */

int add(int num1, int num2){
    int sum, carry;
    do{
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }while(num2 != 0);

    return sum;

}

int main() {

    int num1 = 3;
    int num2 = 17;

    int sum = add(num1, num2);

    std::cout << num1 << " + " << num2 << " = "<< sum << std::endl;

    return 0;
}