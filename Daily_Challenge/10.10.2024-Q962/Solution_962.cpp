#include <vector> 
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size = nums.size();
        vector<int> temp;
        int max_width = 0;

        for (int i = 0; i < size; ++i) {
            if (temp.empty() || nums[i] < nums[temp.back()]) {
                temp.push_back(i);
            }
        }

        for (int j = size-1; j >= 0; --j) {
            if (nums[j] == 0){
                if (size - j - 1 > max_width){
                    return size - j - 1;
                }
                max_width = max(max_width, size - j - 1);
            }
            while (!temp.empty() && nums[j] >= nums[temp.back()]) {
                max_width = max(max_width, j - temp.back());
                temp.pop_back();
            }
        }

        return max_width;
    }
};