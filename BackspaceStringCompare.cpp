#include <iostream>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        std::stack<char> strS; //create two stacks for s and t
        std::stack<char> strT; 
        for(int c : s) { //loop through each element in s
            if(c != '#') { //when we see a character (not a backspace (#)), we push that character onto the stack
                strS.push(c);
            }
            else if(c == '#') { //when we see a backspace (#), we first make sure the string isn't empty because if we backspace on an empty stack, we do nothing.
                if(!strS.empty()) { 
                    strS.pop(); //we then pop the character if we see one
                }
            }
        }
        for(int c : t) { //loop through each element in t
            if(c != '#') { //when we see a character (not a backspace (#)), we push that character onto the stack
                strT.push(c);
            }
            else if(c == '#') { //when we see a backspace (#), we first make sure the string isn't empty because if we backspace on an empty stack, we do nothing.
                if(!strT.empty()) {
                    strT.pop(); //we then pop the character if we see one
                }
            }
        }
        if(strS.size() != strT.size()) { //check that the sizes of the stacks are the same using .size(). If they aren't we return false cause then they would not be the same.
            return false;
        }
        if(strS.empty()) { //if strS, strT will also be empty since we already checked for the sizes and that would mean they are the same 
            return true;
        }
        while(!strS.empty() && !strT.empty()) { //if they are not both empty but also have the same size, we want to make sure they have the same characters
            if(strS.top() != strT.top()) { //make sure the top element is the same and then keeping popping through the entire stack
                return false;
            }
            strS.pop();
            strT.pop();
        }
        return true;
    }
};

int main() {
    std::string s;
    std::string t;

    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    std::cout << "Enter another string: ";
    std::getline(std::cin, t);

    Solution solution;

    if(solution.backspaceCompare(s, t) == 1) {
        std::cout << "The result is the same!" << std::endl;
    }
    else {
        std::cout << "The result is not the same." << std::endl;
    }
}

