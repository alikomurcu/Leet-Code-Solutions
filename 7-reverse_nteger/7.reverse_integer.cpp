#include<stack>

using namespace std;

class Solution {
public:
    stack<int> S;
    int reverse(int x) 
    {
        long y = 0, coef = 1;
        while(x)
        {
            S.push(x % 10);
            x /= 10;
        }

        while(!S.empty())
        {
            y += S.top()*coef;
            S.pop();
            coef *= 10;
        }
        
        if(y > INT_MAX || y < INT_MIN) return 0;
        return y;
    }
};