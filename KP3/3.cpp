#include <iostream>
#include <string>

int main() {
    std::string line;

    std::cout << "Введите строку: ";
    std::getline(std::cin, line);  

    std::cout << "Длина строки: " << line.length() << std::endl;

    return 0;
}
