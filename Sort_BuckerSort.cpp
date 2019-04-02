#include <iostream>
#include <bits/stdc++.h>

/*
 * 排序算法，桶排序，时间复杂度是O（n ）
 * 空间复杂度O（n ）
 * 桶排序相对来说，在面试的时候问得不多，但是也会问到思路，典型题目如下：
 * 给你个非负整数的无序数组，求数组排序后，相邻数字的最大间隔是多少
 * */

void Change(int num[], int a, int b){
    int temp = num[b];
    num[b] = num[a];
    num[a] = temp;
}

//尝试得到最大差值
int getMaxDelta(int* num, const int len){
    const int length = len + 1;
    int data[length][2];
    //初始化
    for(int i = 0; i < length; ++i){
        data[i][0] = -1;
        data[i][1] = -1;
    }

    int max_num = num[0];
    int min_num = num[0];
    //找出数组里面的最大值和最小值
    for(int i = 1; i < len; ++i){
        if(num[i] > max_num){
            max_num = num[i];
        }
        if(num[i] < min_num){
            min_num = num[i];
        }
    }

    double delta = ((double)(max_num - min_num) / length);
    for(int i = 0; i < len; ++i){
        int tempNum = num[i];
        int index = (tempNum - min_num) / delta - 1;
        if(data[index][0]  == -1){
            data[index][0] = tempNum;
        }else{
            if(data[index][0] > tempNum){
                data[index][0] = tempNum;
            }
        }
        if(data[index][1] < tempNum){
            data[index][1] = tempNum;
        }
    }

    int max_delta = 0;
    int last_max = data[0][1];
    for(int i = 0; i < length; ++i){
        if(last_max != -1){
            if(data[i][0] != -1){
                if(data[i][0] - last_max > max_delta){
                    max_delta = data[i][0] - last_max;
                }
                last_max = data[i][1];
            }
        }else{
            last_max = data[i][1];
        }

    }

//    for(int i = 0; i < length; ++i){
//        std::cout << data[i][0] << " " << data[i][1] << std::endl;
//    }

    return max_delta;
}

int main() {

    int num[8] = {2, 1, 8, 15, 0, 7, 6, 13};
    int len = 8;

    std::cout<< "~~~~~~~~~~~~排序前~~~~~~~~~~~~" << std::endl;
    for(int i = 0; i < len; ++i){
        std::cout << num[i];
        std::cout << "  ";
    }
    std::cout << std::endl;

    // 得到排序后的最大差值
    int max_delta = getMaxDelta(num, len);
    std::cout << "排序后最大差值是 ： " << max_delta << std::endl;

    return 0;
}