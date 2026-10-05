#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

// Разбирает "ax^2 + bx + c" и заполняет a, b, c.
// Понимает вольные форматы: "2x^2-3x+1", "x^2+5", "-x2", "4" и т.п.
bool readPolynomial(double& a, double& b, double& c) {
    std::string line;
    std::cout << "Введите многочлен (например, 2x^2 - 3x + 1): ";
    if (!std::getline(std::cin, line)) return false;

    a = b = c = 0.0;

    // Убираем пробелы, чтобы разбор был единообразным
    std::string s;
    for (char ch : line)
        if (!std::isspace(static_cast<unsigned char>(ch))) s += ch;

    if (s.empty()) return false;

    // Нормализуем ведущий '+' — так логика знаков ниже будет одинаковой
    if (s[0] != '+' && s[0] != '-') s = "+" + s;

    size_t i = 0;
    int termCount = 0;

    while (i < s.size()) {
        int sign = 1;
        if (s[i] == '+') { sign = 1;  i++; }
        else if (s[i] == '-') { sign = -1; i++; }
        else return false;

        // Числовая часть (может быть пустой -> коэффициент равен 1)
        std::string num;
        while (i < s.size() && (std::isdigit(static_cast<unsigned char>(s[i])) || s[i] == '.'))
            num += s[i++];

        double coeff = num.empty() ? 1.0 : std::stod(num);
        coeff *= sign;

        // Определяем степень
        int power;
        if (i < s.size() && (s[i] == 'x' || s[i] == 'X')) {
            i++;
            if (i < s.size() && s[i] == '^') {
                i++;
                std::string pw;
                while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) pw += s[i++];
                power = pw.empty() ? 1 : std::stoi(pw);
            } else if (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) {
                // Формат "2x2"
                std::string pw;
                while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) pw += s[i++];
                power = std::stoi(pw);
            } else {
                power = 1;
            }
        } else {
            power = 0;
        }

        if (power == 2)      a = coeff;
        else if (power == 1) b = coeff;
        else if (power == 0) c = coeff;
        else {
            std::cout << "Поддерживается только степень <= 2.\n";
            return false;
        }

        termCount++;
    }

    return termCount > 0;
}

void solvePolynomial(double a, double b, double c) {
    // Особый случай, явно требуемый заданием
    if (a == 0 && b == 0 && c == 0) {
        std::cout << "a = b = c = 0 -> x — любое действительное число.\n";
        return;
    }

    // Не квадратное: линейное или константа
    if (a == 0) {
        if (b == 0) {
            std::cout << "Корней нет (ненулевая константа).\n";
        } else {
            double x = -c / b;
            std::cout << "Линейное уравнение. Корень: x = " << x << "\n";
        }
        return;
    }

    // Настоящее квадратное
    double D = b * b - 4 * a * c;
    if (D < 0) {
        std::cout << "D = " << D << " < 0 -> действительных корней нет.\n";
    } else if (D == 0) {
        double x = -b / (2 * a);
        std::cout << "D = 0 -> один корень: x = " << x << "\n";
    } else {
        double x1 = (-b - std::sqrt(D)) / (2 * a);
        double x2 = (-b + std::sqrt(D)) / (2 * a);
        std::cout << "D = " << D << " -> два корня: x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
}

int main() {
    double a, b, c;
    if (!readPolynomial(a, b, c)) {
        std::cout << "Не удалось разобрать многочлен.\n";
        return 1;
    }

    std::cout << "Разобрано: a=" << a << " b=" << b << " c=" << c << "\n";

    char symbol;
    std::cout << "Введите управляющий символ (1/2/3): ";
    std::cin >> symbol;

    switch (symbol) {
        case '1':
            // TODO: впиши сюда своё настоящее имя
            std::cout << "Ivan Ivanov\n";
            break;

        case '2':
            solvePolynomial(a, b, c);
            break;

        case '3': {
            int n;
            std::cout << "Введите число: ";
            if (!(std::cin >> n)) {
                std::cout << "Это не число.\n";
                break;
            }
            if (n % 5 == 0)
                std::cout << n << " делится на 5.\n";
            else
                std::cout << n << " НЕ делится на 5.\n";
            break;
        }

        default:
            std::cout << "Неизвестный символ.\n";
            break;
    }

    return 0;
}