// Neetcode: longest_consecutive.cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>

using namespace std;

int valid_parentheses(std::string s) {
    // Create hash map to link closing characters to opening
    // Make sure to use single quotes ' to denote char, not string
    std::unordered_map<char, char> closure = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    // Create empty stack to store the chars from input s
    std::vector<char> stack = {};

    // For loop to iterate through s
    for (const auto& c : s) {
        // If the character is a closing character
        if (closure.contains(c)) {
            // If the stack is not empty and the last char is 
            // the correct match, pop from the end and continue
            if (!stack.empty() and stack.back() == closure[c]) {
                stack.pop_back();
            }
            // If the stack doesn't end with the correct character,
            // we can immediately return false
            else {
                return false;
            }
        }
        // If the character is an opening character, append it to the stack
        else {
            stack.push_back(c);
        }
    }
    // If we get all the way through the input and
    // we are not left with an empty stack, we have an
    // unmatched opener. An empty ending stack means the input was
    // valid, a non-empty ending stack means it is not
    return stack.empty();
}

int main() {
    std::string test1 = "[]";
    bool test1_result = valid_parentheses(test1);
    assert(test1_result == true && "Error: test 1 result should be true.");
    cout << "Test 1 passed successfully!\n";

    std::string test2 = "([{}])";
    bool test2_result = valid_parentheses(test2);
    assert(test2_result == true && "Error: test 2 result should be true.");
    cout << "Test 2 passed successfully!\n";

    std::string test3 = "[(])";
    bool test3_result = valid_parentheses(test3);
    assert(test3_result == false && "Error: test 3 result should be false.");
    cout << "Test 3 passed successfully!\n";
}