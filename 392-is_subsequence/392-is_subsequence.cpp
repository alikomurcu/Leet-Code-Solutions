#include<vector>
#include<cmath>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int iter = 0;
        for(int i=0; i<t.size() && iter<s.size(); i++)
        {
            if(s[iter] == t[i])
            {
                iter++;
            }
        }
        if(iter == s.size()) return true;
        return false;
    }
};