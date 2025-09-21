class Solution {
    intToRoman(num) {
        const valToSym = new Map([
            [1000, "M"],
            [900, "CM"],
            [500, "D"],
            [400, "CD"],
            [100, "C"],
            [90, "XC"],
            [50, "L"],
            [40, "XL"],
            [10, "X"],
            [9, "IX"],
            [5, "V"],
            [4, "IV"],
            [1, "I"]
        ]);
        
        let result = "";
        for (let [value, symbol] of valToSym) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
}

// Test suite
function runTests() {
    const sol = new Solution();
    const tests = [
        { input: 1, expected: "I" },
        { input: 3, expected: "III" },
        { input: 4, expected: "IV" },
        { input: 58, expected: "LVIII" },
        { input: 1994, expected: "MCMXCIV" }
    ];
    
    let passed = 0;
    tests.forEach((test, index) => {
        const output = sol.intToRoman(test.input);
        const isPass = output === test.expected;
        console.log(`Test ${index + 1}: Input=${test.input}, Output="${output}", Expected="${test.expected}" → ${isPass ? "PASS" : "FAIL"}`);
        if (isPass) passed++;
    });
    
    console.log(`\nSummary: ${passed}/${tests.length} tests passed.`);
}

runTests();