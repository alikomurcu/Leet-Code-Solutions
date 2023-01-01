#include<string>
#include<iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // create a map from s to t
        unordered_map<char, char> map;

        int szS = s.size();
        int szT = t.size();
        string t2 = s;
        if (szS != szT) return false;
        for(int i = 0; i < szS; i++)
        {
            const char c = s[i];
            const char d = t[i];
            if (map.find(d) != map.end())
            {
                if (map[d] != t2[i]) return false;
            }
            else
            {
                map[d] = c;
            }
            std::replace(s.begin(), s.end(), c, d);
        }
        if (s.compare(t) == 0) return true;
        else return false;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("egg", "add");
}