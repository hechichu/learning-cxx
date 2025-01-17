#include <iostream>
#include <cassert>

// 宏定义，用于简单断言
#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)

// 函数声明
int add(int a, int b);

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

// 函数定义
int add(int a, int b) {
    return a + b; // 补全函数定义
}

