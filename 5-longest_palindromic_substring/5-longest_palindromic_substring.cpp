#include <cmath>
#include <iostream>
#include <string>

// This is an iterative way to solve this problem with a complexity O(n^2).

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";

        if(s.size() < 2) return s;
        if(s.size() == 2)
        {
            if(s[0] == s[1]) return s;
            return string (1,s[0]);
        }

        for(int i=0; i<s.size(); i++)  // iterate over each element
        {
            int left = i, right = i;  // start from s[i-1] and s[i+1] in first while loop cycle
            while (left > 0 && right < s.size() - 1)  // loop 1 -> finds aabaa (odd length palindromes)
            {
                if(s[left-1] == s[right+1])  // check if the left and the right of s[i] are equal or not
                {
                    left--; right++;
                    if (right-left+1 > result.size())
                    {
                        result = s.substr(left, right-left+1);
                    }
                    continue;
                }
                break;  // break the while when left and rigth are not equal
            }

            left = i; right = i + 1;  // choose s[i] and s[i+1]
            while (left >= 0 && right < s.size())  // loop 2 -> finds aabbaa (even length palindromes)
            {
                if(s[left] == s[right])  // check if they are equal or not
                {
                    if(right-left+1 > result.size())
                    {
                        result = s.substr(left, right-left+1);
                    }
                    left--; right++;
                    continue;
                }
                break;  // break the while whenever they are no more equal
            }
        }
        if(!result.size()) result = s[0];  // if result = "", then return the first element
        return result;
    }
};

main()
{
    Solution S;
    string myS = S.longestPalindrome("aac");
    cout << myS;
}