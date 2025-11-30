import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        int i = 0;
        for(int j = 1; j < len; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    public static void printArray(int[] nums, int k) {
        System.out.print("Count: " + k + " | Array: [");
        for (int i = 0; i < k; i++) {
            System.out.print(nums[i]);
            if (i < k - 1) System.out.print(", ");
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {1, 1, 2};
        int k1 = solution.removeDuplicates(nums1);
        System.out.print("Test Case 1: ");
        printArray(nums1, k1);

        int[] nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k2 = solution.removeDuplicates(nums2);
        System.out.print("Test Case 2: ");
        printArray(nums2, k2);

        int[] nums3 = {1, 2, 3}; 
        int k3 = solution.removeDuplicates(nums3);
        System.out.print("Test Case 3: ");
        printArray(nums3, k3);
    }
}