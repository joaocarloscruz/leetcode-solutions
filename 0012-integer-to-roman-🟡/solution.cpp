#include <iostream>
#include <vector>
#include <string>
#include <utility>  // for std::pair

class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<std::pair<int, std::string>> valToSym = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        std::string result = "";
        for (const auto& p : valToSym) {
            int value = p.first;
            std::string symbol = p.second;
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, std::string>> tests = {
        {1, "I"},
        {3, "III"},
        {4, "IV"},
        {58, "LVIII"},
        {1994, "MCMXCIV"}
    };
    
    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        std::string output = sol.intToRoman(tests[i].first);
        bool isPass = (output == tests[i].second);
        std::cout << "Test " << (i + 1) << ": Input=" << tests[i].first
                  << ", Output=\"" << output << "\", Expected=\"" << tests[i].second
                  << "\" → " << (isPass ? "PASS" : "FAIL") << std::endl;
        if (isPass) ++passed;
    }
    
    std::cout << "\nSummary: " << passed << "/" << tests.size() << " tests passed." << std::endl;
    return 0;
}