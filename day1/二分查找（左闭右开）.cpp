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