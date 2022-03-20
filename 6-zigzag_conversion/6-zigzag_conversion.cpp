#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) 
    {
        // initialize container
        vector<char> V[numRows];  // here, create an array of vectors that holds:
        /* V [
                row1 = {.,.,...}
                row2 = {.,.,...}
                .
                .
                .
             ]
        */
        int j = 0, i = 0;
        if(numRows == 1) return s;  // if there is only one row, then return the given string
        while(1)
        {
            // i -> iterates over string s
            // j -> iterates back and forth in either column
            if(i >= s.size()) break; // if the iterator i exceeds the size of the string, then break

            for(;j < numRows && s[i]; j++)
                V[j].push_back(s[i++]); // go end of column and store values
            j--; j--;
            while(j && i < s.size() && s[i])
            {
                V[j--].push_back(s[i++]);  // move back through top of the column
            }

            if(!j) continue;  // if j=0, namely, j can not go back to the top, i.e.,the iteration of the string is over
        }
        string res = "";
        for(int a=0; a<numRows; a++)
        {
             
            for(int k=0; k<V[a].size(); k++)
            {
                res += V[a][k];  // store the value
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.convert("PAYPALISHIRING", 3);
    return 0;
}