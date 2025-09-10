#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        long original = x;
        long reverse = 0;
        
        while (x > 0) {
            int last_digit = x % 10;
            reverse = (reverse * 10) + last_digit;
            x /= 10;
        }
        
        return original == reverse;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: A simple palindrome
    int num1 = 121;
    std::cout << "Is " << num1 << " a palindrome? " << (solution.isPalindrome(num1) ? "true" : "false") << std::endl;
    
    // Test case 2: A non-palindrome
    int num2 = 123;
    std::cout << "Is " << num2 << " a palindrome? " << (solution.isPalindrome(num2) ? "true" : "false") << std::endl;
    
    // Test case 3: A negative number
    int num3 = -121;
    std::cout << "Is " << num3 << " a palindrome? " << (solution.isPalindrome(num3) ? "true" : "false") << std::endl;
    
    // Test case 4: A number with a zero at the end (not a palindrome)
    int num4 = 10;
    std::cout << "Is " << num4 << " a palindrome? " << (solution.isPalindrome(num4) ? "true" : "false") << std::endl;
    
    // Test case 5: A number that causes integer overflow in a 32-bit int
    int num5 = 1234567899;
    std::cout << "Is " << num5 << " a palindrome? " << (solution.isPalindrome(num5) ? "true" : "false") << std::endl;
    
    return 0;
}
