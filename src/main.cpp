//  Copyright 2021 Dmitry Vargin
#include <iostream>
#include <string>

#include "postfix.h"
#include "MyStack.h"

int main() {
    std::cout << infix2postfix("2 + 2") << std::endl;
    std::cout << infix2postfix("2 + 6 * 3 / (4 - 2)") << std::endl;
    std::cout << infix2postfix("(2 + 8.3) * (6 - 3.2)") << std::endl;
    std::cout << infix2postfix("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9") << std::endl;
    return 0;
}
