#include <iostream>
using namespace std;

long long fastPow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int main() {
    long long a, n;
    cin >> a >> n;
    cout << fastPow(a, n) << endl;
    return 0;
}