#include<stack>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) return false;
        if(x < 10) return true;
        long n = x, r = 0;
        while(n)
        {
            r += n % 10;
            n /= 10;
            if(n) r *= 10;
        }
        cout << r << endl;
        if(r == x) return true;
        return false;
    }
};

main()
{
    Solution s;
    cout << s.isPalindrome(1234567899);

}