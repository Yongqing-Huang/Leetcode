#include <iostream>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        short size = s.size();
        short l = 0;
        int add = 0;
        for (char c : s){
            if (c == '('){
                l++;
            } else {
                l--;
                if (l < 0){
                    add -= l;
                    l = 0;
                }
            }
        }
        if (l > 0){
            add += l;
        }
        return add;
    }
};