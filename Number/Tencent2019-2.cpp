#include <iostream>
#include <bits/stdc++.h>

/*
 * 关于腾讯正式批编程题，题目如下：给定一个数组，数组内的数字代表需要的材料数量，所有数量总和为0，正数代表多出来可以运到别处，负数代表需要从别的地方运材料过来，求运送材料最短路径
 * 解题思路：贪心算法，从头开始遍历数组，用一个数字来存储到目前数字的总和，代表使该点为0所需能量，每次叠加该数字的绝对值作为最终输出
 * */


int main() {

    std::vector<int> allNum = {1, 5, -3, -2, -1, 4, -1, -3};
    int size = allNum.size();

    int tempSum = 0;
    int needSum = 0;
    for(int i = 0; i < size; ++i){
        tempSum += allNum[i];
        needSum += abs(tempSum);
    }

    std::cout << "All need is : " << needSum << std::endl;

    return 0;
}