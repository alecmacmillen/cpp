// Neetcode: longest_consecutive.cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

int longest_consecutive(vector<int>& nums) {
    // Create tracker variable and convert input vector to set
    int longest_seq = 0;
    std::unordered_set<int> numset(nums.begin(), nums.end());

    // for loop: syntax iterates through objects in vector, not indices
    for (const auto& item : numset) {
        // Skip to next iteration if prev value is in the set; can't
        // be the start of a sequence
        if (numset.contains(item - 1)) {
            continue;
        }

        // Increment sequence length variable for each sequential
        // value that is still in the unordered set
        int val = item;
        int seq_length = 0;
        while (numset.contains(val)) {
            val++;
            seq_length++;
        }

        // Update longest sequence length if current sequence is longer
        if (seq_length > longest_seq) {
            longest_seq = seq_length;
        }
    }
    return longest_seq;
}

int main() {
    vector<int> test1 = {2,20,4,10,3,4,5};
    int test1_result = longest_consecutive(test1);
    assert(test1_result == 4 && "Error: test 1 result should be 4.");
    cout << "Test 1 passed successfully!";

    vector<int> test2 = {0,3,2,5,4,6,1,1};
    int test2_result = longest_consecutive(test2);
    assert(test2_result == 7 && "Error: test 2 result should be 7.");
    cout << "Test 2 passed successfully!";
}