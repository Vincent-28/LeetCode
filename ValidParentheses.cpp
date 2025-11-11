#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        //first make sure the string isn't empty and that it doesn't begin with a closed bracket or end with an open bracket
        if(s.empty() || s[0] == '}' || s[0] == ')' || s[0] == ']' || s[s.size() - 1] == '{' || s[s.size() - 1] == '(' || s[s.size() - 1] == '[') { 
            return false;
        }
        //then make sure there is an equal number of open and closed brackets because that is the only way the string can be valid
        int count1 = 0;
        int count2 = 0;
        for(char c : s) {
            if(c == '{' || c == '(' || c == '[') {
                count1++;
            }
            else if(c == '}' || c == ')' || c == ']') {
                count2++;
            }
        }
        if(count1 != count2) {
            return false;
        }
        //we create our stack here
        std::stack<char> stack;
        for(char c : s) {
            if(c == '{' || c == '(' || c == '[') { //first check for an open bracket and push it to the stack everytime we find one
                stack.push(c);
            }
            //when we find a closed bracket, we want to make sure that there was the same type of open bracket on the stack and if there was, we pop it because they now check out. 
            //If the top of the stack bracket does not correspond to the current closed bracket, that would make the string invalid and we return false
            else if(c == '}') { 
                if(stack.top() == '{') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else if(c == ')') {
                if(stack.top() == '(') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
            else if(c == ']') {
                if(stack.top() == '[') {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(stack.empty()) { //if the stack is empty in the end, we know that all open and closed brackets pushed and popped out meaning this is a valid string and we return true
            return true;
        }
        else { //return false otherwise
            return false;
        }
    }
};

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    Solution solution;

    if (solution.isValid(s) == 1) {
        std::cout << "Your input is valid";
    }
    else {
        std::cout << "Your input is not valid";
    }
}