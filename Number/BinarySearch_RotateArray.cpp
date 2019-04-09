#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于二分查找的一个例子，寻找旋转数组中的最小值
 * 通常来说，二分查找是考察的重点，主要是要关注边界点
 * */

bool hasNum(int* num, int start, int end, int& foundNum){

    if(start == end){
        if(num[start] != foundNum){
            return false;
        }else{
            return true;
        }
    }else{
        int mid = (start + end) / 2;
        if((num[start] <= foundNum && num[mid] >= foundNum) || (num[start] <= foundNum && num[mid] < num[start]) || (num[mid] >= foundNum &&  num[start] >= num[mid])){
            return hasNum(num, start, mid, foundNum);
        }else{
            return hasNum(num, mid + 1, end, foundNum);
        }
    }

}

int main() {

    int len = 10;
    int num[] = {5, 8, 9, 11, 12, 14, 20, 1, 2, 4};
    int foundNum;
    for(int i = 0; i < len; ++i){
        foundNum = num[i];
        bool found = hasNum(num, 0, len - 1, foundNum);

        if(found){
            std::cout << "Number " << foundNum << " has been found !!" << std::endl;
        }else{
            std::cout << "Number " << foundNum << " has not been found !!" << std::endl;
        }
    }

    foundNum = 7;
    if(hasNum(num, 0, len - 1, foundNum)){
        std::cout << "Number " << foundNum << " has been found !!" << std::endl;
    }else{
        std::cout << "Number " << foundNum << " has not been found !!" << std::endl;
    }

    return 0;
}