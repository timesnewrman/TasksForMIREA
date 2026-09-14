#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    // swap
    int a, b;
    std::cin >> a >> b;

    a -= b;
    b += a;
    a = b - a;

    std::cout << a << '\n' << b;

    return 0;
}
