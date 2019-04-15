#include <iostream>
#include <bits/stdc++.h>

/*
 * 给定一个递增的整型数组，在数组中查找所有和为s的两个数的组合输出
 * 可以采用两个指针，一头一尾，来遍历完成
 * */

int main() {

    int s = 5;
    int allNum[] = {0, 1, 2, 3, 3, 5};
    int size = 6;

    int pre = size - 1;
    int aft = 0;
    while(pre > aft){
        int tempSum = allNum[aft] + allNum[pre];
        if(tempSum == s){
            int preNum = 1;
            int aftNum = 1;
            while(pre > 0 && allNum[pre] == allNum[pre - 1]){
                ++preNum;
                --pre;
            }
            while(aft < size - 1 && allNum[aft] == allNum[aft + 1]){
                ++aftNum;
                ++aft;
            }
            int num = preNum * aftNum;
            for(int i = 0; i < num; ++i){
                std::cout << allNum[aft] << " + " << allNum[pre] << " = " << s << std::endl;
            }
            --pre;
            ++aft;
        }else{
            if(tempSum > s){
                --pre;
            }else{
                ++aft;
            }
        }
    }

    return 0;
}