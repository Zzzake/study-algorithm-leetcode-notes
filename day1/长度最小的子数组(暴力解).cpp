#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdint>

//暴力解
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0; // 窗口内元素的总和
        int i = 0;   // 窗口的起始位置（左边界）

        // j 是窗口的结束位置（右边界）
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];

            // 注意这里使用的是 while，因为左边界可能需要向右移动多次
            while (sum >= target)
            {
                int subLength = j - i + 1;                        // 计算当前窗口长度
                result = result < subLength ? result : subLength; // 更新最小值

                sum -= nums[i]; // 缩减窗口，减去左侧元素
                i++;            // 左边界右移
            }
        }

        // 如果 result 没变，说明没有符合条件的子数组，返回 0
        return result == INT32_MAX ? 0 : result;
    }
};