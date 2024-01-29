#include <iostream>
#include <iomanip>

bool myFunction() {
    // Your function logic here
    return true; // or false
}

int main() {
    bool result = myFunction();

    // Print the literal words "true" or "false"
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}