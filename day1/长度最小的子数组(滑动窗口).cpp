#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdint>

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT32_MAX;
        int sum = 0;       // 滑动窗口的数值之和
        int i = 0;         // 滑动窗口的起始位置
        int sublength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            // 注意这里使用while，每次更新i(起始位置)并不断比较子数组是否符合条件
            while (sum >= target)
            {
                sublength = (j - i + 1); // 获取子数组的长度
                result = result < sublength ? result : sublength;
                // 这里体现滑动窗口的精髓之处，不断变更i（子数组的起始位置）
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
