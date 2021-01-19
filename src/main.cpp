//  Copyright 2021 Dmitry Vargin
#include <iostream>
#include <string>

#include "postfix.h"
#include "MyStack.h"

int main() {
    std::string s1 = "2 + 6 * 3 / (4 - 2)";
    std::string s2 = infix2postfix("(2 + 8.3) * (6 - 3.2)");
    std::cout << "input: " << s1 << std::endl;
    std::cout << "output: " << s2 << "\n\n";
    s1 = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
    s2 = infix2postfix("6 4 2 - * 5 + 2.6 3 7 * + * 9 -");
    std::cout << "input: " << s1 << std::endl;
    std::cout << "output: " << s2 << "\n\n";
    return 0;
}
