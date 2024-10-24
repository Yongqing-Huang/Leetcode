#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    /* Solution 1
    string longestPalindrome(string s) {
        int size = s.size();
        int max_len = 0;
        int start = 0, end = 0;
        int len_even, len_odd;
        int len_even_b, len_odd_b;

        if (size == 1 || size == 0){
            return s;
        }

        for (int i = 0; i < size; i++){
            len_even = checkPalindromic(s, size, i , i+1);
            len_odd = checkPalindromic(s, size, i , i);
            max_len = max(len_even, len_odd);

            if (max_len > (end - start)){
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int checkPalindromic (string s, int size, int l, int r){
        while (l >= 0 && r < size && s[l] == s[r]){
            l--;
            r++;
        }
        return r - l - 1;
    }
    */ 
   
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) return s;

        string T = preprocess(s);
        int n = T.size();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        int max_len = 0;
        int center_index = 0;
        int i_mirror;

        for (int i = 1; i < n - 1; ++i){
            i_mirror = 2 * C - i;

            if (i < R) {
                P[i] = min(R - i, P[i_mirror]);
            }

            while (T[i + P[i] + 1] == T[i - P[i] - 1]){
                P[i]++;
            }

            if (i + P[i] > R){
                C = i;
                R = i + P[i];
            }

            if (P[i] > max_len){
                max_len = P[i];
                center_index = i;
            }
        }

        return s.substr((center_index - max_len) / 2, max_len); 
    }

    string preprocess(const string &s) {
        string transformed = "^";
        for (char c : s) {
            transformed += "#" + string(1, c);
        }
        transformed += "#$";
        return transformed;
    }
};