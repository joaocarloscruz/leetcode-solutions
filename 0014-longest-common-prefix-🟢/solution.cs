using System;

public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0) {
            return "";
        }

        string result = "";

        for (int i = 0; i < strs[0].Length; i++) {
            char charToCompare = strs[0][i];
            for (int j = 1; j < strs.Length; j++) {
                
                if (i >= strs[j].Length || strs[j][i] != charToCompare) {
                    return result;
                }
            }
            result += charToCompare;
        }

        return result;
    }
}

public static class Program {
    // Return code: 0 = all tests passed, non-zero = failures
    static int Main(string[] args) {
        var tests = new (string[] input, string expected)[] {
            (new string[] {"flower","flow","flight"}, "fl"),
            (new string[] {"dog","racecar","car"}, ""),
            (new string[] {"interspace","interstellar","internet"}, "inter"),
            (new string[] {"a"}, "a"),
            (new string[] {}, "")
        };

        int failures = 0;
        var sol = new Solution();

        for (int i = 0; i < tests.Length; i++) {
            var t = tests[i];
            string got = sol.LongestCommonPrefix(t.input);
            bool ok = string.Equals(got, t.expected, StringComparison.Ordinal);
            string inputRepr = t.input == null ? "null" : (t.input.Length == 0 ? "[]" : "[" + string.Join(",", t.input) + "]");
            Console.WriteLine($"Test {i+1}: input={inputRepr} expected='{t.expected}' got='{got}' => {(ok?"PASS":"FAIL")}");
            if (!ok) failures++;
        }

        if (failures == 0) {
            Console.WriteLine("All tests passed.");
        } else {
            Console.WriteLine($"{failures} test(s) failed.");
        }

        return failures == 0 ? 0 : 1;
    }
}