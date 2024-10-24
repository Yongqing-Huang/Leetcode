#include<iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        string str = "";
        int size = s.size();
        int step = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < size; j += step) {
                str += s[j];
                if (i != 0 && i != numRows - 1 && j + step - 2 * i < size) {
                    str += s[j + step - 2 * i];
                }
            }
        }

        return str;
    }
};