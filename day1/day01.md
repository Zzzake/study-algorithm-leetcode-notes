# 1.二分查找

## 1.情况1：左闭右闭

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else 
                return mid;
        }
        return -1;
    

    }

};
```

## 2.情况2：左闭右开

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size(); // 右开：指向越界后的第一个位置
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = left;
            }
            else
                return mid;
        }
        return -1;
    }
};
```



# 2.移除元素

## 1.常规方法

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[j];
                j--;
            }
            else
            {
                i++;
            }
        }

        return j + 1;
    }

};
```

## 2.双指针法

```c++
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    // 双指针法
    int removeElement(vector<int> &nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex])
            {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
```

# 3：长度最小的子数组

## 1：暴力解

```c++
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
```

## 2：滑动窗口

```
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
```