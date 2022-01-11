/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    stack<char> S;
    short neg = 0; // is negative?
    short pos = 0;
    long num = 0;
    long coef = 1;
    bool f = true;

    int myAtoi(string s) {

        while(s[0] == ' ') s.erase(0, 1);
        while(s[0] == '0')
        {
            s.erase(0, 1);
            f = false;
        }
        while((s[0] == '-' || s[0] == '+') && f)
        {
            if(s[0] == '-') neg += 1;
            if(s[0] == '+') pos += 1;
            s.erase(0, 1);
        }
        while(s[0] == '0') s.erase(0, 1);
        if(neg > 1 || pos > 1) return 0;

        cout << "Your string: " << s << endl;
        while(s[0] >= '0' && s[0] <= '9')
        {
            S.push(s[0]);  // collect digits in reverse order
            s.erase(0, 1);
        }
        if(S.size() > 10) 
        {
            if(neg && !pos) num *= -1;
            if (!neg) return INT_MAX;
            if (neg && !pos) return INT_MIN;
            //if(neg && pos) num = 0;
            return num;
        } 
        while(!S.empty())
        {
            num += (long)(S.top() - '0')*coef;
            if (num >= INT_MAX) break;
            if (num <= INT_MIN) break;
            if (coef >= INT_MAX) break;
            S.pop();
            coef *= 10;
        }
        
        if(neg && !pos) num *= -1;
        if (num >= INT_MAX) num = INT_MAX;
        if (num <= INT_MIN) num = INT_MIN;
        if(neg && pos) num = 0;
        
        cout << "Your number: " << num;


        return num;
    }
};
int main()
{
    Solution S;
    S.myAtoi("20000000000000000000");
}