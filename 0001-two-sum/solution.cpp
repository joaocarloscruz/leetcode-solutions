#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        int length = nums.size();
        for(int i = 0; i < length; i++){
            int missing_value = target - nums[i];
            if(map.count(missing_value)){
                return {map[missing_value], i};
            }
            map[nums[i]] = i; 
        }
        return {};
    }
};

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution s;

    std::vector<int> result = s.twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}