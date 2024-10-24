#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int num = 0;

        while (x != 0){
            int lastDigit = x % 10;
            x /= 10;

            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && lastDigit > 7)) return 0;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && lastDigit < -8)) return 0;
            num = num * 10 + lastDigit;
        }


        return num;
    }
};