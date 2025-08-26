#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) {
            return 0;
        }
        std::unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    
    std::string test_string = "abcabcbb";
    
    int result = solution.lengthOfLongestSubstring(test_string);
    
    std::cout << "The length of the longest substring for '" << test_string << "' is: " << result << std::endl;
    
    return 0;
}