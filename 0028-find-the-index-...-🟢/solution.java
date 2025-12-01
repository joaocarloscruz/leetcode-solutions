class Solution {
    public int strStr(String haystack, String needle) {
        int j = 0;
        int len = haystack.length();
        
        for(int i = 0; i < len; i++){
            if(haystack.charAt(i) == needle.charAt(j)){
                j++;
            } else {

                i -= j; 
                j = 0;
            }
            if(j == needle.length()){
                return i + 1 - j;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test Case 1: Standard match
        String h1 = "sadbutsad";
        String n1 = "sad";
        System.out.println("Input: " + h1 + ", " + n1 + " | Output: " + solution.strStr(h1, n1)); // Expected: 0

        // Test Case 2: No match
        String h2 = "leetcode";
        String n2 = "leeto";
        System.out.println("Input: " + h2 + ", " + n2 + " | Output: " + solution.strStr(h2, n2)); // Expected: -1

        // Test Case 3: Partial match backtrack (The "mississippi" case)
        String h3 = "mississippi";
        String n3 = "issip";
        System.out.println("Input: " + h3 + ", " + n3 + " | Output: " + solution.strStr(h3, n3)); // Expected: 4

        // Test Case 4: Match at the very end
        String h4 = "hello";
        String n4 = "ll";
        System.out.println("Input: " + h4 + ", " + n4 + " | Output: " + solution.strStr(h4, n4)); // Expected: 2
    }
}