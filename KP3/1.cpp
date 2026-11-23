#include <iostream>
#include <cmath>

int countDigits(long long n) {
    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        return 1;
    }
    return 1 + countDigits(n / 10);
}

int main() {
    long long number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    std::cout << "Количество цифр: " << countDigits(number) << std::endl;
    return 0;
}
