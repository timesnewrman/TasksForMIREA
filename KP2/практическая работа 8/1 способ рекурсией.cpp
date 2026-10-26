#include <iostream>
using namespace std;

long long fastPow(long long base, long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        long long half = fastPow(base, exp / 2);
        return half * half;
    }
    return base * fastPow(base, exp - 1);
}

int main() {
    long long a, n;
    cin >> a >> n;
    cout << fastPow(a, n) << endl;
    return 0;
}