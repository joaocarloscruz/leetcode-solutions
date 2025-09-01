#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        std::string result = "";
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += cycleLen) {
                result += s[j];

                if (i > 0 && i < numRows - 1) {
                    int secondCharIndex = j + cycleLen - 2 * i;
                    if (secondCharIndex < s.length()) {
                        result += s[secondCharIndex];
                    }
                }
            }
        }

        return result;
    }
};

void run_test(const std::string& input, int numRows, const std::string& expected) {
    Solution sol;
    std::string output = sol.convert(input, numRows);
    std::cout << "Input: \"" << input << "\", numRows: " << numRows << std::endl;
    std::cout << "Output: \"" << output << "\"" << std::endl;
    std::cout << "Expected: \"" << expected << "\"" << std::endl;

    if (output == expected) {
        std::cout << "Result: PASSED" << std::endl;
    } else {
        std::cout << "Result: FAILED" << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;
}

int main() {
    run_test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");

    run_test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    
    run_test("A", 1, "A");

    run_test("ABC", 1, "ABC");

    return 0;
}
