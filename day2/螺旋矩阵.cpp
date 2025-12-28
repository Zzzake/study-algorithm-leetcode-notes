#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2;           // 每个圈循环几次，如果n为奇数3
                                    // 那么loop=1,只是循环一圈
        int mid = n / 2;            // 矩阵中间的位置，例如：n为3，中间的位置就是（1,1）
        int count = 1;              // 用来给矩阵中每个空格位置赋值
        int offset = 1;             // 每一圈循环都需要控制每一条边的遍历长度
        int i, j;
        // 开始转圈填充
        while (loop--)
        {
            i = startx;
            j = starty;

            // 从下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右（左闭右开）
            for (j = starty; j < starty + n - offset; j++)
            {
                res[startx][j] = count++;
            }
            // 模拟填充左列从上到下（左闭右开）
            for (i = startx; i < startx + n - offset; i++)
            {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左（左闭右开）
            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上（左闭右开）
            for (; i > startx; i--)
            {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始的位置要各自加1
            // 例如，第一圈的起始位置是(0.0),第二圈的起始位置是（1,1）
            startx++;
            starty++;

            // offset 用于控制每一圈中每一条边遍历的长度

            offset += 2;
        }

        // 如果n为奇数，则需要单独为矩阵最中间的位置赋值
        if (n % 2)
        {
            res[mid][mid] = count;
        }
        return res;
    }
};