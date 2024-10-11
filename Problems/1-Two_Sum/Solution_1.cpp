#include "vector"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        short size = nums.size();
        short dest = (size+1)/2;
        for (short i = 0; i < dest; i++){
            for (short j = i+1; j < size; j++){
                if (nums[i]+nums[j] == target){
                    return vector<int>{i,j};
                } else if (nums[size-1-i] + nums[size-1-j] == target){
                    return vector<int>{size-1-i, size-1-j};
                }
            }
        }
        return {};
    }
};