#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> nums{1, 2, 3, 4, 5};

    for (auto n : nums | std::views::filter([](int x){
        return x % 2 == 0;
    })) {
        std::cout << n << '\n';
    }
}