import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        // Optimization check
        if (s.length() % 2 != 0){
            return false;
        } 
        
        Map<Character, Character> map = new HashMap<>();
        map.put('(', ')');
        map.put('[', ']');
        map.put('{', '}');
        
        Stack<Character> stack = new Stack<>();
        
        for(char c : s.toCharArray()){
            if(map.containsKey(c)){
                stack.push(c);
            }
            else{
                if(stack.isEmpty()) {
                    return false;
                }
                char p = stack.peek();
                if(c == map.get(p)){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(!stack.isEmpty()){
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test Case 1: A standard valid string
        String test1 = "()[]{}";
        System.out.println("Input: " + test1 + " -> Is Valid? " + solution.isValid(test1));

        // Test Case 2: A mismatch (Invalid)
        String test2 = "(]";
        System.out.println("Input: " + test2 + " -> Is Valid? " + solution.isValid(test2));

        // Test Case 3: Nested brackets (Valid)
        String test3 = "([])";
        System.out.println("Input: " + test3 + " -> Is Valid? " + solution.isValid(test3));
        
        // Test Case 4: Only closing bracket (Invalid - tests your stack.isEmpty check)
        String test4 = "]";
        System.out.println("Input: " + test4 + " -> Is Valid? " + solution.isValid(test4));
    }
}