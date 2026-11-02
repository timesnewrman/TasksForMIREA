#include <fstream>
#include <string>
using namespace std;

string toBinary(long long n) {
    if (n == 0) return "0";
    string r;
    while (n > 0) { r = char('0' + n % 2) + r; n /= 2; }
    return r;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string s;
    getline(in, s);

    string result;
    for (size_t i = 0; i < s.size(); ) {
        if (isdigit((unsigned char)s[i])) {
            long long num = 0;
            while (i < s.size() && isdigit((unsigned char)s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            result += toBinary(num);
        } else {
            result += s[i];
            i++;
        }
    }
    out << result;
    return 0;
}