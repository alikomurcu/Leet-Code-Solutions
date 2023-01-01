#include<vector>
#include<cmath>
#include<iostream>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int> nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            int left = 0, right = 0;
            for (int j = 0; j < i; j++)
            {
                left += nums[j];
            }
            for (int k = i + 1; k < size; k++)
            {
                right += nums[k];
            }
            if (left == right) return i;
        }
    }
};

int main()
{
    Solution s;
    cout << s.pivotIndex({-1,-1,-1,-1,-1,0});
}