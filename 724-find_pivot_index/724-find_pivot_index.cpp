#include<vector>
#include<cmath>
#include<iostream>
using namespace std;


class Solution {
public:
    int pivotIndex(vector<int> nums) {
        int size = nums.size();
        int mid = size / 2;

        while(true)
        {
            if (mid >= size)    return -1;
            int leftsum = 0;
            int rightsum = 0;

            for(int i=0; i<mid; i++)
            {
                leftsum += nums[i];
            }

            for(int i=mid+1; i<size; i++)
            {
                rightsum += nums[i];
            }

            if (mid == 0 && rightsum != 0) return -1;
            if (mid == size - 1 && leftsum != 0) return -1;

            if (leftsum == rightsum)    return mid;
            else if (leftsum > rightsum)
            {
                mid = mid / 2;  // assign new mid to left
            }

            else if (leftsum < rightsum)
            {
                mid = mid + ((size) - mid) / 2;    // assing new mid to right
            }

        }

    }
};

int main()
{
    Solution s;
    cout << s.pivotIndex({-1,-1,-1,-1,-1,0});
}