#include<iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string str = "";
        bool b = false;
        
        for(char c : s){
            if (c == '+' || c == '-'){
                if (b || str.size() != 0){
                    break;
                }
                str += c;
                b = true;
            }

            else if (c == ' '){
                if (str.size() != 0){
                    break;
                }
                continue;
            }

            else if (isdigit(c)){
                str += c;
            }

            else{
                break;
            }
        }

        if (str == "+" || str == "-"){
            return 0;
        }

        try {
            if (!str.empty() && (isdigit(str[0]) || str[0] == '-' || str[0] == '+')) {
                return stoi(str);
            }
        } 
        catch (...) {
            return (str[0] == '-') ? INT_MIN : INT_MAX;
        }
        return 0;
    }
};