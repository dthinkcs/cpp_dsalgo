/*
Minimum bracket Reversal
Send Feedback
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1
*/

import java.util.Stack; public class Solution { // Function returns -1 if brackets can't be balanced public static int countBracketReversals(String input){ if(input.length() == 0){ return 0; } if(input.length() % 2 != 0){ return -1; // reversal isn't possible } Stack<Character> stack = new Stack<>(); for(int i = 0; i < input.length(); i++){ char currentChar = input.charAt(i); if(currentChar == '{'){ stack.push(currentChar); }else{ // pop if there is a balanced pair if(!stack.isEmpty() && stack.peek() == '{'){ stack.pop(); }else{ stack.push(currentChar); } } } int count = 0; // only unbalanced brackets are there in stack now while(!stack.isEmpty()){ char char1 = stack.pop(); char char2 = stack.pop(); // i.e char1 = } and char2 = { then we need to reverse both of them if(char1 != char2){ count += 2; } // if both char1 and char2 are same i.e either the are {{ or }}, then we need only 1 reversal else{ count += 1; } } return count; } }
