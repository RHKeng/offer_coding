#include <iostream>
#include <bits/stdc++.h>

/*
 * 给定一个排序数组，统计一个数字在当中出现的次数，并输出
 * 可以用二分查找的思路来解决这个问题，分别用二分查找寻找排序数组中第一个和最后一个该数字出现的index
 * */

int getFirstIndex(std::vector<int> &allNum, int start, int end, int &num){

    if(start > end){
        return -1;
    }

    int middleIndex = (start + end) / 2;
    int tempData = allNum[middleIndex];

    if(tempData == num){
        if(middleIndex > 0 && allNum[middleIndex - 1] != num || middleIndex == 0){
            return middleIndex;
        }else{
            end = middleIndex - 1;
        }
    }else{
        if(tempData > num){
            end = middleIndex - 1;
        }else{
            start = middleIndex + 1;
        }
    }

    return getFirstIndex(allNum, start, end, num);

}

int getLastIndex(std::vector<int> &allNum, int start, int end, int &num){

    if(start > end){
        return -1;
    }

    int middleIndex = (start + end) / 2;
    int tempData = allNum[middleIndex];

    if(tempData == num){
        if(middleIndex < end && allNum[middleIndex + 1] != num || middleIndex == end){
            return middleIndex;
        }else{
            start = middleIndex + 1;
        }
    }else{
        if(tempData > num){
            end = middleIndex - 1;
        }else{
            start = middleIndex + 1;
        }
    }

    return getLastIndex(allNum, start, end, num);

}

int main() {

    std::vector<int> allNum = {1, 5, 2, 14, 10, 3, 8, 41, 6, 5, 1, 5, 5};
    int size = allNum.size();
    int target = 5;

    //先对数组进行排序
    std::sort(allNum.begin(), allNum.end());

    int firstIndex = getFirstIndex(allNum, 0, size - 1, target);
    int lastIndex = getLastIndex(allNum, 0, size - 1, target);
    int times = lastIndex - firstIndex + 1;

    //输出最终结果
    std::cout << "The times number " << target << " appears is : " << times << std::endl;

    return 0;
}