#include <vector>
#include <iostream>
#include <cassert>
#include <tuple>

using namespace std;

std::vector<int> daily_temperatures(std::vector<int> temperatures) {
    // initialize the stack, which is a vector of tuples, and the result
    // vector which is of type int
    std::vector<std::tuple<int, int>> stack = {};
    int len_temps = temperatures.size();
    std::vector<int> result(len_temps);

    // Iterate through input in reverse order - the for-loop gives each
    // index in decreasing order with the last iteration happening when i = 0
    for (int i = static_cast<int>(temperatures.size()) - 1; i >= 0; --i) {
        // if the stack is empty, put the current item on top of the stack
        // and set the corresponding result to 0
        if (stack.size() == 0) {
            stack.emplace_back(temperatures[i], i);
            result[i] = 0;
        // otherwise, compare the current item to the item on top (back) of 
        // the stack. if the temp on top of the stack is smaller, pop it
        // and continue popping items until you find a top of the stack that
        // has a higher temperature than the current item being considered
        } else {
            while (stack.size() > 0 && temperatures[i] >= std::get<0>(stack.back())) {
                stack.pop_back();
            }
            // store the result using the difference of the resulting top
            // of stack's index and the current item's index to count
            // the number of days in the future the next highest temp is
            if (stack.size() > 0) {
                result[i] = std::get<1>(stack.back()) - i;
            }
            // if the stack is empty, there are no future days with higher
            // temps, and the result vector takes a 0 in the corresponding space
            else {
                result[i] = 0;
            }
            // always push the current item to the stack - it will either be
            // popped or used as the "next warmest day" for an earlier day
            stack.emplace_back(temperatures[i], i);
        }
    }
    // after iteration is complete, return the result vector
    return result;
}

int main() {
    std::vector<int> test1 = {30, 38, 30, 36, 35, 40, 28};
    std::vector<int> t1_result = daily_temperatures(test1);
    std::vector<int> t1_expected = {1, 4, 1, 2, 1, 0, 0};
    if (t1_result == t1_expected) {
        cout << "Test 1 passed successfully!\n";
    } else {
        cout << "Test 1 failed\n";
    }

    std::vector<int> test2 = {22, 21, 20};
    std::vector<int> t2_result = daily_temperatures(test2);
    std::vector<int> t2_expected = {0, 0, 0};
    if (t2_result == t2_expected) {
        cout << "Test 2 passed successfully!\n";
    } else {
        cout << "Test 2 failed\n";
    }
}