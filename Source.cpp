#include <iostream>
#include <string>

// Template function to find the maximum of two values
template <typename T>
T findMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    // Test case 1: Two integers
    int int1 = 3, int2 = 5;
    std::cout << "Max of " << int1 << " and " << int2 << " is " << findMax(int1, int2) << std::endl;

    // Test case 2: Two floating-point numbers
    float float1 = 3.14f, float2 = 2.71f;
    std::cout << "Max of " << float1 << " and " << float2 << " is " << findMax(float1, float2) << std::endl;

    // Test case 3: Two strings
    std::string str1 = "apple", str2 = "banana";
    std::cout << "Max of " << str1 << " and " << str2 << " is " << findMax(str1, str2) << std::endl;

    return 0;
}