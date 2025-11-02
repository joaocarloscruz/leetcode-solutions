/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort((a,b)=> a - b);
    const results = [];

    // This is the loop condition we were testing
    for(let i = 0; i < nums.length - 3; i++){ 
        if (i === 0 || nums[i] !== nums[i-1]) {
            let j = i + 1;
            let k = nums.length - 1;
            while(j < k){
                if (nums[j] + nums[k] === -nums[i]) {
                    results.push([nums[i], nums[j], nums[k]]);

                    // remove duplicates
                    while (j < k && nums[j] === nums[j + 1]) {
                        j++;
                    }
                    
                    while (j < k && nums[k] === nums[k - 1]) {
                        k--;
                    }

                    // we change the value of both j and k since if there are no more duplicates
                    j++;
                    k--;                  
                } else if (nums[j] + nums[k] < -nums[i]) {
                    // value too small, increment j
                    j++;
                    
                } else {
                    // value too big, decrement k
                    k--;
                }
            }
        }
    }
    return results;
};

// --- Main Function & Test Cases ---

function main() {
    console.log("Running 3Sum Tests...\n");

    const tests = [
        { 
            id: 1, 
            input: [0, 0, 0], 
            expected: "[[0,0,0]]" 
        },
        { 
            id: 2, 
            input: [-1, 0, 1, 2, -1, -4], 
            // The function sorts the input, so the result will be consistent
            expected: "[[-1,-1,2],[-1,0,1]]" 
        },
        { 
            id: 3, 
            input: [1, 2, 3], 
            expected: "[]" 
        },
        {
            id: 4,
            input: [],
            expected: "[]"
        }
    ];

    tests.forEach(test => {
        console.log(`--- Test ${test.id} ---`);
        console.log(`Input: [${test.input}]`);
        
        // We create a copy so the original test input isn't modified by the sort
        const inputCopy = [...test.input]; 
        const actual = threeSum(inputCopy);
        
        // Use JSON.stringify for a simple way to compare array contents
        const actualStr = JSON.stringify(actual); 
        
        console.log(`Expected: ${test.expected}`);
        console.log(`Actual:   ${actualStr}`);
        
        if (actualStr === test.expected) {
            console.log("Result: PASS ✅");
        } else {
            console.log("Result: FAIL ❌");
        }
        console.log(""); // Newline for spacing
    });
}

// Run the main function
main();