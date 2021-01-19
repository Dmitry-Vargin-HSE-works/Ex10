// Copyright 2020 A.SHT
#ifndef INCLUDE_POSTFIX_H_
#define INCLUDE_POSTFIX_H_
#include <string>

std::string infix2postfix(std::string infix);
bool isNumber(char c);
int priority(char op);

#endif  // INCLUDE_POSTFIX_H_
