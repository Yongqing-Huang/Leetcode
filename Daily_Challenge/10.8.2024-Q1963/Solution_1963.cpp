#include <iostream>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int max_imbalance = 0;

        for (char c : s){
            balance += (c=='[')? 1 : -1;
            if (balance < 0)
                max_imbalance = (max_imbalance > - balance)? max_imbalance : -balance;
        }
        return (max_imbalance + 1) / 2;
    }
};