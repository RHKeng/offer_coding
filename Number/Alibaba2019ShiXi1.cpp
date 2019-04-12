#include <iostream>
#include <bits/stdc++.h>

/*
 *2019阿里正式批笔试第一题，具体题目见对应图片描述
 * */


int main() {

    int times = 100;
    std::vector<float> allNum = {0.1, 0.2, 0.3, 0.2, 0.5};
    int size = allNum.size();

    float temp = 1.0;
    float finalP = 0.0;
    for(int i = 0; i < times; ++i){
        //代表是小明先
        if(i % 2 == 0){
            for(int j = 0; j < size; ++j){
                if(j % 2 == 0){     //代表是小明的
                    finalP += (temp * allNum[j]);
                    temp = temp * (1 - allNum[j]);
                }else{
                    temp = temp * (1 - allNum[j]);
                }
            }
        }else{
            if(size % 2 == 0){
                for(int j = 0; j < size; ++j){
                    if(j % 2 == 0){     //代表是小明的
                        finalP += (temp * allNum[j]);
                        temp = temp * (1 - allNum[j]);
                    }else{
                        temp = temp * (1 - allNum[j]);
                    }
                }
            }else{
                //代表是小华先
                for(int j = 0; j < size; ++j){
                    if(j % 2 == 1){     //代表是小明的
                        finalP += (temp * allNum[j]);
                        temp = temp * (1 - allNum[j]);
                    }else{
                        temp = temp * (1 - allNum[j]);
                    }
                }
            }
        }
    }

//    int tempNum = finalP * 100000;
//    if(tempNum % 10 >= 5){
//        tempNum = tempNum - (tempNum % 10) + 10;
//    }else{
//        tempNum = tempNum - (tempNum % 10);
//    }
//    float finalCout = (float)tempNum / 100000;

    //四舍五入保留小数点后四位
    std::cout << setiosflags(std::ios::fixed);
    std::cout << std::setprecision(4) << finalP << std::endl;

    return 0;
}