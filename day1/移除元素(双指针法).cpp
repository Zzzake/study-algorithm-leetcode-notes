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