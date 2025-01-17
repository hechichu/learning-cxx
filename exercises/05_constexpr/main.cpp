#include <array>
#include <iostream>

constexpr unsigned long long fibonacci(int i){
    constexpr std::array<unsigned long long, 91> fibs = []{
        constexpr std::array<unsigned long long, 91> arr {};
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= 90; i++){
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr;
        
    }();

    return fibs[i];

}
int main (){
    constexpr auto FIB20 = fibonacci(20);
    std::out << "fibonacci(20) = " << FIB20 << std::endl;

    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::out << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0
}
