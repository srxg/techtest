package Java.test;

import java.util.HashMap;
import java.util.Map;

public class Task {

    /**
     * Checks if the brackets in the input are balanced i.e. () is balanced, {(}) is not.
     * I'm not sure if I'm allowed to use a Map or not. Here's the method I would use
     * if I was not allowed to use a map.
     * @param input the string to check for balanced brackets
     * @return true if the brackets are balanced, false otherwise
     */
    public static boolean isBalanced(String input) {
        StackDLinkedList stack = new StackDLinkedList();

        for (char ch : input.toCharArray()) {            
            if (ch == '{' || ch == '[' || ch == '(') {
                // chars are just ints
                // this should work with my stack
                stack.push((int) ch);
            } else if (ch == '}' || ch == ']' || ch == ')') {
                if (stack.isEmpty()) {
                    return false;
                }

                char top = (char) ((int) stack.pop());

                if (ch == '}' && top != '{') {
                    return false;
                } else if (ch == ']' && top != '[') {
                    return false;
                } else if (ch == ')' && top != '(') {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }


    private static final Map<Character, Character> BRACKETS = new HashMap<Character, Character>() {{
        put('}', '{');
        put(']', '[');
        put(')', '(');
    }};
    /**
     * Checks if the brackets in the input are balanced i.e. () is balanced, {(}) is not.
     * I'm not sure if I'm allowed to use a Map or not. Here's the method I would use
     * if I was allowed to use a Map
     * @param input the string to check for balanced brackets
     * @return true if the brackets are balanced, false otherwise
     */
    public static boolean isBalancedWithMap(String input) {
        StackDLinkedList stack = new StackDLinkedList();

        for (char ch : input.toCharArray()) {
            if(BRACKETS.containsKey(ch)) {
                if(stack.isEmpty() || stack.pop() != (int) BRACKETS.get(ch)) {
                    return false;
                }
            } else {
                stack.push((int) ch);
            }
        }
        return stack.isEmpty();
    }


}
