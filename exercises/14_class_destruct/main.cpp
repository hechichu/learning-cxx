#include "../exercise.h"
#include <cassert>

// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>
// READ: RAII <https://learn.microsoft.com/zh-cn/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170>

class DynFibonacci {
    size_t *cache;
    int cached;
    int capacity;  // 新增容量变量

public:
    // 实现动态设置容量的构造器
    DynFibonacci(int init_capacity) 
        : cache(new size_t[init_capacity]), cached(0), capacity(init_capacity) {}

    // 实现析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        // 如果 i 超过当前容量，则扩展容量
        if (i >= capacity) {
            expandCache(i + 1);  // 确保有足够的空间
        }

        // 计算斐波那契数
        for (; cached <= i; ++cached) {
            if (cached <= 1) {
                cache[cached] = cached;
            } else {
                cache[cached] = cache[cached - 1] + cache[cached - 2];
            }
        }
        return cache[i];
    }

private:
    // 扩展缓存容量
    void expandCache(int new_capacity) {
        size_t *new_cache = new size_t[new_capacity];  // 分配新缓存
        for (int j = 0; j < capacity; ++j) {
            new_cache[j] = cache[j];  // 复制旧数据
        }
        delete[] cache;  // 释放旧缓存
        cache = new_cache;  // 更新指针
        capacity = new_capacity;  // 更新容量
    }
};

int main() {
    DynFibonacci fib(12);
    assert(fib.get(10) == 55);  // 确保计算正确
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    
    // 测试超出初始容量的情况
    std::cout << "fibonacci(20) = " << fib.get(20) << std::endl;  // 应该正确计算
    return 0;
}