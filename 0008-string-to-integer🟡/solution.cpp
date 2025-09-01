#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        bool isNegative = false;
        int index = 0;
        while (index < s.length() && s[index] == ' ') {
            index++;
        }
        if (index < s.length() && s[index] == '-') {
            isNegative = true;
            index++;
        } else if (index < s.length() && s[index] == '+') {
            index++;
        }

        int result = 0;
        while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
            int digit = s[index] - '0';
            
            if (!isNegative && (result > 214748364 || (result == 214748364 && digit > 6))) {
                return 2147483647;
            }
            
            if (isNegative && (result > 214748364 || (result == 214748364 && digit > 7))) {
                return -2147483648;
            }

            result = result * 10 + digit;
            index++;
        }

        return isNegative ? result * -1 : result;
        
    }
};

int main() {
    Solution sol;
    
    // Test cases to check the functionality
    std::cout << "--- Testing various inputs ---" << std::endl;
    std::cout << "Input: \"42\" -> Output: " << sol.myAtoi("42") << std::endl;
    std::cout << "Input: \"   -042\" -> Output: " << sol.myAtoi("   -042") << std::endl;
    std::cout << "Input: \"1337c0d3\" -> Output: " << sol.myAtoi("1337c0d3") << std::endl;
    std::cout << "Input: \"0-1\" -> Output: " << sol.myAtoi("0-1") << std::endl;
    std::cout << "Input: \"words and 987\" -> Output: " << sol.myAtoi("words and 987") << std::endl;
    
    // This test case will likely cause a runtime error due to integer overflow
    std::cout << "\n--- Testing for Overflow (Expected Error) ---" << std::endl;
    std::cout << "Input: \"2147483648\" -> Output: " << sol.myAtoi("2147483648") << std::endl;

    return 0;
}
