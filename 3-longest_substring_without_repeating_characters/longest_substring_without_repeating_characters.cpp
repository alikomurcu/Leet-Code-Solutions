/*
Given a string s, find the length of the longest substring without repeating characters.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool includes(vector<char> &sL, char key)
    {
        for (vector<char>::iterator it=sL.begin(); it != sL.end(); ++it)
        {
            if(*it == key) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) 
    {
        int max_len = 0;
        vector<char> cL;
        int i = 0;    
        while(true)
        {
            if(s[i] == '\0') return max_len;
            if(includes(cL, s[i]))
            {
                int j = i;
                char cur = s[i];
                while(true)
                {
                    j--;
                    if(s[j] == cur)
                    {
                        i = j;
                        i++;
                        break;
                    }
                    if(j == 0) break;
                }
                if(cL.size() > max_len) max_len = cL.size();
                cL.clear();
                continue;
            }
            cL.push_back(s[i++]);
            if(cL.size() > max_len) max_len = cL.size();
        }        
        return max_len;
    }
};