#include <iostream>
#include <fstream>
#include <string>

int main() {
    const std::string inputFile  = "input.txt";
    const std::string outputFile = "output.txt";

    std::ifstream fin(inputFile);
    if (!fin.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << inputFile << std::endl;
        return 1;
    }

    long long sum = 0;  
    long long count = 0; 
    int value;

    while (fin >> value) {
        sum += value;
        ++count;
    }

    fin.close();

    if (count == 0) {
        std::cerr << "Файл не содержит чисел." << std::endl;
        return 1;
    }

    
    double average = static_cast<double>(sum) / count;

    // Записываем результат в новый файл
    std::ofstream fout(outputFile);
    if (!fout.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл " << outputFile << std::endl;
        return 1;
    }

    fout << "Количество чисел: " << count << "\n";
    fout << "Сумма: " << sum << "\n";
    fout << "Среднее арифметическое: " << average << "\n";S
    fout.close();

    std::cout << "Готово. Результат записан в " << outputFile << std::endl;
    std::cout << "Среднее арифметическое = " << average << std::endl;

    return 0;
}
