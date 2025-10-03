#include <iostream>
#include <string>
#include <vector>
#include <utility>      // for std::pair
#include <unordered_map> // for the Roman numeral map

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int prev_value = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            int current_value = roman_map.at(s[i]); 

            if (current_value < prev_value) {
                result -= current_value;
            } else {
                result += current_value;
            }
            
            prev_value = current_value;
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::string, int>> tests = {
        {"I", 1},
        {"III", 3},
        {"IV", 4},
        {"IX", 9},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
        {"DCCCLXXII", 872},
        {"MMMCMXCIX", 3999}
    };
    
    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        int output = sol.romanToInt(tests[i].first);
        bool isPass = (output == tests[i].second);
        std::cout << "Test " << (i + 1) << ": Input=\"" << tests[i].first
                  << "\", Output=" << output << ", Expected=" << tests[i].second
                  << " → " << (isPass ? "PASS" : "FAIL") << std::endl;
        if (isPass) ++passed;
    }
    
    std::cout << "\nSummary: " << passed << "/" << tests.size() << " tests passed." << std::endl;
    return 0;
}